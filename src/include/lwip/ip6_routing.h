#pragma once

#ifndef LWIP_HDR_IP6_ROUTING_H
#define LWIP_HDR_IP6_ROUTING_H

#include "lwip/opt.h"
#include "lwip/ip_addr.h"

#ifdef __cplusplus
extern "C" {
#endif

#define GW_NAME_SIZE 5

struct rt_entry {
	ip6_addr_t addr;
	uint8_t mask;
	char gw_name[GW_NAME_SIZE];
};


bool ip_add_route(const ip6_addr_t* ip, uint8_t mask, const char* gw);

struct netif* ip_find_route(const ip6_addr_t* ip);

bool ip_rm_route(const ip6_addr_t* ip, uint8_t mask, const char* gw);

void ip_update_route(const ip6_addr_t* ip, uint8_t mask, const char* new_gw);

void ip_print_table();

void print_ip(const ip6_addr_t* ip);

#ifdef __cplusplus
}
#endif


#endif // LWIP_HDR_IP6_ROUTING_H

