/*
 * Copyright (c) 2000-2018, 达梦数据库有限公司.
 * All rights reserved.
 */
package dm

import (
	"container/list"
	"io"
)

type Dm_build_1546 struct {
	dm_build_1547 *list.List
	dm_build_1548 *dm_build_1600
	dm_build_1549 int
}

func Dm_build_1550() *Dm_build_1546 {
	return &Dm_build_1546{
		dm_build_1547: list.New(),
		dm_build_1549: 0,
	}
}

func (dm_build_1552 *Dm_build_1546) Dm_build_1551() int {
	return dm_build_1552.dm_build_1549
}

func (dm_build_1554 *Dm_build_1546) Dm_build_1553(dm_build_1555 *Dm_build_0, dm_build_1556 int) int {
	var dm_build_1557 = 0
	var dm_build_1558 = 0
	for dm_build_1557 < dm_build_1556 && dm_build_1554.dm_build_1548 != nil {
		dm_build_1558 = dm_build_1554.dm_build_1548.dm_build_1608(dm_build_1555, dm_build_1556-dm_build_1557)
		if dm_build_1554.dm_build_1548.dm_build_1603 == 0 {
			dm_build_1554.dm_build_1590()
		}
		dm_build_1557 += dm_build_1558
		dm_build_1554.dm_build_1549 -= dm_build_1558
	}
	return dm_build_1557
}

func (dm_build_1560 *Dm_build_1546) Dm_build_1559(dm_build_1561 []byte, dm_build_1562 int, dm_build_1563 int) int {
	var dm_build_1564 = 0
	var dm_build_1565 = 0
	for dm_build_1564 < dm_build_1563 && dm_build_1560.dm_build_1548 != nil {
		dm_build_1565 = dm_build_1560.dm_build_1548.dm_build_1612(dm_build_1561, dm_build_1562, dm_build_1563-dm_build_1564)
		if dm_build_1560.dm_build_1548.dm_build_1603 == 0 {
			dm_build_1560.dm_build_1590()
		}
		dm_build_1564 += dm_build_1565
		dm_build_1560.dm_build_1549 -= dm_build_1565
		dm_build_1562 += dm_build_1565
	}
	return dm_build_1564
}

func (dm_build_1567 *Dm_build_1546) Dm_build_1566(dm_build_1568 io.Writer, dm_build_1569 int) int {
	var dm_build_1570 = 0
	var dm_build_1571 = 0
	for dm_build_1570 < dm_build_1569 && dm_build_1567.dm_build_1548 != nil {
		dm_build_1571 = dm_build_1567.dm_build_1548.dm_build_1617(dm_build_1568, dm_build_1569-dm_build_1570)
		if dm_build_1567.dm_build_1548.dm_build_1603 == 0 {
			dm_build_1567.dm_build_1590()
		}
		dm_build_1570 += dm_build_1571
		dm_build_1567.dm_build_1549 -= dm_build_1571
	}
	return dm_build_1570
}

func (dm_build_1573 *Dm_build_1546) Dm_build_1572(dm_build_1574 []byte, dm_build_1575 int, dm_build_1576 int) {
	if dm_build_1576 == 0 {
		return
	}
	var dm_build_1577 = dm_build_1604(dm_build_1574, dm_build_1575, dm_build_1576)
	if dm_build_1573.dm_build_1548 == nil {
		dm_build_1573.dm_build_1548 = dm_build_1577
	} else {
		dm_build_1573.dm_build_1547.PushBack(dm_build_1577)
	}
	dm_build_1573.dm_build_1549 += dm_build_1576
}

func (dm_build_1579 *Dm_build_1546) dm_build_1578(dm_build_1580 int) byte {
	var dm_build_1581 = dm_build_1580
	var dm_build_1582 = dm_build_1579.dm_build_1548
	for dm_build_1581 > 0 && dm_build_1582 != nil {
		if dm_build_1582.dm_build_1603 == 0 {
			continue
		}
		if dm_build_1581 > dm_build_1582.dm_build_1603-1 {
			dm_build_1581 -= dm_build_1582.dm_build_1603
			dm_build_1582 = dm_build_1579.dm_build_1547.Front().Value.(*dm_build_1600)
		} else {
			break
		}
	}
	return dm_build_1582.dm_build_1621(dm_build_1581)
}
func (dm_build_1584 *Dm_build_1546) Dm_build_1583(dm_build_1585 *Dm_build_1546) {
	if dm_build_1585.dm_build_1549 == 0 {
		return
	}
	var dm_build_1586 = dm_build_1585.dm_build_1548
	for dm_build_1586 != nil {
		dm_build_1584.dm_build_1587(dm_build_1586)
		dm_build_1585.dm_build_1590()
		dm_build_1586 = dm_build_1585.dm_build_1548
	}
	dm_build_1585.dm_build_1549 = 0
}
func (dm_build_1588 *Dm_build_1546) dm_build_1587(dm_build_1589 *dm_build_1600) {
	if dm_build_1589.dm_build_1603 == 0 {
		return
	}
	if dm_build_1588.dm_build_1548 == nil {
		dm_build_1588.dm_build_1548 = dm_build_1589
	} else {
		dm_build_1588.dm_build_1547.PushBack(dm_build_1589)
	}
	dm_build_1588.dm_build_1549 += dm_build_1589.dm_build_1603
}

func (dm_build_1591 *Dm_build_1546) dm_build_1590() {
	var dm_build_1592 = dm_build_1591.dm_build_1547.Front()
	if dm_build_1592 == nil {
		dm_build_1591.dm_build_1548 = nil
	} else {
		dm_build_1591.dm_build_1548 = dm_build_1592.Value.(*dm_build_1600)
		dm_build_1591.dm_build_1547.Remove(dm_build_1592)
	}
}

func (dm_build_1594 *Dm_build_1546) Dm_build_1593() []byte {
	var dm_build_1595 = make([]byte, dm_build_1594.dm_build_1549)
	var dm_build_1596 = dm_build_1594.dm_build_1548
	var dm_build_1597 = 0
	var dm_build_1598 = len(dm_build_1595)
	var dm_build_1599 = 0
	for dm_build_1596 != nil {
		if dm_build_1596.dm_build_1603 > 0 {
			if dm_build_1598 > dm_build_1596.dm_build_1603 {
				dm_build_1599 = dm_build_1596.dm_build_1603
			} else {
				dm_build_1599 = dm_build_1598
			}
			copy(dm_build_1595[dm_build_1597:dm_build_1597+dm_build_1599], dm_build_1596.dm_build_1601[dm_build_1596.dm_build_1602:dm_build_1596.dm_build_1602+dm_build_1599])
			dm_build_1597 += dm_build_1599
			dm_build_1598 -= dm_build_1599
		}
		if dm_build_1594.dm_build_1547.Front() == nil {
			dm_build_1596 = nil
		} else {
			dm_build_1596 = dm_build_1594.dm_build_1547.Front().Value.(*dm_build_1600)
		}
	}
	return dm_build_1595
}

type dm_build_1600 struct {
	dm_build_1601 []byte
	dm_build_1602 int
	dm_build_1603 int
}

func dm_build_1604(dm_build_1605 []byte, dm_build_1606 int, dm_build_1607 int) *dm_build_1600 {
	return &dm_build_1600{
		dm_build_1605,
		dm_build_1606,
		dm_build_1607,
	}
}

func (dm_build_1609 *dm_build_1600) dm_build_1608(dm_build_1610 *Dm_build_0, dm_build_1611 int) int {
	if dm_build_1609.dm_build_1603 <= dm_build_1611 {
		dm_build_1611 = dm_build_1609.dm_build_1603
	}
	dm_build_1610.Dm_build_83(dm_build_1609.dm_build_1601[dm_build_1609.dm_build_1602 : dm_build_1609.dm_build_1602+dm_build_1611])
	dm_build_1609.dm_build_1602 += dm_build_1611
	dm_build_1609.dm_build_1603 -= dm_build_1611
	return dm_build_1611
}

func (dm_build_1613 *dm_build_1600) dm_build_1612(dm_build_1614 []byte, dm_build_1615 int, dm_build_1616 int) int {
	if dm_build_1613.dm_build_1603 <= dm_build_1616 {
		dm_build_1616 = dm_build_1613.dm_build_1603
	}
	copy(dm_build_1614[dm_build_1615:dm_build_1615+dm_build_1616], dm_build_1613.dm_build_1601[dm_build_1613.dm_build_1602:dm_build_1613.dm_build_1602+dm_build_1616])
	dm_build_1613.dm_build_1602 += dm_build_1616
	dm_build_1613.dm_build_1603 -= dm_build_1616
	return dm_build_1616
}

func (dm_build_1618 *dm_build_1600) dm_build_1617(dm_build_1619 io.Writer, dm_build_1620 int) int {
	if dm_build_1618.dm_build_1603 <= dm_build_1620 {
		dm_build_1620 = dm_build_1618.dm_build_1603
	}
	dm_build_1619.Write(dm_build_1618.dm_build_1601[dm_build_1618.dm_build_1602 : dm_build_1618.dm_build_1602+dm_build_1620])
	dm_build_1618.dm_build_1602 += dm_build_1620
	dm_build_1618.dm_build_1603 -= dm_build_1620
	return dm_build_1620
}
func (dm_build_1622 *dm_build_1600) dm_build_1621(dm_build_1623 int) byte {
	return dm_build_1622.dm_build_1601[dm_build_1622.dm_build_1602+dm_build_1623]
}
