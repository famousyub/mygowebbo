class Delta:
    def __init__(self):
        self._sizer = 0
        self.fg_drone = ""
        self.deltaname = ""
        self.droneconf_actif = ""
        self.droneIdbyte = 0
        self.droneId = ""

class Droneconfig:
    def __init__(self):
        self.dela = Delta()
        self.config_beta = ""
        self.droneElice = 0
        self.portNum = ""
        self.urlFetch = [0] * 1024
        self.filelog = ""

class Drone:
    def __init__(self):
        self.droneconfig = Droneconfig()
        self.drones_fg = 0
        self.dronebyte = 0
        self.droneName = ""
        self.linenName = ""
        self.lines = 0
        self.user_id = 0
        self.isUsed = 0
        self.readdrone = None

class Node:
    def __init__(self):
        self.valdrone = 0
        self.dronenode = ""
        self.drone = Drone()
        self.next = None

# Function to add a new node to the linked list
def add_node(head, drone):
    new_node = Node()
    new_node.valdrone = drone.dronebyte
    new_node.dronenode = drone.droneName
    new_node.drone = drone
    new_node.next = head
    return new_node

# Function to store drones in a linked list and write to a file using fprintf
def store_drones_and_write_to_file(filename, head):
    temp = head
    with open(filename, "w") as saver:
        while temp is not None:
            saver.write(f"{temp.valdrone},{temp.dronenode},{temp.drone.dronebyte},{temp.drone.droneName}\n")
            temp = temp.next
    print("List stored in file successfully")

# Create a sample Drone
sample_drone1 = Drone()
sample_drone1.dronebyte = 1
sample_drone1.droneName = "SampleDrone1"

# Create another sample Drone
sample_drone2 = Drone()
sample_drone2.dronebyte = 2
sample_drone2.droneName = "SampleDrone2"

# Add the sample drones to the linked list
head = add_node(None, sample_drone1)
head = add_node(head, sample_drone2)

# Store drones in the linked list and write to file using fprintf
store_drones_and_write_to_file("drones.txt", head)
