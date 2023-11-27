import ipaddress

CYAN = "\033[96m"
RED = "\033[91m"
END = "\033[0m"

def check_ip(ip):
    """
    checks if an ip is valid
    """
    try:
        ipaddress.IPv4Address(ip)
        return True
    except ipaddress.AddressValueError:
        return False

def check_subnet(subnet):
    """
    checks if a subnet is valid
    """
    try:
        ipaddress.IPv4Network(f"192.0.2.1/{subnet}", strict=False)
        return True
    except (ipaddress.AddressValueError, ipaddress.NetmaskValueError):
        return False

def slash_to_normal(subnet):
    """
    converts slash notation to regular notation
    """
    try:
        subnet = int(subnet)
    except ValueError:
        return None

    if subnet < 0 or subnet > 32:
        return None

    mask = (0xFFFFFFFF << (32 - subnet)) & 0xFFFFFFFF
    mask_str = ".".join([str((mask >> (8 * i)) & 255) for i in range(3, -1, -1)])
    return mask_str

def calculate_network_info():
    """
    calculates first/last host ip and broadcast ip
    """
    while True:
        network_address = input(f"{CYAN} please enter the network address {END}")
        subnet_input = input(f"{CYAN} please enter the subnet mask {END}")

        if check_ip(network_address) and check_subnet(subnet_input):
            subnet_mask = subnet_input if '/' in subnet_input else slash_to_normal(subnet_input)
            if subnet_mask is None:
                print(RED, "invalid subnet mask", END)
                continue

            network = ipaddress.IPv4Network(f"{network_address}/{subnet_mask}", strict=False)

            router_ip = network.network_address + 1
            last_host_ip = network.broadcast_address - 1
            broadcast_ip = network.broadcast_address

            print(f"Router IP: {router_ip}")
            print(f"Last Host IP: {last_host_ip}")
            print(f"Broadcast IP: {broadcast_ip}")
            break

        print(RED, "invalid network address / subnet mask. retry", END)

calculate_network_info()