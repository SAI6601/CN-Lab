#include <stdio.h>
#include <stdint.h>
#include <math.h>

void print_ip(uint32_t ip) {
    printf("%d.%d.%d.%d", (ip >> 24) & 255, (ip >> 16) & 255, (ip >> 8) & 255, ip & 255);
}

int main() {
    char ip_str[20];
    int main_mask, sub_mask;
    int a, b, c, d;

    printf("Enter IP address (e.g. 192.168.1.0): ");
    scanf("%s", ip_str);
    if (sscanf(ip_str, "%d.%d.%d.%d", &a, &b, &c, &d) != 4) {
        printf("Invalid IP format.\n");
        return 1;
    }

    printf("Enter main subnet mask (e.g. 24): ");
    scanf("%d", &main_mask);
    printf("Enter subgroup mask (e.g. 26): ");
    scanf("%d", &sub_mask);

    if (sub_mask < main_mask) {
        printf("Error: Subgroup mask must be >= main mask.\n");
        return 1;
    }

    uint32_t ip = ((uint32_t)a << 24) | ((uint32_t)b << 16) | ((uint32_t)c << 8) | (uint32_t)d;
    uint32_t main_netmask = (main_mask == 0) ? 0 : (~0u << (32 - main_mask));
    uint32_t network_addr = ip & main_netmask;

    uint32_t total_addresses = (uint32_t)1 << (32 - main_mask);
    uint32_t addr_per_group = (uint32_t)1 << (32 - sub_mask);
    uint32_t max_possible_groups = total_addresses / addr_per_group;

    int used_groups;
    printf("\nEnter number of groups actually used: ");
    scanf("%d", &used_groups);

    if ((uint32_t)used_groups > max_possible_groups) {
        printf("Too many groups. Max is %u.\n", max_possible_groups);
        return 1;
    }

    unsigned long long total_assigned = (unsigned long long)used_groups * addr_per_group;
    unsigned long long remaining = total_addresses - total_assigned;

    printf("\n--- Subnet Results ---\n");
    printf("Main Network: "); print_ip(network_addr); printf("/%d\n", main_mask);
    printf("Total Addresses: %u\n", total_addresses);
    printf("Address/Group: %u\n", addr_per_group);
    printf("Max Groups: %u\n", max_possible_groups);
    printf("Assigned Addr: %llu\n", total_assigned);
    printf("Remaining Addr: %llu\n", remaining);
    printf("--------------------\n");
    printf("Assigned Subgroup Ranges:\n");

    for (int g = 0; g < used_groups; g++) {
        uint32_t start = network_addr + g * addr_per_group;
        uint32_t end = start + addr_per_group - 1;
        printf("Group %d: ", g + 1);
        print_ip(start);
        printf(" - ");
        print_ip(end);
        printf("\n");
    }

    printf("\n");
    return 0;
}
