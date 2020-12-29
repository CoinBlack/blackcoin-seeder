#ifndef _DNS_H_
#define _DNS_H_ 1

#include <stdint.h>

struct addr_t {
    int v;
    union {
       unsigned char v4[4];
       unsigned char v6[16];
    } data;
};

struct dns_opt_t {
  int port;
  int datattl;
  int nsttl;
  const char *host;
  const char *addr;
  const char *ns;
  const char *mbox;
  int (*cb)(void *opt, char *requested_hostname, addr_t *addr, int max, int ipv4, int ipv6);
  // stats
  uint64_t nRequests;
};

int dnsserver(dns_opt_t *opt);

#endif
