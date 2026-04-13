#include <stdio.h>

#include <stdint.h>

void print_ip(uint32_t ip) {

printf("%u.%u.%u.%u",

(ip >> 24) & 0xFF,

(ip >> 16) & 0xFF,

(ip >> 8) & 0xFF,

ip & 0xFF);

}

int main() {

int a, b, c, d;

int main_mask, sub_mask;

uint32_t used_groups;

printf("Enter Base IP (format: xxx.xxx.xxx.xxx): ");

if (scanf("%d.%d.%d.%d", &a, &b, &c, &d) != 4) {

printf("Invalid IP format.
");

return 1;

}

printf("Enter Main Mask (e.g., 24): ");

scanf("%d", &main_mask);

printf("Enter Subgroup Mask (e.g., 28): ");

scanf("%d", &sub_mask);

if (sub_mask < main_mask) {

printf("Error: Subgroup mask must be >= main mask.
");

return 1;

}

uint32_t ip = ((uint32_t)a << 24) \| ((uint32_t)b << 16) \|

((uint32_t)c << 8) \| (uint32_t)d;

uint64_t total_addresses = (uint64_t)1 << (32 - main_mask);

uint32_t addr_per_group = (uint32_t)1 << (32 - sub_mask);

uint32_t max_possible_groups = (uint32_t)(total_addresses /
addr_per_group);

printf("
Enter number of groups actually used: ");

scanf("%u", &used_groups);

uint64_t total_assigned = (uint64_t)used_groups * addr_per_group;

uint64_t remaining = total_addresses - total_assigned;

printf("
\--- Subnet Results \---
");

printf("Main Network: "); print_ip(ip); printf("/%d
", main_mask);

printf("Total Addresses: %llu
", total_addresses);

printf("Address/Group: %u
", addr_per_group);

printf("Max Groups: %u
", max_possible_groups);

printf("Assigned Addr: %llu
", total_assigned);

printf("Remaining Addr: %llu
", remaining);

printf("\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\---

");

printf("Assigned Subgroup Ranges:
");

for (uint32_t i = 0; i < used_groups; i++) {

uint32_t g_start = ip + (i * addr_per_group);

uint32_t g_end = g_start + addr_per_group - 1;

printf("Group %u: ", i + 1);

print_ip(g_start);

printf(" to ");

print_ip(g_end);

printf("
");

}

return 0;

}
