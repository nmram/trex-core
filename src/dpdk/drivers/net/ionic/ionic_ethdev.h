/* SPDX-License-Identifier: (BSD-3-Clause OR GPL-2.0)
 * Copyright(c) 2018-2019 Pensando Systems, Inc. All rights reserved.
 */

#ifndef _IONIC_ETHDEV_H_
#define _IONIC_ETHDEV_H_

#include <rte_ethdev.h>

#define IONIC_ETH_RSS_OFFLOAD_ALL ( \
	ETH_RSS_IPV4 | \
	ETH_RSS_NONFRAG_IPV4_TCP | \
	ETH_RSS_NONFRAG_IPV4_UDP | \
	ETH_RSS_IPV6 | \
	ETH_RSS_NONFRAG_IPV6_TCP | \
	ETH_RSS_NONFRAG_IPV6_UDP)

#define IONIC_ETH_DEV_TO_LIF(eth_dev) ((struct ionic_lif *) \
	(eth_dev)->data->dev_private)

struct ionic_bars;
struct ionic_dev_intf;

int eth_ionic_dev_probe(void *bus_dev, struct rte_device *rte_dev,
	struct ionic_bars *bars, const struct ionic_dev_intf *intf,
	uint16_t device_id, uint16_t vendor_id);
int eth_ionic_dev_remove(struct rte_device *rte_dev);

void ionic_dev_interrupt_handler(void *param);
int ionic_dev_link_update(struct rte_eth_dev *eth_dev, int wait_to_complete);

#endif /* _IONIC_ETHDEV_H_ */

