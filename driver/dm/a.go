/*
 * Copyright (c) 2000-2018, 达梦数据库有限公司.
 * All rights reserved.
 */
package dm

import (
	"bytes"
	"context"
	"crypto/tls"
	"fmt"
	"github.com/team-ide/go-driver/driver/dm/security"
	"net"
	"strconv"
	"time"
	"unicode/utf8"
)

const (
	Dm_build_334 = 8192
	Dm_build_335 = 2 * time.Second
)

type dm_build_336 struct {
	dm_build_337 net.Conn
	dm_build_338 *tls.Conn
	dm_build_339 *Dm_build_0
	dm_build_340 *DmConnection
	dm_build_341 security.Cipher
	dm_build_342 bool
	dm_build_343 bool
	dm_build_344 *security.DhKey

	dm_build_345 bool
	dm_build_346 string
	dm_build_347 bool
}

func dm_build_348(dm_build_349 context.Context, dm_build_350 *DmConnection) (*dm_build_336, error) {
	var dm_build_351 net.Conn
	var dm_build_352 error

	dialsLock.RLock()
	dm_build_353, dm_build_354 := dials[dm_build_350.dmConnector.dialName]
	dialsLock.RUnlock()
	if dm_build_354 {
		dm_build_351, dm_build_352 = dm_build_353(dm_build_349, dm_build_350.dmConnector.host+":"+strconv.Itoa(int(dm_build_350.dmConnector.port)))
	} else {
		dm_build_351, dm_build_352 = dm_build_356(dm_build_350.dmConnector.host+":"+strconv.Itoa(int(dm_build_350.dmConnector.port)), time.Duration(dm_build_350.dmConnector.socketTimeout)*time.Second)
	}
	if dm_build_352 != nil {
		return nil, dm_build_352
	}

	dm_build_355 := dm_build_336{}
	dm_build_355.dm_build_337 = dm_build_351
	dm_build_355.dm_build_339 = Dm_build_3(Dm_build_629)
	dm_build_355.dm_build_340 = dm_build_350
	dm_build_355.dm_build_342 = false
	dm_build_355.dm_build_343 = false
	dm_build_355.dm_build_345 = false
	dm_build_355.dm_build_346 = ""
	dm_build_355.dm_build_347 = false
	dm_build_350.Access = &dm_build_355

	return &dm_build_355, nil
}

func dm_build_356(dm_build_357 string, dm_build_358 time.Duration) (net.Conn, error) {
	dm_build_359, dm_build_360 := net.DialTimeout("tcp", dm_build_357, dm_build_358)
	if dm_build_360 != nil {
		return &net.TCPConn{}, ECGO_COMMUNITION_ERROR.addDetail("\tdial address: " + dm_build_357).throw()
	}

	if tcpConn, ok := dm_build_359.(*net.TCPConn); ok {
		tcpConn.SetKeepAlive(true)
		tcpConn.SetKeepAlivePeriod(Dm_build_335)
		tcpConn.SetNoDelay(true)

	}
	return dm_build_359, nil
}

func (dm_build_362 *dm_build_336) dm_build_361(dm_build_363 dm_build_750) bool {
	var dm_build_364 = dm_build_362.dm_build_340.dmConnector.compress
	if dm_build_363.dm_build_765() == Dm_build_657 || dm_build_364 == Dm_build_706 {
		return false
	}

	if dm_build_364 == Dm_build_704 {
		return true
	} else if dm_build_364 == Dm_build_705 {
		return !dm_build_362.dm_build_340.Local && dm_build_363.dm_build_763() > Dm_build_703
	}

	return false
}

func (dm_build_366 *dm_build_336) dm_build_365(dm_build_367 dm_build_750) bool {
	var dm_build_368 = dm_build_366.dm_build_340.dmConnector.compress
	if dm_build_367.dm_build_765() == Dm_build_657 || dm_build_368 == Dm_build_706 {
		return false
	}

	if dm_build_368 == Dm_build_704 {
		return true
	} else if dm_build_368 == Dm_build_705 {
		return dm_build_366.dm_build_339.Dm_build_267(Dm_build_665) == 1
	}

	return false
}

func (dm_build_370 *dm_build_336) dm_build_369(dm_build_371 dm_build_750) (err error) {
	defer func() {
		if p := recover(); p != nil {
			if _, ok := p.(string); ok {
				err = ECGO_COMMUNITION_ERROR.addDetail("\t" + p.(string)).throw()
			} else {
				err = fmt.Errorf("internal error: %v", p)
			}
		}
	}()

	dm_build_373 := dm_build_371.dm_build_763()

	if dm_build_373 > 0 {

		if dm_build_370.dm_build_361(dm_build_371) {
			var retBytes, err = Compress(dm_build_370.dm_build_339, Dm_build_658, int(dm_build_373), int(dm_build_370.dm_build_340.dmConnector.compressID))
			if err != nil {
				return err
			}

			dm_build_370.dm_build_339.Dm_build_14(Dm_build_658)

			dm_build_370.dm_build_339.Dm_build_55(dm_build_373)

			dm_build_370.dm_build_339.Dm_build_83(retBytes)

			dm_build_371.dm_build_764(int32(len(retBytes)) + ULINT_SIZE)

			dm_build_370.dm_build_339.Dm_build_187(Dm_build_665, 1)
		}

		if dm_build_370.dm_build_343 {
			dm_build_373 = dm_build_371.dm_build_763()
			var retBytes = dm_build_370.dm_build_341.Encrypt(dm_build_370.dm_build_339.Dm_build_294(Dm_build_658, int(dm_build_373)), true)

			dm_build_370.dm_build_339.Dm_build_14(Dm_build_658)

			dm_build_370.dm_build_339.Dm_build_83(retBytes)

			dm_build_371.dm_build_764(int32(len(retBytes)))
		}
	}

	if dm_build_370.dm_build_339.Dm_build_12() > Dm_build_630 {
		return ECGO_MSG_TOO_LONG.throw()
	}

	dm_build_371.dm_build_759()
	if dm_build_370.dm_build_612(dm_build_371) {
		if dm_build_370.dm_build_338 != nil {
			dm_build_370.dm_build_339.Dm_build_17(0)
			if _, err := dm_build_370.dm_build_339.Dm_build_36(dm_build_370.dm_build_338); err != nil {
				return err
			}
		}
	} else {
		dm_build_370.dm_build_339.Dm_build_17(0)
		if _, err := dm_build_370.dm_build_339.Dm_build_36(dm_build_370.dm_build_337); err != nil {
			return err
		}
	}
	return nil
}

func (dm_build_375 *dm_build_336) dm_build_374(dm_build_376 dm_build_750) (err error) {
	defer func() {
		if p := recover(); p != nil {
			if _, ok := p.(string); ok {
				err = ECGO_COMMUNITION_ERROR.addDetail("\t" + p.(string)).throw()
			} else {
				err = fmt.Errorf("internal error: %v", p)
			}
		}
	}()

	dm_build_378 := int32(0)
	if dm_build_375.dm_build_612(dm_build_376) {
		if dm_build_375.dm_build_338 != nil {
			dm_build_375.dm_build_339.Dm_build_14(0)
			if _, err := dm_build_375.dm_build_339.Dm_build_30(dm_build_375.dm_build_338, Dm_build_658); err != nil {
				return err
			}

			dm_build_378 = dm_build_376.dm_build_763()
			if dm_build_378 > 0 {
				if _, err := dm_build_375.dm_build_339.Dm_build_30(dm_build_375.dm_build_338, int(dm_build_378)); err != nil {
					return err
				}
			}
		}
	} else {

		dm_build_375.dm_build_339.Dm_build_14(0)
		if _, err := dm_build_375.dm_build_339.Dm_build_30(dm_build_375.dm_build_337, Dm_build_658); err != nil {
			return err
		}
		dm_build_378 = dm_build_376.dm_build_763()

		if dm_build_378 > 0 {
			if _, err := dm_build_375.dm_build_339.Dm_build_30(dm_build_375.dm_build_337, int(dm_build_378)); err != nil {
				return err
			}
		}
	}

	dm_build_376.dm_build_760()

	dm_build_378 = dm_build_376.dm_build_763()
	if dm_build_378 <= 0 {
		return nil
	}

	if dm_build_375.dm_build_343 {
		ebytes := dm_build_375.dm_build_339.Dm_build_294(Dm_build_658, int(dm_build_378))
		bytes, err := dm_build_375.dm_build_341.Decrypt(ebytes, true)
		if err != nil {
			return err
		}
		dm_build_375.dm_build_339.Dm_build_14(Dm_build_658)
		dm_build_375.dm_build_339.Dm_build_83(bytes)
		dm_build_376.dm_build_764(int32(len(bytes)))
	}

	if dm_build_375.dm_build_365(dm_build_376) {

		dm_build_378 = dm_build_376.dm_build_763()
		cbytes := dm_build_375.dm_build_339.Dm_build_294(Dm_build_658+ULINT_SIZE, int(dm_build_378-ULINT_SIZE))
		bytes, err := UnCompress(cbytes, int(dm_build_375.dm_build_340.dmConnector.compressID))
		if err != nil {
			return err
		}
		dm_build_375.dm_build_339.Dm_build_14(Dm_build_658)
		dm_build_375.dm_build_339.Dm_build_83(bytes)
		dm_build_376.dm_build_764(int32(len(bytes)))
	}
	return nil
}

func (dm_build_380 *dm_build_336) dm_build_379(dm_build_381 dm_build_750) (dm_build_382 interface{}, dm_build_383 error) {
	if dm_build_380.dm_build_347 {
		return nil, ECGO_CONNECTION_CLOSED.throw()
	}
	dm_build_384 := dm_build_380.dm_build_340
	dm_build_384.mu.Lock()
	defer dm_build_384.mu.Unlock()
	dm_build_383 = dm_build_381.dm_build_754(dm_build_381)
	if dm_build_383 != nil {
		return nil, dm_build_383
	}

	dm_build_383 = dm_build_380.dm_build_369(dm_build_381)
	if dm_build_383 != nil {
		return nil, dm_build_383
	}

	dm_build_383 = dm_build_380.dm_build_374(dm_build_381)
	if dm_build_383 != nil {
		return nil, dm_build_383
	}

	return dm_build_381.dm_build_758(dm_build_381)
}

func (dm_build_386 *dm_build_336) dm_build_385() (*dm_build_1207, error) {

	Dm_build_387 := dm_build_1213(dm_build_386)
	_, dm_build_388 := dm_build_386.dm_build_379(Dm_build_387)
	if dm_build_388 != nil {
		return nil, dm_build_388
	}

	return Dm_build_387, nil
}

func (dm_build_390 *dm_build_336) dm_build_389() error {

	dm_build_391 := dm_build_1074(dm_build_390)
	_, dm_build_392 := dm_build_390.dm_build_379(dm_build_391)
	if dm_build_392 != nil {
		return dm_build_392
	}

	return nil
}

func (dm_build_394 *dm_build_336) dm_build_393() error {

	var dm_build_395 *dm_build_1207
	var err error
	if dm_build_395, err = dm_build_394.dm_build_385(); err != nil {
		return err
	}

	if dm_build_394.dm_build_340.sslEncrypt == 2 {
		if err = dm_build_394.dm_build_608(false); err != nil {
			return ECGO_INIT_SSL_FAILED.addDetail("\n" + err.Error()).throw()
		}
	} else if dm_build_394.dm_build_340.sslEncrypt == 1 {
		if err = dm_build_394.dm_build_608(true); err != nil {
			return ECGO_INIT_SSL_FAILED.addDetail("\n" + err.Error()).throw()
		}
	}

	if dm_build_394.dm_build_343 || dm_build_394.dm_build_342 {
		k, err := dm_build_394.dm_build_598()
		if err != nil {
			return err
		}
		sessionKey := security.ComputeSessionKey(k, dm_build_395.Dm_build_1211)
		encryptType := dm_build_395.dm_build_1209
		hashType := int(dm_build_395.Dm_build_1210)
		if encryptType == -1 {
			encryptType = security.DES_CFB
		}
		if hashType == -1 {
			hashType = security.MD5
		}
		err = dm_build_394.dm_build_601(encryptType, sessionKey, dm_build_394.dm_build_340.dmConnector.cipherPath, hashType)
		if err != nil {
			return err
		}
	}

	if err := dm_build_394.dm_build_389(); err != nil {
		return err
	}
	return nil
}

func (dm_build_398 *dm_build_336) Dm_build_397(dm_build_399 *DmStatement) error {
	dm_build_400 := dm_build_1236(dm_build_398, dm_build_399)
	_, dm_build_401 := dm_build_398.dm_build_379(dm_build_400)
	if dm_build_401 != nil {
		return dm_build_401
	}

	return nil
}

func (dm_build_403 *dm_build_336) Dm_build_402(dm_build_404 int32) error {
	dm_build_405 := dm_build_1246(dm_build_403, dm_build_404)
	_, dm_build_406 := dm_build_403.dm_build_379(dm_build_405)
	if dm_build_406 != nil {
		return dm_build_406
	}

	return nil
}

func (dm_build_408 *dm_build_336) Dm_build_407(dm_build_409 *DmStatement, dm_build_410 bool, dm_build_411 int16) (*execRetInfo, error) {
	dm_build_412 := dm_build_1113(dm_build_408, dm_build_409, dm_build_410, dm_build_411)
	dm_build_413, dm_build_414 := dm_build_408.dm_build_379(dm_build_412)
	if dm_build_414 != nil {
		return nil, dm_build_414
	}
	return dm_build_413.(*execRetInfo), nil
}

func (dm_build_416 *dm_build_336) Dm_build_415(dm_build_417 *DmStatement, dm_build_418 int16) (*execRetInfo, error) {
	return dm_build_416.Dm_build_407(dm_build_417, false, Dm_build_710)
}

func (dm_build_420 *dm_build_336) Dm_build_419(dm_build_421 *DmStatement, dm_build_422 []OptParameter) (*execRetInfo, error) {
	dm_build_423, dm_build_424 := dm_build_420.dm_build_379(dm_build_853(dm_build_420, dm_build_421, dm_build_422))
	if dm_build_424 != nil {
		return nil, dm_build_424
	}

	return dm_build_423.(*execRetInfo), nil
}

func (dm_build_426 *dm_build_336) Dm_build_425(dm_build_427 *DmStatement, dm_build_428 int16) (*execRetInfo, error) {
	return dm_build_426.Dm_build_407(dm_build_427, true, dm_build_428)
}

func (dm_build_430 *dm_build_336) Dm_build_429(dm_build_431 *DmStatement, dm_build_432 [][]interface{}) (*execRetInfo, error) {
	dm_build_433 := dm_build_885(dm_build_430, dm_build_431, dm_build_432)
	dm_build_434, dm_build_435 := dm_build_430.dm_build_379(dm_build_433)
	if dm_build_435 != nil {
		return nil, dm_build_435
	}
	return dm_build_434.(*execRetInfo), nil
}

func (dm_build_437 *dm_build_336) Dm_build_436(dm_build_438 *DmStatement, dm_build_439 [][]interface{}, dm_build_440 bool) (*execRetInfo, error) {
	var dm_build_441, dm_build_442 = 0, 0
	var dm_build_443 = len(dm_build_439)
	var dm_build_444 [][]interface{}
	var dm_build_445 = NewExceInfo()
	dm_build_445.updateCounts = make([]int64, dm_build_443)
	var dm_build_446 = false
	for dm_build_441 < dm_build_443 {
		for dm_build_442 = dm_build_441; dm_build_442 < dm_build_443; dm_build_442++ {
			paramData := dm_build_439[dm_build_442]
			bindData := make([]interface{}, dm_build_438.paramCount)
			dm_build_446 = false
			for icol := 0; icol < int(dm_build_438.paramCount); icol++ {
				if dm_build_438.bindParams[icol].ioType == IO_TYPE_OUT {
					continue
				}
				if dm_build_437.dm_build_581(bindData, paramData, icol) {
					dm_build_446 = true
					break
				}
			}

			if dm_build_446 {
				break
			}
			dm_build_444 = append(dm_build_444, bindData)
		}

		if dm_build_442 != dm_build_441 {
			tmpExecInfo, err := dm_build_437.Dm_build_429(dm_build_438, dm_build_444)
			if err != nil {
				return nil, err
			}
			dm_build_444 = dm_build_444[0:0]
			dm_build_445.union(tmpExecInfo, dm_build_441, dm_build_442-dm_build_441)
		}

		if dm_build_442 < dm_build_443 {
			tmpExecInfo, err := dm_build_437.Dm_build_455(dm_build_438, dm_build_439[dm_build_442], dm_build_440)
			if err != nil {
				return nil, err
			}

			dm_build_440 = true
			dm_build_445.union(tmpExecInfo, dm_build_442, 1)
		}

		dm_build_441 = dm_build_442 + 1
	}
	for _, i := range dm_build_445.updateCounts {
		if i > 0 {
			dm_build_445.updateCount += i
		}
	}
	return dm_build_445, nil
}

func (dm_build_448 *dm_build_336) dm_build_447(dm_build_449 *DmStatement, dm_build_450 []parameter) error {
	if !dm_build_449.prepared {
		retInfo, err := dm_build_448.Dm_build_407(dm_build_449, false, Dm_build_710)
		if err != nil {
			return nil
		}
		dm_build_449.serverParams = retInfo.serverParams
		dm_build_449.paramCount = int32(len(dm_build_449.serverParams))
		dm_build_449.prepared = true
	}

	dm_build_451 := dm_build_1102(dm_build_448, dm_build_449, dm_build_449.bindParams)
	dm_build_452, err := dm_build_448.dm_build_379(dm_build_451)
	if err != nil {
		return nil
	}
	retInfo := dm_build_452.(*execRetInfo)
	if retInfo.serverParams != nil && len(retInfo.serverParams) > 0 {
		dm_build_449.serverParams = retInfo.serverParams
		dm_build_449.paramCount = int32(len(dm_build_449.serverParams))
	}
	dm_build_449.preExec = true
	return nil
}

func (dm_build_456 *dm_build_336) Dm_build_455(dm_build_457 *DmStatement, dm_build_458 []interface{}, dm_build_459 bool) (*execRetInfo, error) {

	var dm_build_460 = make([]interface{}, dm_build_457.paramCount)
	for icol := 0; icol < int(dm_build_457.paramCount); icol++ {
		if dm_build_457.bindParams[icol].ioType == IO_TYPE_OUT {
			continue
		}
		if dm_build_456.dm_build_581(dm_build_460, dm_build_458, icol) {

			if !dm_build_459 {
				dm_build_456.dm_build_447(dm_build_457, dm_build_457.bindParams)

				dm_build_459 = true
			}

			dm_build_456.dm_build_587(dm_build_457, dm_build_457.bindParams[icol], icol, dm_build_458[icol].(iOffRowBinder))
			dm_build_460[icol] = ParamDataEnum_OFF_ROW
		}
	}

	var dm_build_461 = make([][]interface{}, 1, 1)
	dm_build_461[0] = dm_build_460

	dm_build_462 := dm_build_885(dm_build_456, dm_build_457, dm_build_461)
	dm_build_463, dm_build_464 := dm_build_456.dm_build_379(dm_build_462)
	if dm_build_464 != nil {
		return nil, dm_build_464
	}
	return dm_build_463.(*execRetInfo), nil
}

func (dm_build_466 *dm_build_336) Dm_build_465(dm_build_467 *DmStatement, dm_build_468 int16) (*execRetInfo, error) {
	dm_build_469 := dm_build_1089(dm_build_466, dm_build_467, dm_build_468)

	dm_build_470, dm_build_471 := dm_build_466.dm_build_379(dm_build_469)
	if dm_build_471 != nil {
		return nil, dm_build_471
	}
	return dm_build_470.(*execRetInfo), nil
}

func (dm_build_473 *dm_build_336) Dm_build_472(dm_build_474 *innerRows, dm_build_475 int64) (*execRetInfo, error) {
	dm_build_476 := dm_build_992(dm_build_473, dm_build_474, dm_build_475, INT64_MAX)
	dm_build_477, dm_build_478 := dm_build_473.dm_build_379(dm_build_476)
	if dm_build_478 != nil {
		return nil, dm_build_478
	}
	return dm_build_477.(*execRetInfo), nil
}

func (dm_build_480 *dm_build_336) Commit() error {
	dm_build_481 := dm_build_838(dm_build_480)
	_, dm_build_482 := dm_build_480.dm_build_379(dm_build_481)
	if dm_build_482 != nil {
		return dm_build_482
	}

	return nil
}

func (dm_build_484 *dm_build_336) Rollback() error {
	dm_build_485 := dm_build_1151(dm_build_484)
	_, dm_build_486 := dm_build_484.dm_build_379(dm_build_485)
	if dm_build_486 != nil {
		return dm_build_486
	}

	return nil
}

func (dm_build_488 *dm_build_336) Dm_build_487(dm_build_489 *DmConnection) error {
	dm_build_490 := dm_build_1156(dm_build_488, dm_build_489.IsoLevel)
	_, dm_build_491 := dm_build_488.dm_build_379(dm_build_490)
	if dm_build_491 != nil {
		return dm_build_491
	}

	return nil
}

func (dm_build_493 *dm_build_336) Dm_build_492(dm_build_494 *DmStatement, dm_build_495 string) error {
	dm_build_496 := dm_build_843(dm_build_493, dm_build_494, dm_build_495)
	_, dm_build_497 := dm_build_493.dm_build_379(dm_build_496)
	if dm_build_497 != nil {
		return dm_build_497
	}

	return nil
}

func (dm_build_499 *dm_build_336) Dm_build_498(dm_build_500 []uint32) ([]int64, error) {
	dm_build_501 := dm_build_1254(dm_build_499, dm_build_500)
	dm_build_502, dm_build_503 := dm_build_499.dm_build_379(dm_build_501)
	if dm_build_503 != nil {
		return nil, dm_build_503
	}
	return dm_build_502.([]int64), nil
}

func (dm_build_505 *dm_build_336) Close() error {
	if dm_build_505.dm_build_347 {
		return nil
	}

	dm_build_506 := dm_build_505.dm_build_337.Close()
	if dm_build_506 != nil {
		return dm_build_506
	}

	dm_build_505.dm_build_340 = nil
	dm_build_505.dm_build_347 = true
	return nil
}

func (dm_build_508 *dm_build_336) dm_build_507(dm_build_509 *lob) (int64, error) {
	dm_build_510 := dm_build_1025(dm_build_508, dm_build_509)
	dm_build_511, dm_build_512 := dm_build_508.dm_build_379(dm_build_510)
	if dm_build_512 != nil {
		return 0, dm_build_512
	}
	return dm_build_511.(int64), nil
}

func (dm_build_514 *dm_build_336) dm_build_513(dm_build_515 *lob, dm_build_516 int32, dm_build_517 int32) (*lobRetInfo, error) {
	dm_build_518 := dm_build_1010(dm_build_514, dm_build_515, int(dm_build_516), int(dm_build_517))
	dm_build_519, dm_build_520 := dm_build_514.dm_build_379(dm_build_518)
	if dm_build_520 != nil {
		return nil, dm_build_520
	}
	return dm_build_519.(*lobRetInfo), nil
}

func (dm_build_522 *dm_build_336) dm_build_521(dm_build_523 *DmBlob, dm_build_524 int32, dm_build_525 int32) ([]byte, error) {
	var dm_build_526 = make([]byte, dm_build_525)
	var dm_build_527 int32 = 0
	var dm_build_528 int32 = 0
	var dm_build_529 *lobRetInfo
	var dm_build_530 []byte
	var dm_build_531 error
	for dm_build_527 < dm_build_525 {
		dm_build_528 = dm_build_525 - dm_build_527
		if dm_build_528 > Dm_build_743 {
			dm_build_528 = Dm_build_743
		}
		dm_build_529, dm_build_531 = dm_build_522.dm_build_513(&dm_build_523.lob, dm_build_524+dm_build_527, dm_build_528)
		if dm_build_531 != nil {
			return nil, dm_build_531
		}
		dm_build_530 = dm_build_529.data
		if dm_build_530 == nil || len(dm_build_530) == 0 {
			break
		}
		Dm_build_1265.Dm_build_1321(dm_build_526, int(dm_build_527), dm_build_530, 0, len(dm_build_530))
		dm_build_527 += int32(len(dm_build_530))
		if dm_build_523.readOver {
			break
		}
	}
	return dm_build_526, nil
}

func (dm_build_533 *dm_build_336) dm_build_532(dm_build_534 *DmClob, dm_build_535 int32, dm_build_536 int32) (string, error) {
	var dm_build_537 bytes.Buffer
	var dm_build_538 int32 = 0
	var dm_build_539 int32 = 0
	var dm_build_540 *lobRetInfo
	var dm_build_541 []byte
	var dm_build_542 string
	var dm_build_543 error
	for dm_build_538 < dm_build_536 {
		dm_build_539 = dm_build_536 - dm_build_538
		if dm_build_539 > Dm_build_743/2 {
			dm_build_539 = Dm_build_743 / 2
		}
		dm_build_540, dm_build_543 = dm_build_533.dm_build_513(&dm_build_534.lob, dm_build_535+dm_build_538, dm_build_539)
		if dm_build_543 != nil {
			return "", dm_build_543
		}
		dm_build_541 = dm_build_540.data
		if dm_build_541 == nil || len(dm_build_541) == 0 {
			break
		}
		dm_build_542 = Dm_build_1265.Dm_build_1422(dm_build_541, 0, len(dm_build_541), dm_build_534.serverEncoding, dm_build_533.dm_build_340)

		dm_build_537.WriteString(dm_build_542)
		var strLen = dm_build_540.charLen
		if strLen == -1 {
			strLen = int64(utf8.RuneCountInString(dm_build_542))
		}
		dm_build_538 += int32(strLen)
		if dm_build_534.readOver {
			break
		}
	}
	return dm_build_537.String(), nil
}

func (dm_build_545 *dm_build_336) dm_build_544(dm_build_546 *DmClob, dm_build_547 int, dm_build_548 string, dm_build_549 string) (int, error) {
	var dm_build_550 = Dm_build_1265.Dm_build_1481(dm_build_548, dm_build_549, dm_build_545.dm_build_340)
	var dm_build_551 = 0
	var dm_build_552 = len(dm_build_550)
	var dm_build_553 = 0
	var dm_build_554 = 0
	var dm_build_555 = 0
	var dm_build_556 = dm_build_552/Dm_build_742 + 1
	var dm_build_557 byte = 0
	var dm_build_558 byte = 0x01
	var dm_build_559 byte = 0x02
	for i := 0; i < dm_build_556; i++ {
		dm_build_557 = 0
		if i == 0 {
			dm_build_557 |= dm_build_558
		}
		if i == dm_build_556-1 {
			dm_build_557 |= dm_build_559
		}
		dm_build_555 = dm_build_552 - dm_build_554
		if dm_build_555 > Dm_build_742 {
			dm_build_555 = Dm_build_742
		}

		setLobData := dm_build_1170(dm_build_545, &dm_build_546.lob, dm_build_557, dm_build_547, dm_build_550, dm_build_551, dm_build_555)
		ret, err := dm_build_545.dm_build_379(setLobData)
		if err != nil {
			return 0, err
		}
		tmp := ret.(int32)
		if err != nil {
			return -1, err
		}
		if tmp <= 0 {
			return dm_build_553, nil
		} else {
			dm_build_547 += int(tmp)
			dm_build_553 += int(tmp)
			dm_build_554 += dm_build_555
			dm_build_551 += dm_build_555
		}
	}
	return dm_build_553, nil
}

func (dm_build_561 *dm_build_336) dm_build_560(dm_build_562 *DmBlob, dm_build_563 int, dm_build_564 []byte) (int, error) {
	var dm_build_565 = 0
	var dm_build_566 = len(dm_build_564)
	var dm_build_567 = 0
	var dm_build_568 = 0
	var dm_build_569 = 0
	var dm_build_570 = dm_build_566/Dm_build_742 + 1
	var dm_build_571 byte = 0
	var dm_build_572 byte = 0x01
	var dm_build_573 byte = 0x02
	for i := 0; i < dm_build_570; i++ {
		dm_build_571 = 0
		if i == 0 {
			dm_build_571 |= dm_build_572
		}
		if i == dm_build_570-1 {
			dm_build_571 |= dm_build_573
		}
		dm_build_569 = dm_build_566 - dm_build_568
		if dm_build_569 > Dm_build_742 {
			dm_build_569 = Dm_build_742
		}

		setLobData := dm_build_1170(dm_build_561, &dm_build_562.lob, dm_build_571, dm_build_563, dm_build_564, dm_build_565, dm_build_569)
		ret, err := dm_build_561.dm_build_379(setLobData)
		if err != nil {
			return 0, err
		}
		tmp := ret.(int32)
		if tmp <= 0 {
			return dm_build_567, nil
		} else {
			dm_build_563 += int(tmp)
			dm_build_567 += int(tmp)
			dm_build_568 += dm_build_569
			dm_build_565 += dm_build_569
		}
	}
	return dm_build_567, nil
}

func (dm_build_575 *dm_build_336) dm_build_574(dm_build_576 *lob, dm_build_577 int) (int64, error) {
	dm_build_578 := dm_build_1036(dm_build_575, dm_build_576, dm_build_577)
	dm_build_579, dm_build_580 := dm_build_575.dm_build_379(dm_build_578)
	if dm_build_580 != nil {
		return dm_build_576.length, dm_build_580
	}
	return dm_build_579.(int64), nil
}

func (dm_build_582 *dm_build_336) dm_build_581(dm_build_583 []interface{}, dm_build_584 []interface{}, dm_build_585 int) bool {
	var dm_build_586 = false
	dm_build_583[dm_build_585] = dm_build_584[dm_build_585]

	if binder, ok := dm_build_584[dm_build_585].(iOffRowBinder); ok {
		dm_build_586 = true
		dm_build_583[dm_build_585] = make([]byte, 0)
		var lob lob
		if l, ok := binder.getObj().(DmBlob); ok {
			lob = l.lob
		} else if l, ok := binder.getObj().(DmClob); ok {
			lob = l.lob
		}
		if &lob != nil && lob.canOptimized(dm_build_582.dm_build_340) {
			dm_build_583[dm_build_585] = &lobCtl{lob.buildCtlData()}
			dm_build_586 = false
		}
	} else {
		dm_build_583[dm_build_585] = dm_build_584[dm_build_585]
	}
	return dm_build_586
}

func (dm_build_588 *dm_build_336) dm_build_587(dm_build_589 *DmStatement, dm_build_590 parameter, dm_build_591 int, dm_build_592 iOffRowBinder) error {
	var dm_build_593 = Dm_build_1550()
	dm_build_592.read(dm_build_593)
	var dm_build_594 = 0
	for !dm_build_592.isReadOver() || dm_build_593.Dm_build_1551() > 0 {
		if !dm_build_592.isReadOver() && dm_build_593.Dm_build_1551() < Dm_build_742 {
			dm_build_592.read(dm_build_593)
		}
		if dm_build_593.Dm_build_1551() > Dm_build_742 {
			dm_build_594 = Dm_build_742
		} else {
			dm_build_594 = dm_build_593.Dm_build_1551()
		}

		putData := dm_build_1141(dm_build_588, dm_build_589, int16(dm_build_591), dm_build_593, int32(dm_build_594))
		_, err := dm_build_588.dm_build_379(putData)
		if err != nil {
			return err
		}
	}
	return nil
}

func (dm_build_596 *dm_build_336) dm_build_595() ([]byte, error) {
	var dm_build_597 error
	if dm_build_596.dm_build_344 == nil {
		if dm_build_596.dm_build_344, dm_build_597 = security.NewClientKeyPair(); dm_build_597 != nil {
			return nil, dm_build_597
		}
	}
	return security.Bn2Bytes(dm_build_596.dm_build_344.GetY(), security.DH_KEY_LENGTH), nil
}

func (dm_build_599 *dm_build_336) dm_build_598() (*security.DhKey, error) {
	var dm_build_600 error
	if dm_build_599.dm_build_344 == nil {
		if dm_build_599.dm_build_344, dm_build_600 = security.NewClientKeyPair(); dm_build_600 != nil {
			return nil, dm_build_600
		}
	}
	return dm_build_599.dm_build_344, nil
}

func (dm_build_602 *dm_build_336) dm_build_601(dm_build_603 int, dm_build_604 []byte, dm_build_605 string, dm_build_606 int) (dm_build_607 error) {
	if dm_build_603 > 0 && dm_build_603 < security.MIN_EXTERNAL_CIPHER_ID && dm_build_604 != nil {
		dm_build_602.dm_build_341, dm_build_607 = security.NewSymmCipher(dm_build_603, dm_build_604)
	} else if dm_build_603 >= security.MIN_EXTERNAL_CIPHER_ID {
		if dm_build_602.dm_build_341, dm_build_607 = security.NewThirdPartCipher(dm_build_603, dm_build_604, dm_build_605, dm_build_606); dm_build_607 != nil {
			dm_build_607 = THIRD_PART_CIPHER_INIT_FAILED.addDetailln(dm_build_607.Error()).throw()
		}
	}
	return
}

func (dm_build_609 *dm_build_336) dm_build_608(dm_build_610 bool) (dm_build_611 error) {
	if dm_build_609.dm_build_338, dm_build_611 = security.NewTLSFromTCP(dm_build_609.dm_build_337, dm_build_609.dm_build_340.dmConnector.sslCertPath, dm_build_609.dm_build_340.dmConnector.sslKeyPath, dm_build_609.dm_build_340.dmConnector.user); dm_build_611 != nil {
		return
	}
	if !dm_build_610 {
		dm_build_609.dm_build_338 = nil
	}
	return
}

func (dm_build_613 *dm_build_336) dm_build_612(dm_build_614 dm_build_750) bool {
	return dm_build_614.dm_build_765() != Dm_build_657 && dm_build_613.dm_build_340.sslEncrypt == 1
}
