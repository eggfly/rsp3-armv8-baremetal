/*
 * gicv3_base.h
 *
 *  Created on: Feb 8, 2018
 *      Author: 13774
 */

#ifndef INCLUDE_ARCH_COMMON_AARCH64_GICV3_BASE_H_
#define INCLUDE_ARCH_COMMON_AARCH64_GICV3_BASE_H_


#define GIC_DIST_BASE 0x08000000
#define GIC_CPU_BASE  0x08010000
#define GIC_V2M_BASE 0x08020000
#define GIC_ITS_BASE 0x08080000
#define GIC_REDIST_BASE 0x080A0000


#define GIC_REDIST_RD_BASE  (GIC_REDIST_BASE)
// +64KB
#define GIC_REDIST_SGI_BASE (GIC_REDIST_RD_BASE + 1024*64)

#define GICD_CTLR_MEM_MAPPED_ADDR (GIC_DIST_BASE+0)
#define GICD_IIDR_MEM_MAPPED_ADDR (GIC_DIST_BASE+0x8)
#define GICD_ISENABLER_MEM_MAPPED_ADDR(n) (GIC_DIST_BASE + 0x100 + 4*(n))
#define GICD_ISPENDR_MEM_MAPPED_ADDR(n) (GIC_DIST_BASE + 0x200 + 4*(n))
#define GICD_ISACTIVER_MEM_MAPPED_ADDR(n) (GIC_DIST_BASE + 0x300 + 4*(n))
#define GICD_ISENABLER0_MEM_MAPPED_ADDR GICD_ISENABLER_MEM_MAPPED_ADDR(0)
#define GICD_ISENABLER1_MEM_MAPPED_ADDR GICD_ISENABLER_MEM_MAPPED_ADDR(1)
#define GICD_ISENABLER2_MEM_MAPPED_ADDR GICD_ISENABLER_MEM_MAPPED_ADDR(2)
#define GICD_ISENABLER3_MEM_MAPPED_ADDR GICD_ISENABLER_MEM_MAPPED_ADDR(3)
#define GICD_ISENABLER4_MEM_MAPPED_ADDR GICD_ISENABLER_MEM_MAPPED_ADDR(4)
#define GICD_ISENABLER5_MEM_MAPPED_ADDR GICD_ISENABLER_MEM_MAPPED_ADDR(5)
#define GICD_ISENABLER6_MEM_MAPPED_ADDR GICD_ISENABLER_MEM_MAPPED_ADDR(6)
#define GICD_ISENABLER7_MEM_MAPPED_ADDR GICD_ISENABLER_MEM_MAPPED_ADDR(7)
#define GICD_ISENABLER8_MEM_MAPPED_ADDR GICD_ISENABLER_MEM_MAPPED_ADDR(8)
#define GICD_ISENABLER9_MEM_MAPPED_ADDR GICD_ISENABLER_MEM_MAPPED_ADDR(9)
#define GICD_ISENABLER10_MEM_MAPPED_ADDR GICD_ISENABLER_MEM_MAPPED_ADDR(10)
#define GICD_ISENABLER11_MEM_MAPPED_ADDR GICD_ISENABLER_MEM_MAPPED_ADDR(11)
#define GICD_ISENABLER12_MEM_MAPPED_ADDR GICD_ISENABLER_MEM_MAPPED_ADDR(12)
#define GICD_ISENABLER13_MEM_MAPPED_ADDR GICD_ISENABLER_MEM_MAPPED_ADDR(13)
#define GICD_ISENABLER14_MEM_MAPPED_ADDR GICD_ISENABLER_MEM_MAPPED_ADDR(14)
#define GICD_ISENABLER15_MEM_MAPPED_ADDR GICD_ISENABLER_MEM_MAPPED_ADDR(15)
#define GICD_ISENABLER16_MEM_MAPPED_ADDR GICD_ISENABLER_MEM_MAPPED_ADDR(16)
#define GICD_ISENABLER17_MEM_MAPPED_ADDR GICD_ISENABLER_MEM_MAPPED_ADDR(17)
#define GICD_ISENABLER18_MEM_MAPPED_ADDR GICD_ISENABLER_MEM_MAPPED_ADDR(18)
#define GICD_ISENABLER19_MEM_MAPPED_ADDR GICD_ISENABLER_MEM_MAPPED_ADDR(19)
#define GICD_ISENABLER20_MEM_MAPPED_ADDR GICD_ISENABLER_MEM_MAPPED_ADDR(20)
#define GICD_ISENABLER21_MEM_MAPPED_ADDR GICD_ISENABLER_MEM_MAPPED_ADDR(21)
#define GICD_ISENABLER22_MEM_MAPPED_ADDR GICD_ISENABLER_MEM_MAPPED_ADDR(22)
#define GICD_ISENABLER23_MEM_MAPPED_ADDR GICD_ISENABLER_MEM_MAPPED_ADDR(23)
#define GICD_ISENABLER24_MEM_MAPPED_ADDR GICD_ISENABLER_MEM_MAPPED_ADDR(24)
#define GICD_ISENABLER25_MEM_MAPPED_ADDR GICD_ISENABLER_MEM_MAPPED_ADDR(25)
#define GICD_ISENABLER26_MEM_MAPPED_ADDR GICD_ISENABLER_MEM_MAPPED_ADDR(26)
#define GICD_ISENABLER27_MEM_MAPPED_ADDR GICD_ISENABLER_MEM_MAPPED_ADDR(27)
#define GICD_ISENABLER28_MEM_MAPPED_ADDR GICD_ISENABLER_MEM_MAPPED_ADDR(28)
#define GICD_ISENABLER29_MEM_MAPPED_ADDR GICD_ISENABLER_MEM_MAPPED_ADDR(29)
#define GICD_ISENABLER30_MEM_MAPPED_ADDR GICD_ISENABLER_MEM_MAPPED_ADDR(30)
#define GICD_ISENABLER31_MEM_MAPPED_ADDR GICD_ISENABLER_MEM_MAPPED_ADDR(31)

#define GICD_ISPENDR0_MEM_MAPPED_ADDR GICD_ISPENDR_MEM_MAPPED_ADDR(0)
#define GICD_ISPENDR1_MEM_MAPPED_ADDR GICD_ISPENDR_MEM_MAPPED_ADDR(1)
#define GICD_ISPENDR2_MEM_MAPPED_ADDR GICD_ISPENDR_MEM_MAPPED_ADDR(2)
#define GICD_ISPENDR3_MEM_MAPPED_ADDR GICD_ISPENDR_MEM_MAPPED_ADDR(3)
#define GICD_ISPENDR4_MEM_MAPPED_ADDR GICD_ISPENDR_MEM_MAPPED_ADDR(4)
#define GICD_ISPENDR5_MEM_MAPPED_ADDR GICD_ISPENDR_MEM_MAPPED_ADDR(5)
#define GICD_ISPENDR6_MEM_MAPPED_ADDR GICD_ISPENDR_MEM_MAPPED_ADDR(6)
#define GICD_ISPENDR7_MEM_MAPPED_ADDR GICD_ISPENDR_MEM_MAPPED_ADDR(7)
#define GICD_ISPENDR8_MEM_MAPPED_ADDR GICD_ISPENDR_MEM_MAPPED_ADDR(8)
#define GICD_ISPENDR9_MEM_MAPPED_ADDR GICD_ISPENDR_MEM_MAPPED_ADDR(9)
#define GICD_ISPENDR10_MEM_MAPPED_ADDR GICD_ISPENDR_MEM_MAPPED_ADDR(10)
#define GICD_ISPENDR11_MEM_MAPPED_ADDR GICD_ISPENDR_MEM_MAPPED_ADDR(11)
#define GICD_ISPENDR12_MEM_MAPPED_ADDR GICD_ISPENDR_MEM_MAPPED_ADDR(12)
#define GICD_ISPENDR13_MEM_MAPPED_ADDR GICD_ISPENDR_MEM_MAPPED_ADDR(13)
#define GICD_ISPENDR14_MEM_MAPPED_ADDR GICD_ISPENDR_MEM_MAPPED_ADDR(14)
#define GICD_ISPENDR15_MEM_MAPPED_ADDR GICD_ISPENDR_MEM_MAPPED_ADDR(15)
#define GICD_ISPENDR16_MEM_MAPPED_ADDR GICD_ISPENDR_MEM_MAPPED_ADDR(16)
#define GICD_ISPENDR17_MEM_MAPPED_ADDR GICD_ISPENDR_MEM_MAPPED_ADDR(17)
#define GICD_ISPENDR18_MEM_MAPPED_ADDR GICD_ISPENDR_MEM_MAPPED_ADDR(18)
#define GICD_ISPENDR19_MEM_MAPPED_ADDR GICD_ISPENDR_MEM_MAPPED_ADDR(19)
#define GICD_ISPENDR20_MEM_MAPPED_ADDR GICD_ISPENDR_MEM_MAPPED_ADDR(20)
#define GICD_ISPENDR21_MEM_MAPPED_ADDR GICD_ISPENDR_MEM_MAPPED_ADDR(21)
#define GICD_ISPENDR22_MEM_MAPPED_ADDR GICD_ISPENDR_MEM_MAPPED_ADDR(22)
#define GICD_ISPENDR23_MEM_MAPPED_ADDR GICD_ISPENDR_MEM_MAPPED_ADDR(23)
#define GICD_ISPENDR24_MEM_MAPPED_ADDR GICD_ISPENDR_MEM_MAPPED_ADDR(24)
#define GICD_ISPENDR25_MEM_MAPPED_ADDR GICD_ISPENDR_MEM_MAPPED_ADDR(25)
#define GICD_ISPENDR26_MEM_MAPPED_ADDR GICD_ISPENDR_MEM_MAPPED_ADDR(26)
#define GICD_ISPENDR27_MEM_MAPPED_ADDR GICD_ISPENDR_MEM_MAPPED_ADDR(27)
#define GICD_ISPENDR28_MEM_MAPPED_ADDR GICD_ISPENDR_MEM_MAPPED_ADDR(28)
#define GICD_ISPENDR29_MEM_MAPPED_ADDR GICD_ISPENDR_MEM_MAPPED_ADDR(29)
#define GICD_ISPENDR30_MEM_MAPPED_ADDR GICD_ISPENDR_MEM_MAPPED_ADDR(30)
#define GICD_ISPENDR31_MEM_MAPPED_ADDR GICD_ISPENDR_MEM_MAPPED_ADDR(31)


#define GICD_ISACTIVER0_MEM_MAPPED_ADDR GICD_ISACTIVER_MEM_MAPPED_ADDR(0)
#define GICD_ISACTIVER1_MEM_MAPPED_ADDR GICD_ISACTIVER_MEM_MAPPED_ADDR(1)
#define GICD_ISACTIVER2_MEM_MAPPED_ADDR GICD_ISACTIVER_MEM_MAPPED_ADDR(2)
#define GICD_ISACTIVER3_MEM_MAPPED_ADDR GICD_ISACTIVER_MEM_MAPPED_ADDR(3)
#define GICD_ISACTIVER4_MEM_MAPPED_ADDR GICD_ISACTIVER_MEM_MAPPED_ADDR(4)
#define GICD_ISACTIVER5_MEM_MAPPED_ADDR GICD_ISACTIVER_MEM_MAPPED_ADDR(5)
#define GICD_ISACTIVER6_MEM_MAPPED_ADDR GICD_ISACTIVER_MEM_MAPPED_ADDR(6)
#define GICD_ISACTIVER7_MEM_MAPPED_ADDR GICD_ISACTIVER_MEM_MAPPED_ADDR(7)
#define GICD_ISACTIVER8_MEM_MAPPED_ADDR GICD_ISACTIVER_MEM_MAPPED_ADDR(8)
#define GICD_ISACTIVER9_MEM_MAPPED_ADDR GICD_ISACTIVER_MEM_MAPPED_ADDR(9)
#define GICD_ISACTIVER10_MEM_MAPPED_ADDR GICD_ISACTIVER_MEM_MAPPED_ADDR(10)
#define GICD_ISACTIVER11_MEM_MAPPED_ADDR GICD_ISACTIVER_MEM_MAPPED_ADDR(11)
#define GICD_ISACTIVER12_MEM_MAPPED_ADDR GICD_ISACTIVER_MEM_MAPPED_ADDR(12)
#define GICD_ISACTIVER13_MEM_MAPPED_ADDR GICD_ISACTIVER_MEM_MAPPED_ADDR(13)
#define GICD_ISACTIVER14_MEM_MAPPED_ADDR GICD_ISACTIVER_MEM_MAPPED_ADDR(14)
#define GICD_ISACTIVER15_MEM_MAPPED_ADDR GICD_ISACTIVER_MEM_MAPPED_ADDR(15)
#define GICD_ISACTIVER16_MEM_MAPPED_ADDR GICD_ISACTIVER_MEM_MAPPED_ADDR(16)
#define GICD_ISACTIVER17_MEM_MAPPED_ADDR GICD_ISACTIVER_MEM_MAPPED_ADDR(17)
#define GICD_ISACTIVER18_MEM_MAPPED_ADDR GICD_ISACTIVER_MEM_MAPPED_ADDR(18)
#define GICD_ISACTIVER19_MEM_MAPPED_ADDR GICD_ISACTIVER_MEM_MAPPED_ADDR(19)
#define GICD_ISACTIVER20_MEM_MAPPED_ADDR GICD_ISACTIVER_MEM_MAPPED_ADDR(20)
#define GICD_ISACTIVER21_MEM_MAPPED_ADDR GICD_ISACTIVER_MEM_MAPPED_ADDR(21)
#define GICD_ISACTIVER22_MEM_MAPPED_ADDR GICD_ISACTIVER_MEM_MAPPED_ADDR(22)
#define GICD_ISACTIVER23_MEM_MAPPED_ADDR GICD_ISACTIVER_MEM_MAPPED_ADDR(23)
#define GICD_ISACTIVER24_MEM_MAPPED_ADDR GICD_ISACTIVER_MEM_MAPPED_ADDR(24)
#define GICD_ISACTIVER25_MEM_MAPPED_ADDR GICD_ISACTIVER_MEM_MAPPED_ADDR(25)
#define GICD_ISACTIVER26_MEM_MAPPED_ADDR GICD_ISACTIVER_MEM_MAPPED_ADDR(26)
#define GICD_ISACTIVER27_MEM_MAPPED_ADDR GICD_ISACTIVER_MEM_MAPPED_ADDR(27)
#define GICD_ISACTIVER28_MEM_MAPPED_ADDR GICD_ISACTIVER_MEM_MAPPED_ADDR(28)
#define GICD_ISACTIVER29_MEM_MAPPED_ADDR GICD_ISACTIVER_MEM_MAPPED_ADDR(29)
#define GICD_ISACTIVER30_MEM_MAPPED_ADDR GICD_ISACTIVER_MEM_MAPPED_ADDR(30)
#define GICD_ISACTIVER31_MEM_MAPPED_ADDR GICD_ISACTIVER_MEM_MAPPED_ADDR(31)

#define GICR_IPRIORITYR_MEM_MAPPED_ADDR(n) (GIC_REDIST_SGI_BASE + 0x400 + 4*(n))
#define GICR_IPRIORITYR0_MEM_MAPPED_ADDR GICR_IPRIORITYR_MEM_MAPPED_ADDR(0)
#define GICR_IPRIORITYR1_MEM_MAPPED_ADDR GICR_IPRIORITYR_MEM_MAPPED_ADDR(1)
#define GICR_IPRIORITYR2_MEM_MAPPED_ADDR GICR_IPRIORITYR_MEM_MAPPED_ADDR(2)
#define GICR_IPRIORITYR3_MEM_MAPPED_ADDR GICR_IPRIORITYR_MEM_MAPPED_ADDR(3)
#define GICR_IPRIORITYR4_MEM_MAPPED_ADDR GICR_IPRIORITYR_MEM_MAPPED_ADDR(4)
#define GICR_IPRIORITYR5_MEM_MAPPED_ADDR GICR_IPRIORITYR_MEM_MAPPED_ADDR(5)
#define GICR_IPRIORITYR6_MEM_MAPPED_ADDR GICR_IPRIORITYR_MEM_MAPPED_ADDR(6)
#define GICR_IPRIORITYR7_MEM_MAPPED_ADDR GICR_IPRIORITYR_MEM_MAPPED_ADDR(7)

#define GICR_CTLR_MEM_MAPPED_ADDR  (GIC_REDIST_BASE+0)
#define GICR_WAKER_MEM_MAPPED_ADDR (GIC_REDIST_BASE+0x14)
#define GICR_IGROUPR0_MEM_MAPPED_ADDR  (GIC_REDIST_SGI_BASE + 0x80)
#define GICR_ISACTIVER0_MEM_MAPPED_ADDR (GIC_REDIST_SGI_BASE + 0x300)
#define GICR_ISPENDR0_MEM_MAPPED_ADDR (GIC_REDIST_SGI_BASE+0x200)
#define GICR_ISENABLER0_MEM_MAPPED_ADDR (GIC_REDIST_SGI_BASE + 0x100)

#define GICR_ICENABLER0_MEM_MAPPED_ADDR (GIC_REDIST_SGI_BASE+0x180)
#define GICR_ICFGR0_MEM_MAPPED_ADDR (GIC_REDIST_SGI_BASE+0xc00)
#define GICR_ICFGR1_MEM_MAPPED_ADDR (GIC_REDIST_SGI_BASE+0xc04)
#define GICR_ICACTIVER0_MEM_MAPPED_ADDR (GIC_REDIST_SGI_BASE + 0x380)



#endif /* INCLUDE_ARCH_COMMON_AARCH64_GICV3_DEFINES_H_ */
