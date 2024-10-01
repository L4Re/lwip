/* SPDX-License-Identifier: BSD-3-Clause */
/*
 * Copyright (C) 2022 Kernkonzept GmbH.
 * Author(s): Stephan Gerhold <stephan.gerhold@kernkonzept.com>
 */

#ifndef LWIP_HDR_EXTERNAL_INET_H
#define LWIP_HDR_EXTERNAL_INET_H

#include <arpa/inet.h>

#if LWIP_IPV4
#define inet_addr_from_ip4addr(target_inaddr, source_ipaddr) ((target_inaddr)->s_addr = ip4_addr_get_u32(source_ipaddr))
#define inet_addr_to_ip4addr(target_ipaddr, source_inaddr)   (ip4_addr_set_u32(target_ipaddr, (source_inaddr)->s_addr))
#endif /* LWIP_IPV4 */

#if LWIP_IPV6
#define inet6_addr_from_ip6addr(target_in6addr, source_ip6addr) {(target_in6addr)->s6_addr32[0] = (source_ip6addr)->addr[0]; \
                                                                 (target_in6addr)->s6_addr32[1] = (source_ip6addr)->addr[1]; \
                                                                 (target_in6addr)->s6_addr32[2] = (source_ip6addr)->addr[2]; \
                                                                 (target_in6addr)->s6_addr32[3] = (source_ip6addr)->addr[3];}
#define inet6_addr_to_ip6addr(target_ip6addr, source_in6addr)   {(target_ip6addr)->addr[0] = (source_in6addr)->s6_addr32[0]; \
                                                                 (target_ip6addr)->addr[1] = (source_in6addr)->s6_addr32[1]; \
                                                                 (target_ip6addr)->addr[2] = (source_in6addr)->s6_addr32[2]; \
                                                                 (target_ip6addr)->addr[3] = (source_in6addr)->s6_addr32[3]; \
                                                                 ip6_addr_clear_zone(target_ip6addr);}
#endif /* LWIP_IPV6 */

#endif /* LWIP_HDR_EXTERNAL_INET_H */
