/*
 * Copyright (c) 2000-2018, 达梦数据库有限公司.
 * All rights reserved.
 */
package dm

import (
	"bytes"
	"golang.org/x/text/encoding"
	"golang.org/x/text/encoding/ianaindex"
	"golang.org/x/text/transform"
	"io"
	"io/ioutil"
	"math"
)

type dm_build_1264 struct{}

var Dm_build_1265 = &dm_build_1264{}

func (Dm_build_1267 *dm_build_1264) Dm_build_1266(dm_build_1268 []byte, dm_build_1269 int, dm_build_1270 byte) int {
	dm_build_1268[dm_build_1269] = dm_build_1270
	return 1
}

func (Dm_build_1272 *dm_build_1264) Dm_build_1271(dm_build_1273 []byte, dm_build_1274 int, dm_build_1275 int8) int {
	dm_build_1273[dm_build_1274] = byte(dm_build_1275)
	return 1
}

func (Dm_build_1277 *dm_build_1264) Dm_build_1276(dm_build_1278 []byte, dm_build_1279 int, dm_build_1280 int16) int {
	dm_build_1278[dm_build_1279] = byte(dm_build_1280)
	dm_build_1279++
	dm_build_1278[dm_build_1279] = byte(dm_build_1280 >> 8)
	return 2
}

func (Dm_build_1282 *dm_build_1264) Dm_build_1281(dm_build_1283 []byte, dm_build_1284 int, dm_build_1285 int32) int {
	dm_build_1283[dm_build_1284] = byte(dm_build_1285)
	dm_build_1284++
	dm_build_1283[dm_build_1284] = byte(dm_build_1285 >> 8)
	dm_build_1284++
	dm_build_1283[dm_build_1284] = byte(dm_build_1285 >> 16)
	dm_build_1284++
	dm_build_1283[dm_build_1284] = byte(dm_build_1285 >> 24)
	dm_build_1284++
	return 4
}

func (Dm_build_1287 *dm_build_1264) Dm_build_1286(dm_build_1288 []byte, dm_build_1289 int, dm_build_1290 int64) int {
	dm_build_1288[dm_build_1289] = byte(dm_build_1290)
	dm_build_1289++
	dm_build_1288[dm_build_1289] = byte(dm_build_1290 >> 8)
	dm_build_1289++
	dm_build_1288[dm_build_1289] = byte(dm_build_1290 >> 16)
	dm_build_1289++
	dm_build_1288[dm_build_1289] = byte(dm_build_1290 >> 24)
	dm_build_1289++
	dm_build_1288[dm_build_1289] = byte(dm_build_1290 >> 32)
	dm_build_1289++
	dm_build_1288[dm_build_1289] = byte(dm_build_1290 >> 40)
	dm_build_1289++
	dm_build_1288[dm_build_1289] = byte(dm_build_1290 >> 48)
	dm_build_1289++
	dm_build_1288[dm_build_1289] = byte(dm_build_1290 >> 56)
	return 8
}

func (Dm_build_1292 *dm_build_1264) Dm_build_1291(dm_build_1293 []byte, dm_build_1294 int, dm_build_1295 float32) int {
	return Dm_build_1292.Dm_build_1311(dm_build_1293, dm_build_1294, math.Float32bits(dm_build_1295))
}

func (Dm_build_1297 *dm_build_1264) Dm_build_1296(dm_build_1298 []byte, dm_build_1299 int, dm_build_1300 float64) int {
	return Dm_build_1297.Dm_build_1316(dm_build_1298, dm_build_1299, math.Float64bits(dm_build_1300))
}

func (Dm_build_1302 *dm_build_1264) Dm_build_1301(dm_build_1303 []byte, dm_build_1304 int, dm_build_1305 uint8) int {
	dm_build_1303[dm_build_1304] = byte(dm_build_1305)
	return 1
}

func (Dm_build_1307 *dm_build_1264) Dm_build_1306(dm_build_1308 []byte, dm_build_1309 int, dm_build_1310 uint16) int {
	dm_build_1308[dm_build_1309] = byte(dm_build_1310)
	dm_build_1309++
	dm_build_1308[dm_build_1309] = byte(dm_build_1310 >> 8)
	return 2
}

func (Dm_build_1312 *dm_build_1264) Dm_build_1311(dm_build_1313 []byte, dm_build_1314 int, dm_build_1315 uint32) int {
	dm_build_1313[dm_build_1314] = byte(dm_build_1315)
	dm_build_1314++
	dm_build_1313[dm_build_1314] = byte(dm_build_1315 >> 8)
	dm_build_1314++
	dm_build_1313[dm_build_1314] = byte(dm_build_1315 >> 16)
	dm_build_1314++
	dm_build_1313[dm_build_1314] = byte(dm_build_1315 >> 24)
	return 3
}

func (Dm_build_1317 *dm_build_1264) Dm_build_1316(dm_build_1318 []byte, dm_build_1319 int, dm_build_1320 uint64) int {
	dm_build_1318[dm_build_1319] = byte(dm_build_1320)
	dm_build_1319++
	dm_build_1318[dm_build_1319] = byte(dm_build_1320 >> 8)
	dm_build_1319++
	dm_build_1318[dm_build_1319] = byte(dm_build_1320 >> 16)
	dm_build_1319++
	dm_build_1318[dm_build_1319] = byte(dm_build_1320 >> 24)
	dm_build_1319++
	dm_build_1318[dm_build_1319] = byte(dm_build_1320 >> 32)
	dm_build_1319++
	dm_build_1318[dm_build_1319] = byte(dm_build_1320 >> 40)
	dm_build_1319++
	dm_build_1318[dm_build_1319] = byte(dm_build_1320 >> 48)
	dm_build_1319++
	dm_build_1318[dm_build_1319] = byte(dm_build_1320 >> 56)
	return 3
}

func (Dm_build_1322 *dm_build_1264) Dm_build_1321(dm_build_1323 []byte, dm_build_1324 int, dm_build_1325 []byte, dm_build_1326 int, dm_build_1327 int) int {
	copy(dm_build_1323[dm_build_1324:dm_build_1324+dm_build_1327], dm_build_1325[dm_build_1326:dm_build_1326+dm_build_1327])
	return dm_build_1327
}

func (Dm_build_1329 *dm_build_1264) Dm_build_1328(dm_build_1330 []byte, dm_build_1331 int, dm_build_1332 []byte, dm_build_1333 int, dm_build_1334 int) int {
	dm_build_1331 += Dm_build_1329.Dm_build_1311(dm_build_1330, dm_build_1331, uint32(dm_build_1334))
	return 4 + Dm_build_1329.Dm_build_1321(dm_build_1330, dm_build_1331, dm_build_1332, dm_build_1333, dm_build_1334)
}

func (Dm_build_1336 *dm_build_1264) Dm_build_1335(dm_build_1337 []byte, dm_build_1338 int, dm_build_1339 []byte, dm_build_1340 int, dm_build_1341 int) int {
	dm_build_1338 += Dm_build_1336.Dm_build_1306(dm_build_1337, dm_build_1338, uint16(dm_build_1341))
	return 2 + Dm_build_1336.Dm_build_1321(dm_build_1337, dm_build_1338, dm_build_1339, dm_build_1340, dm_build_1341)
}

func (Dm_build_1343 *dm_build_1264) Dm_build_1342(dm_build_1344 []byte, dm_build_1345 int, dm_build_1346 string, dm_build_1347 string, dm_build_1348 *DmConnection) int {
	dm_build_1349 := Dm_build_1343.Dm_build_1481(dm_build_1346, dm_build_1347, dm_build_1348)
	dm_build_1345 += Dm_build_1343.Dm_build_1311(dm_build_1344, dm_build_1345, uint32(len(dm_build_1349)))
	return 4 + Dm_build_1343.Dm_build_1321(dm_build_1344, dm_build_1345, dm_build_1349, 0, len(dm_build_1349))
}

func (Dm_build_1351 *dm_build_1264) Dm_build_1350(dm_build_1352 []byte, dm_build_1353 int, dm_build_1354 string, dm_build_1355 string, dm_build_1356 *DmConnection) int {
	dm_build_1357 := Dm_build_1351.Dm_build_1481(dm_build_1354, dm_build_1355, dm_build_1356)

	dm_build_1353 += Dm_build_1351.Dm_build_1306(dm_build_1352, dm_build_1353, uint16(len(dm_build_1357)))
	return 2 + Dm_build_1351.Dm_build_1321(dm_build_1352, dm_build_1353, dm_build_1357, 0, len(dm_build_1357))
}

func (Dm_build_1359 *dm_build_1264) Dm_build_1358(dm_build_1360 []byte, dm_build_1361 int) byte {
	return dm_build_1360[dm_build_1361]
}

func (Dm_build_1363 *dm_build_1264) Dm_build_1362(dm_build_1364 []byte, dm_build_1365 int) int16 {
	var dm_build_1366 int16
	dm_build_1366 = int16(dm_build_1364[dm_build_1365] & 0xff)
	dm_build_1365++
	dm_build_1366 |= int16(dm_build_1364[dm_build_1365]&0xff) << 8
	return dm_build_1366
}

func (Dm_build_1368 *dm_build_1264) Dm_build_1367(dm_build_1369 []byte, dm_build_1370 int) int32 {
	var dm_build_1371 int32
	dm_build_1371 = int32(dm_build_1369[dm_build_1370] & 0xff)
	dm_build_1370++
	dm_build_1371 |= int32(dm_build_1369[dm_build_1370]&0xff) << 8
	dm_build_1370++
	dm_build_1371 |= int32(dm_build_1369[dm_build_1370]&0xff) << 16
	dm_build_1370++
	dm_build_1371 |= int32(dm_build_1369[dm_build_1370]&0xff) << 24
	return dm_build_1371
}

func (Dm_build_1373 *dm_build_1264) Dm_build_1372(dm_build_1374 []byte, dm_build_1375 int) int64 {
	var dm_build_1376 int64
	dm_build_1376 = int64(dm_build_1374[dm_build_1375] & 0xff)
	dm_build_1375++
	dm_build_1376 |= int64(dm_build_1374[dm_build_1375]&0xff) << 8
	dm_build_1375++
	dm_build_1376 |= int64(dm_build_1374[dm_build_1375]&0xff) << 16
	dm_build_1375++
	dm_build_1376 |= int64(dm_build_1374[dm_build_1375]&0xff) << 24
	dm_build_1375++
	dm_build_1376 |= int64(dm_build_1374[dm_build_1375]&0xff) << 32
	dm_build_1375++
	dm_build_1376 |= int64(dm_build_1374[dm_build_1375]&0xff) << 40
	dm_build_1375++
	dm_build_1376 |= int64(dm_build_1374[dm_build_1375]&0xff) << 48
	dm_build_1375++
	dm_build_1376 |= int64(dm_build_1374[dm_build_1375]&0xff) << 56
	return dm_build_1376
}

func (Dm_build_1378 *dm_build_1264) Dm_build_1377(dm_build_1379 []byte, dm_build_1380 int) float32 {
	return math.Float32frombits(Dm_build_1378.Dm_build_1394(dm_build_1379, dm_build_1380))
}

func (Dm_build_1382 *dm_build_1264) Dm_build_1381(dm_build_1383 []byte, dm_build_1384 int) float64 {
	return math.Float64frombits(Dm_build_1382.Dm_build_1399(dm_build_1383, dm_build_1384))
}

func (Dm_build_1386 *dm_build_1264) Dm_build_1385(dm_build_1387 []byte, dm_build_1388 int) uint8 {
	return uint8(dm_build_1387[dm_build_1388] & 0xff)
}

func (Dm_build_1390 *dm_build_1264) Dm_build_1389(dm_build_1391 []byte, dm_build_1392 int) uint16 {
	var dm_build_1393 uint16
	dm_build_1393 = uint16(dm_build_1391[dm_build_1392] & 0xff)
	dm_build_1392++
	dm_build_1393 |= uint16(dm_build_1391[dm_build_1392]&0xff) << 8
	return dm_build_1393
}

func (Dm_build_1395 *dm_build_1264) Dm_build_1394(dm_build_1396 []byte, dm_build_1397 int) uint32 {
	var dm_build_1398 uint32
	dm_build_1398 = uint32(dm_build_1396[dm_build_1397] & 0xff)
	dm_build_1397++
	dm_build_1398 |= uint32(dm_build_1396[dm_build_1397]&0xff) << 8
	dm_build_1397++
	dm_build_1398 |= uint32(dm_build_1396[dm_build_1397]&0xff) << 16
	dm_build_1397++
	dm_build_1398 |= uint32(dm_build_1396[dm_build_1397]&0xff) << 24
	return dm_build_1398
}

func (Dm_build_1400 *dm_build_1264) Dm_build_1399(dm_build_1401 []byte, dm_build_1402 int) uint64 {
	var dm_build_1403 uint64
	dm_build_1403 = uint64(dm_build_1401[dm_build_1402] & 0xff)
	dm_build_1402++
	dm_build_1403 |= uint64(dm_build_1401[dm_build_1402]&0xff) << 8
	dm_build_1402++
	dm_build_1403 |= uint64(dm_build_1401[dm_build_1402]&0xff) << 16
	dm_build_1402++
	dm_build_1403 |= uint64(dm_build_1401[dm_build_1402]&0xff) << 24
	dm_build_1402++
	dm_build_1403 |= uint64(dm_build_1401[dm_build_1402]&0xff) << 32
	dm_build_1402++
	dm_build_1403 |= uint64(dm_build_1401[dm_build_1402]&0xff) << 40
	dm_build_1402++
	dm_build_1403 |= uint64(dm_build_1401[dm_build_1402]&0xff) << 48
	dm_build_1402++
	dm_build_1403 |= uint64(dm_build_1401[dm_build_1402]&0xff) << 56
	return dm_build_1403
}

func (Dm_build_1405 *dm_build_1264) Dm_build_1404(dm_build_1406 []byte, dm_build_1407 int) []byte {
	dm_build_1408 := Dm_build_1405.Dm_build_1394(dm_build_1406, dm_build_1407)

	dm_build_1409 := make([]byte, dm_build_1408)
	copy(dm_build_1409[:int(dm_build_1408)], dm_build_1406[dm_build_1407+4:dm_build_1407+4+int(dm_build_1408)])
	return dm_build_1409
}

func (Dm_build_1411 *dm_build_1264) Dm_build_1410(dm_build_1412 []byte, dm_build_1413 int) []byte {
	dm_build_1414 := Dm_build_1411.Dm_build_1389(dm_build_1412, dm_build_1413)

	dm_build_1415 := make([]byte, dm_build_1414)
	copy(dm_build_1415[:int(dm_build_1414)], dm_build_1412[dm_build_1413+2:dm_build_1413+2+int(dm_build_1414)])
	return dm_build_1415
}

func (Dm_build_1417 *dm_build_1264) Dm_build_1416(dm_build_1418 []byte, dm_build_1419 int, dm_build_1420 int) []byte {

	dm_build_1421 := make([]byte, dm_build_1420)
	copy(dm_build_1421[:dm_build_1420], dm_build_1418[dm_build_1419:dm_build_1419+dm_build_1420])
	return dm_build_1421
}

func (Dm_build_1423 *dm_build_1264) Dm_build_1422(dm_build_1424 []byte, dm_build_1425 int, dm_build_1426 int, dm_build_1427 string, dm_build_1428 *DmConnection) string {
	return Dm_build_1423.Dm_build_1517(dm_build_1424[dm_build_1425:dm_build_1425+dm_build_1426], dm_build_1427, dm_build_1428)
}

func (Dm_build_1430 *dm_build_1264) Dm_build_1429(dm_build_1431 []byte, dm_build_1432 int, dm_build_1433 string, dm_build_1434 *DmConnection) string {
	dm_build_1435 := Dm_build_1430.Dm_build_1394(dm_build_1431, dm_build_1432)
	dm_build_1432 += 4
	return Dm_build_1430.Dm_build_1422(dm_build_1431, dm_build_1432, int(dm_build_1435), dm_build_1433, dm_build_1434)
}

func (Dm_build_1437 *dm_build_1264) Dm_build_1436(dm_build_1438 []byte, dm_build_1439 int, dm_build_1440 string, dm_build_1441 *DmConnection) string {
	dm_build_1442 := Dm_build_1437.Dm_build_1389(dm_build_1438, dm_build_1439)
	dm_build_1439 += 2
	return Dm_build_1437.Dm_build_1422(dm_build_1438, dm_build_1439, int(dm_build_1442), dm_build_1440, dm_build_1441)
}

func (Dm_build_1444 *dm_build_1264) Dm_build_1443(dm_build_1445 byte) []byte {
	return []byte{dm_build_1445}
}

func (Dm_build_1447 *dm_build_1264) Dm_build_1446(dm_build_1448 int8) []byte {
	return []byte{byte(dm_build_1448)}
}

func (Dm_build_1450 *dm_build_1264) Dm_build_1449(dm_build_1451 int16) []byte {
	return []byte{byte(dm_build_1451), byte(dm_build_1451 >> 8)}
}

func (Dm_build_1453 *dm_build_1264) Dm_build_1452(dm_build_1454 int32) []byte {
	return []byte{byte(dm_build_1454), byte(dm_build_1454 >> 8), byte(dm_build_1454 >> 16), byte(dm_build_1454 >> 24)}
}

func (Dm_build_1456 *dm_build_1264) Dm_build_1455(dm_build_1457 int64) []byte {
	return []byte{byte(dm_build_1457), byte(dm_build_1457 >> 8), byte(dm_build_1457 >> 16), byte(dm_build_1457 >> 24), byte(dm_build_1457 >> 32),
		byte(dm_build_1457 >> 40), byte(dm_build_1457 >> 48), byte(dm_build_1457 >> 56)}
}

func (Dm_build_1459 *dm_build_1264) Dm_build_1458(dm_build_1460 float32) []byte {
	return Dm_build_1459.Dm_build_1470(math.Float32bits(dm_build_1460))
}

func (Dm_build_1462 *dm_build_1264) Dm_build_1461(dm_build_1463 float64) []byte {
	return Dm_build_1462.Dm_build_1473(math.Float64bits(dm_build_1463))
}

func (Dm_build_1465 *dm_build_1264) Dm_build_1464(dm_build_1466 uint8) []byte {
	return []byte{byte(dm_build_1466)}
}

func (Dm_build_1468 *dm_build_1264) Dm_build_1467(dm_build_1469 uint16) []byte {
	return []byte{byte(dm_build_1469), byte(dm_build_1469 >> 8)}
}

func (Dm_build_1471 *dm_build_1264) Dm_build_1470(dm_build_1472 uint32) []byte {
	return []byte{byte(dm_build_1472), byte(dm_build_1472 >> 8), byte(dm_build_1472 >> 16), byte(dm_build_1472 >> 24)}
}

func (Dm_build_1474 *dm_build_1264) Dm_build_1473(dm_build_1475 uint64) []byte {
	return []byte{byte(dm_build_1475), byte(dm_build_1475 >> 8), byte(dm_build_1475 >> 16), byte(dm_build_1475 >> 24), byte(dm_build_1475 >> 32), byte(dm_build_1475 >> 40), byte(dm_build_1475 >> 48), byte(dm_build_1475 >> 56)}
}

func (Dm_build_1477 *dm_build_1264) Dm_build_1476(dm_build_1478 []byte, dm_build_1479 string, dm_build_1480 *DmConnection) []byte {
	if dm_build_1479 == "UTF-8" {
		return dm_build_1478
	}

	if dm_build_1480 == nil {
		if e := dm_build_1522(dm_build_1479); e != nil {
			tmp, err := ioutil.ReadAll(
				transform.NewReader(bytes.NewReader(dm_build_1478), e.NewEncoder()),
			)
			if err != nil {
				panic("UTF8 To Charset error!")
			}

			return tmp
		}

		panic("Unsupported Charset!")
	}

	if dm_build_1480.encodeBuffer == nil {
		dm_build_1480.encodeBuffer = bytes.NewBuffer(nil)
		dm_build_1480.encode = dm_build_1522(dm_build_1480.getServerEncoding())
		dm_build_1480.transformReaderDst = make([]byte, 4096)
		dm_build_1480.transformReaderSrc = make([]byte, 4096)
	}

	if e := dm_build_1480.encode; e != nil {

		dm_build_1480.encodeBuffer.Reset()

		n, err := dm_build_1480.encodeBuffer.ReadFrom(
			Dm_build_1536(bytes.NewReader(dm_build_1478), e.NewEncoder(), dm_build_1480.transformReaderDst, dm_build_1480.transformReaderSrc),
		)
		if err != nil {
			panic("UTF8 To Charset error!")
		}
		var tmp = make([]byte, n)
		if _, err = dm_build_1480.encodeBuffer.Read(tmp); err != nil {
			panic("UTF8 To Charset error!")
		}
		return tmp
	}

	panic("Unsupported Charset!")
}

func (Dm_build_1482 *dm_build_1264) Dm_build_1481(dm_build_1483 string, dm_build_1484 string, dm_build_1485 *DmConnection) []byte {
	return Dm_build_1482.Dm_build_1476([]byte(dm_build_1483), dm_build_1484, dm_build_1485)
}

func (Dm_build_1487 *dm_build_1264) Dm_build_1486(dm_build_1488 []byte) byte {
	return Dm_build_1487.Dm_build_1358(dm_build_1488, 0)
}

func (Dm_build_1490 *dm_build_1264) Dm_build_1489(dm_build_1491 []byte) int16 {
	return Dm_build_1490.Dm_build_1362(dm_build_1491, 0)
}

func (Dm_build_1493 *dm_build_1264) Dm_build_1492(dm_build_1494 []byte) int32 {
	return Dm_build_1493.Dm_build_1367(dm_build_1494, 0)
}

func (Dm_build_1496 *dm_build_1264) Dm_build_1495(dm_build_1497 []byte) int64 {
	return Dm_build_1496.Dm_build_1372(dm_build_1497, 0)
}

func (Dm_build_1499 *dm_build_1264) Dm_build_1498(dm_build_1500 []byte) float32 {
	return Dm_build_1499.Dm_build_1377(dm_build_1500, 0)
}

func (Dm_build_1502 *dm_build_1264) Dm_build_1501(dm_build_1503 []byte) float64 {
	return Dm_build_1502.Dm_build_1381(dm_build_1503, 0)
}

func (Dm_build_1505 *dm_build_1264) Dm_build_1504(dm_build_1506 []byte) uint8 {
	return Dm_build_1505.Dm_build_1385(dm_build_1506, 0)
}

func (Dm_build_1508 *dm_build_1264) Dm_build_1507(dm_build_1509 []byte) uint16 {
	return Dm_build_1508.Dm_build_1389(dm_build_1509, 0)
}

func (Dm_build_1511 *dm_build_1264) Dm_build_1510(dm_build_1512 []byte) uint32 {
	return Dm_build_1511.Dm_build_1394(dm_build_1512, 0)
}

func (Dm_build_1514 *dm_build_1264) Dm_build_1513(dm_build_1515 []byte, dm_build_1516 string) []byte {
	if dm_build_1516 == "UTF-8" {
		return dm_build_1515
	}

	if e := dm_build_1522(dm_build_1516); e != nil {

		tmp, err := ioutil.ReadAll(
			transform.NewReader(bytes.NewReader(dm_build_1515), e.NewDecoder()),
		)
		if err != nil {

			panic("Charset To UTF8 error!")
		}

		return tmp
	}

	panic("Unsupported Charset!")

}

func (Dm_build_1518 *dm_build_1264) Dm_build_1517(dm_build_1519 []byte, dm_build_1520 string, dm_build_1521 *DmConnection) string {
	return string(Dm_build_1518.Dm_build_1513(dm_build_1519, dm_build_1520))
}

func dm_build_1522(dm_build_1523 string) encoding.Encoding {
	if e, err := ianaindex.MIB.Encoding(dm_build_1523); err == nil && e != nil {
		return e
	}
	return nil
}

type Dm_build_1524 struct {
	dm_build_1525 io.Reader
	dm_build_1526 transform.Transformer
	dm_build_1527 error

	dm_build_1528                []byte
	dm_build_1529, dm_build_1530 int

	dm_build_1531                []byte
	dm_build_1532, dm_build_1533 int

	dm_build_1534 bool
}

const dm_build_1535 = 4096

func Dm_build_1536(dm_build_1537 io.Reader, dm_build_1538 transform.Transformer, dm_build_1539 []byte, dm_build_1540 []byte) *Dm_build_1524 {
	dm_build_1538.Reset()
	return &Dm_build_1524{
		dm_build_1525: dm_build_1537,
		dm_build_1526: dm_build_1538,
		dm_build_1528: dm_build_1539,
		dm_build_1531: dm_build_1540,
	}
}

func (dm_build_1542 *Dm_build_1524) Read(dm_build_1543 []byte) (int, error) {
	dm_build_1544, dm_build_1545 := 0, error(nil)
	for {

		if dm_build_1542.dm_build_1529 != dm_build_1542.dm_build_1530 {
			dm_build_1544 = copy(dm_build_1543, dm_build_1542.dm_build_1528[dm_build_1542.dm_build_1529:dm_build_1542.dm_build_1530])
			dm_build_1542.dm_build_1529 += dm_build_1544
			if dm_build_1542.dm_build_1529 == dm_build_1542.dm_build_1530 && dm_build_1542.dm_build_1534 {
				return dm_build_1544, dm_build_1542.dm_build_1527
			}
			return dm_build_1544, nil
		} else if dm_build_1542.dm_build_1534 {
			return 0, dm_build_1542.dm_build_1527
		}

		if dm_build_1542.dm_build_1532 != dm_build_1542.dm_build_1533 || dm_build_1542.dm_build_1527 != nil {
			dm_build_1542.dm_build_1529 = 0
			dm_build_1542.dm_build_1530, dm_build_1544, dm_build_1545 = dm_build_1542.dm_build_1526.Transform(dm_build_1542.dm_build_1528, dm_build_1542.dm_build_1531[dm_build_1542.dm_build_1532:dm_build_1542.dm_build_1533], dm_build_1542.dm_build_1527 == io.EOF)
			dm_build_1542.dm_build_1532 += dm_build_1544

			switch {
			case dm_build_1545 == nil:
				if dm_build_1542.dm_build_1532 != dm_build_1542.dm_build_1533 {
					dm_build_1542.dm_build_1527 = nil
				}

				dm_build_1542.dm_build_1534 = dm_build_1542.dm_build_1527 != nil
				continue
			case dm_build_1545 == transform.ErrShortDst && (dm_build_1542.dm_build_1530 != 0 || dm_build_1544 != 0):

				continue
			case dm_build_1545 == transform.ErrShortSrc && dm_build_1542.dm_build_1533-dm_build_1542.dm_build_1532 != len(dm_build_1542.dm_build_1531) && dm_build_1542.dm_build_1527 == nil:

			default:
				dm_build_1542.dm_build_1534 = true

				if dm_build_1542.dm_build_1527 == nil || dm_build_1542.dm_build_1527 == io.EOF {
					dm_build_1542.dm_build_1527 = dm_build_1545
				}
				continue
			}
		}

		if dm_build_1542.dm_build_1532 != 0 {
			dm_build_1542.dm_build_1532, dm_build_1542.dm_build_1533 = 0, copy(dm_build_1542.dm_build_1531, dm_build_1542.dm_build_1531[dm_build_1542.dm_build_1532:dm_build_1542.dm_build_1533])
		}
		dm_build_1544, dm_build_1542.dm_build_1527 = dm_build_1542.dm_build_1525.Read(dm_build_1542.dm_build_1531[dm_build_1542.dm_build_1533:])
		dm_build_1542.dm_build_1533 += dm_build_1544
	}
}
