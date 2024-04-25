/* spi_dw_regs.h - Designware SPI driver private definitions */

/*
 * Copyright (c) 2015 Intel Corporation.
 * Copyright (c) 2023 Synopsys, Inc. All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef ZEPHYR_DRIVERS_SPI_SPI_DW_REGS_H_
#define ZEPHYR_DRIVERS_SPI_SPI_DW_REGS_H_

#ifdef __cplusplus
extern "C" {
#endif

#define DW_SPI_REG_CTRLR0		(0x00 + 0x500)
#define DW_SPI_REG_CTRLR1		(0x04 + 0x500)
#define DW_SPI_REG_SSIENR		(0x08 + 0x500)
#define DW_SPI_REG_MWCR			(0x0c + 0x500)
#define DW_SPI_REG_SER			(0x10 + 0x500)
#define DW_SPI_REG_BAUDR		(0x14 + 0x500)
#define DW_SPI_REG_TXFTLR		(0x18 + 0x500)
#define DW_SPI_REG_RXFTLR		(0x1c + 0x500)
#define DW_SPI_REG_TXFLR		(0x20 + 0x500)
#define DW_SPI_REG_RXFLR		(0x24 + 0x500)
#define DW_SPI_REG_SR			(0x28 + 0x500)
#define DW_SPI_REG_IMR			(0x2c + 0x500)
#define DW_SPI_REG_ISR			(0x30 + 0x500)
#define DW_SPI_REG_RISR			(0x34 + 0x500)
#define DW_SPI_REG_TXOICR		(0x38 + 0x500)
#define DW_SPI_REG_RXOICR		(0x3c + 0x500)
#define DW_SPI_REG_RXUICR		(0x40 + 0x500)
#define DW_SPI_REG_MSTICR		(0x44 + 0x500)
#define DW_SPI_REG_ICR			(0x48 + 0x500)
#define DW_SPI_REG_DMACR		(0x4c + 0x500)
#define DW_SPI_REG_DMATDLR		(0x50 + 0x500)
#define DW_SPI_REG_DMARDLR		(0x54 + 0x500)
#define DW_SPI_REG_IDR			(0x58 + 0x500)
#define DW_SPI_REG_SSI_COMP_VERSION	(0x5c + 0x500)
#define DW_SPI_REG_DR			(0x60 + 0x500)
#define DW_SPI_REG_RX_SAMPLE_DLY	(0xf0 + 0x500)

/* Register helpers */
DEFINE_MM_REG_WRITE(ctrlr0, DW_SPI_REG_CTRLR0, 32)
DEFINE_MM_REG_READ(ctrlr0, DW_SPI_REG_CTRLR0, 32)
DEFINE_MM_REG_WRITE(txftlr, DW_SPI_REG_TXFTLR, 32)
DEFINE_MM_REG_WRITE(rxftlr, DW_SPI_REG_RXFTLR, 32)
DEFINE_MM_REG_READ(rxftlr, DW_SPI_REG_RXFTLR, 32)
DEFINE_MM_REG_READ(txftlr, DW_SPI_REG_TXFTLR, 32)
DEFINE_MM_REG_WRITE(dr, DW_SPI_REG_DR, 32)
DEFINE_MM_REG_READ(dr, DW_SPI_REG_DR, 32)
DEFINE_MM_REG_READ(ssi_comp_version, DW_SPI_REG_SSI_COMP_VERSION, 32)

#ifdef CONFIG_SPI_DW_ACCESS_WORD_ONLY
DEFINE_MM_REG_WRITE(ctrlr1, DW_SPI_REG_CTRLR1, 32)
DEFINE_MM_REG_READ(ctrlr1, DW_SPI_REG_CTRLR1, 32)
DEFINE_MM_REG_WRITE(ser, DW_SPI_REG_SER, 32)
#else
DEFINE_MM_REG_WRITE(ctrlr1, DW_SPI_REG_CTRLR1, 16)
DEFINE_MM_REG_READ(ctrlr1, DW_SPI_REG_CTRLR1, 16)
DEFINE_MM_REG_WRITE(ser, DW_SPI_REG_SER, 8)
#endif

/* ICR is on a unique bit */
DEFINE_TEST_BIT_OP(icr, DW_SPI_REG_ICR, DW_SPI_SR_ICR_BIT)
#define clear_interrupts(dev) test_bit_icr(dev)

#ifdef __cplusplus
}
#endif

#endif /* ZEPHYR_DRIVERS_SPI_SPI_DW_REGS_H_ */
