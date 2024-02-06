import ipaddress
import json
import time

def generate_hosts(ip_cidr):
    ip_network = ipaddress.ip_network(ip_cidr, strict=False)
    hosts = [str(ip) for ip in ip_network.hosts()]
    return hosts

def save_hosts_to_json(hosts, output_file):
    with open(output_file, 'w') as f:
        json.dump(hosts, f, indent=4)
    print(f"hosts saved to {output_file}")

def count_hosts(ip_cidr):
    ip_network = ipaddress.ip_network(ip_cidr, strict=False)
    count = sum(1 for _ in ip_network.hosts())
    return count

if __name__ == "__main__":
    ip_cidr = input("Enter IP address (123.45.67.89/24): ")
    
    start_time = time.time()
    
    hosts = generate_hosts(ip_cidr)
    count = count_hosts(ip_cidr)
    output_file = "hosts.json"
    save_hosts_to_json(hosts, output_file)
    
    end_time = time.time()
    elapsed_time = round(end_time - start_time, 2)
    
    print(f"number of hosts: {count}")
    print(f"took {elapsed_time} seconds")