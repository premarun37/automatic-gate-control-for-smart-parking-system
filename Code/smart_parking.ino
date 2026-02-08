#include <Servo.h>

/* ---------------- PIN DEFINITIONS ---------------- */

#define TRIG_ENTRY   8
#define ECHO_ENTRY   6

#define TRIG_SLOT1   4
#define ECHO_SLOT1   3

#define TRIG_SLOT2   2
#define ECHO_SLOT2   10

/* ---------------- SERVO ---------------- */

Servo entryGate;

/* ---------------- SLOT & HEAP VARIABLES ---------------- */

const int MAX_SLOTS = 2;

int minHeap[MAX_SLOTS];
int heapSize = 0;

const int slotTrig[MAX_SLOTS] = { TRIG_SLOT1, TRIG_SLOT2 };
const int slotEcho[MAX_SLOTS] = { ECHO_SLOT1, ECHO_SLOT2 };

bool slotOccupied[MAX_SLOTS] = { false, false };

/* ---------------- QUEUE VARIABLES ---------------- */

const int MAX_QUEUE = 5;

int carQueue[MAX_QUEUE];
int front = 0;
int rear  = 0;

/* ---------------- QUEUE FUNCTIONS ---------------- */

bool isQueueFull()
{
    return ((rear + 1) % MAX_QUEUE == front);
}

bool isQueueEmpty()
{
    return (front == rear);
}

void enqueue(int carID)
{
    if (!isQueueFull())
    {
        carQueue[rear] = carID;
        rear = (rear + 1) % MAX_QUEUE;

        Serial.print("Car ");
        Serial.print(carID);
        Serial.println(" added to queue");
    }
}

int dequeue()
{
    if (!isQueueEmpty())
    {
        int carID = carQueue[front];
        front = (front + 1) % MAX_QUEUE;
        return carID;
    }
    return -1;
}

/* ---------------- MIN HEAP FUNCTIONS ---------------- */

void heapifyUp(int i)
{
    while (i != 0 && minHeap[(i - 1) / 2] > minHeap[i])
    {
        int temp = minHeap[i];
        minHeap[i] = minHeap[(i - 1) / 2];
        minHeap[(i - 1) / 2] = temp;

        i = (i - 1) / 2;
    }
}

void heapifyDown(int i)
{
    int smallest = i;
    int left  = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < heapSize && minHeap[left] < minHeap[smallest])
        smallest = left;

    if (right < heapSize && minHeap[right] < minHeap[smallest])
        smallest = right;

    if (smallest != i)
    {
        int temp = minHeap[i];
        minHeap[i] = minHeap[smallest];
        minHeap[smallest] = temp;

        heapifyDown(smallest);
    }
}

void insertHeap(int slotID)
{
    minHeap[heapSize] = slotID;
    heapifyUp(heapSize);
    heapSize++;
}

int extractMin()
{
    if (heapSize <= 0)
        return -1;

    int root = minHeap[0];
    minHeap[0] = minHeap[heapSize - 1];
    heapSize--;

    heapifyDown(0);

    return root;
}

/* ---------------- ULTRASONIC DISTANCE FUNCTION ---------------- */

int checkDistance(int trig, int echo)
{
    digitalWrite(trig, LOW);
    delayMicroseconds(2);

    digitalWrite(trig, HIGH);
    delayMicroseconds(10);

    digitalWrite(trig, LOW);

    long duration = pulseIn(echo, HIGH, 30000);

    if (duration == 0)
        return 999;

    return duration * 0.034 / 2;
}

/* ---------------- SETUP ---------------- */

void setup()
{
    Serial.begin(9600);

    pinMode(TRIG_ENTRY, OUTPUT);
    pinMode(ECHO_ENTRY, INPUT);

    for (int i = 0; i < MAX_SLOTS; i++)
    {
        pinMode(slotTrig[i], OUTPUT);
        pinMode(slotEcho[i], INPUT);

        insertHeap(i);   // All slots initially available
    }

    entryGate.attach(9);
    entryGate.write(0);   // Gate closed

    Serial.println("Smart Parking System Ready with Min Heap");
}

/* ---------------- LOOP ---------------- */

void loop()
{
    int distanceEntry = checkDistance(TRIG_ENTRY, ECHO_ENTRY);

    /* ---- Update Slot Status ---- */

    int availableSlots = 0;

    for (int i = 0; i < MAX_SLOTS; i++)
    {
        int d = checkDistance(slotTrig[i], slotEcho[i]);

        bool prevOccupied = slotOccupied[i];
        slotOccupied[i] = (d < 10);

        if (!slotOccupied[i] && prevOccupied)
            insertHeap(i);   // Slot freed

        if (!slotOccupied[i])
            availableSlots++;

        Serial.print("Slot ");
        Serial.print(i + 1);
        Serial.print(": ");
        Serial.print(slotOccupied[i] ? "Occupied" : "Available");
        Serial.print(" (");
        Serial.print(d);
        Serial.println(" cm)");
    }

    Serial.print("Entry Sensor: ");
    Serial.print(distanceEntry);
    Serial.println(" cm");

    Serial.print("Available Slots: ");
    Serial.println(availableSlots);

    Serial.println("-----------------------");

    /* ---- Enqueue Car ---- */

    if (distanceEntry < 7 && !isQueueFull())
    {
        static unsigned long lastTime = 0;

        if (millis() - lastTime > 4000)
        {
            int carID = random(10000, 99999);
            enqueue(carID);
            lastTime = millis();
        }
    }

    /* ---- Allow Car Entry ---- */

    if (!isQueueEmpty() && heapSize > 0)
    {
        int slotID = extractMin();

        if (!slotOccupied[slotID])
        {
            int carID = dequeue();

            Serial.print("Car ");
            Serial.print(carID);
            Serial.print(" entering Slot ");
            Serial.println(slotID + 1);

            entryGate.write(90);
            delay(4000);
            entryGate.write(0);

            slotOccupied[slotID] = true;

            Serial.println("Gate Closed");
        }
        else
        {
            insertHeap(slotID);
        }
    }

    delay(1500);
}
