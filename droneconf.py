class Drone:
    def __init__(self, dronebyte, droneName):
        self.dronebyte = dronebyte
        self.droneName = droneName


class Node:
    def __init__(self, valdrone, dronenode, drone):
        self.valdrone = valdrone
        self.dronenode = dronenode
        self.drone = drone
        self.next = None


def add_node(head, drone):
    new_node = Node(drone.dronebyte, drone.droneName, drone)
    new_node.next = head
    return new_node


def store_drones_and_write_to_file(filename, head):
    temp = head

    with open(filename, 'w') as f:
        while temp:
            f.write(f"{temp.valdrone},{temp.dronenode},{temp.drone.dronebyte},{temp.drone.droneName}\n")
            temp = temp.next

    print("List stored in file successfully")


# Create a sample Drone
sample_drone = Drone(1, "SampleDrone")

# Add the sample drone to the linked list
linked_list_head = add_node(None, sample_drone)

# Store drones in the linked list and write to file
store_drones_and_write_to_file("dronesconf.txt", linked_list_head)
