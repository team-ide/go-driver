/*
 * Copyright (c) 2000-2018, 达梦数据库有限公司.
 * All rights reserved.
 */
package dm

import (
	"io"
	"math"
)

type Dm_build_0 struct {
	dm_build_1 []byte
	dm_build_2 int
}

func Dm_build_3(dm_build_4 int) *Dm_build_0 {
	return &Dm_build_0{make([]byte, 0, dm_build_4), 0}
}

func Dm_build_5(dm_build_6 []byte) *Dm_build_0 {
	return &Dm_build_0{dm_build_6, 0}
}

func (dm_build_8 *Dm_build_0) dm_build_7(dm_build_9 int) *Dm_build_0 {

	dm_build_10 := len(dm_build_8.dm_build_1)
	dm_build_11 := cap(dm_build_8.dm_build_1)

	if dm_build_10+dm_build_9 <= dm_build_11 {
		dm_build_8.dm_build_1 = dm_build_8.dm_build_1[:dm_build_10+dm_build_9]
	} else {

		var calCap = int64(math.Max(float64(2*dm_build_11), float64(dm_build_9+dm_build_10)))

		nbuf := make([]byte, dm_build_9+dm_build_10, calCap)
		copy(nbuf, dm_build_8.dm_build_1)
		dm_build_8.dm_build_1 = nbuf
	}

	return dm_build_8
}

func (dm_build_13 *Dm_build_0) Dm_build_12() int {
	return len(dm_build_13.dm_build_1)
}

func (dm_build_15 *Dm_build_0) Dm_build_14(dm_build_16 int) *Dm_build_0 {
	for i := dm_build_16; i < len(dm_build_15.dm_build_1); i++ {
		dm_build_15.dm_build_1[i] = 0
	}
	dm_build_15.dm_build_1 = dm_build_15.dm_build_1[:dm_build_16]
	return dm_build_15
}

func (dm_build_18 *Dm_build_0) Dm_build_17(dm_build_19 int) *Dm_build_0 {
	dm_build_18.dm_build_2 = dm_build_19
	return dm_build_18
}

func (dm_build_21 *Dm_build_0) Dm_build_20() int {
	return dm_build_21.dm_build_2
}

func (dm_build_23 *Dm_build_0) Dm_build_22(dm_build_24 bool) int {
	return len(dm_build_23.dm_build_1) - dm_build_23.dm_build_2
}

func (dm_build_26 *Dm_build_0) Dm_build_25(dm_build_27 int, dm_build_28 bool, dm_build_29 bool) *Dm_build_0 {

	if dm_build_28 {
		if dm_build_29 {
			dm_build_26.dm_build_7(dm_build_27)
		} else {
			dm_build_26.dm_build_1 = dm_build_26.dm_build_1[:len(dm_build_26.dm_build_1)-dm_build_27]
		}
	} else {
		if dm_build_29 {
			dm_build_26.dm_build_2 += dm_build_27
		} else {
			dm_build_26.dm_build_2 -= dm_build_27
		}
	}

	return dm_build_26
}

func (dm_build_31 *Dm_build_0) Dm_build_30(dm_build_32 io.Reader, dm_build_33 int) (int, error) {
	dm_build_34 := len(dm_build_31.dm_build_1)
	dm_build_31.dm_build_7(dm_build_33)
	dm_build_35 := 0
	for dm_build_33 > 0 {
		n, err := dm_build_32.Read(dm_build_31.dm_build_1[dm_build_34+dm_build_35:])
		if n > 0 && err == io.EOF {
			dm_build_35 += n
			dm_build_31.dm_build_1 = dm_build_31.dm_build_1[:dm_build_34+dm_build_35]
			return dm_build_35, nil
		} else if n > 0 && err == nil {
			dm_build_33 -= n
			dm_build_35 += n
		} else if n == 0 && err != nil {
			return -1, ECGO_COMMUNITION_ERROR.addDetailln(err.Error()).throw()
		}
	}

	return dm_build_35, nil
}

func (dm_build_37 *Dm_build_0) Dm_build_36(dm_build_38 io.Writer) (*Dm_build_0, error) {
	if _, err := dm_build_38.Write(dm_build_37.dm_build_1); err != nil {
		return nil, ECGO_COMMUNITION_ERROR.addDetailln(err.Error()).throw()
	}
	return dm_build_37, nil
}

func (dm_build_40 *Dm_build_0) Dm_build_39(dm_build_41 bool) int {
	dm_build_42 := len(dm_build_40.dm_build_1)
	dm_build_40.dm_build_7(1)

	if dm_build_41 {
		return copy(dm_build_40.dm_build_1[dm_build_42:], []byte{1})
	} else {
		return copy(dm_build_40.dm_build_1[dm_build_42:], []byte{0})
	}
}

func (dm_build_44 *Dm_build_0) Dm_build_43(dm_build_45 byte) int {
	dm_build_46 := len(dm_build_44.dm_build_1)
	dm_build_44.dm_build_7(1)

	return copy(dm_build_44.dm_build_1[dm_build_46:], Dm_build_1265.Dm_build_1443(dm_build_45))
}

func (dm_build_48 *Dm_build_0) Dm_build_47(dm_build_49 int8) int {
	dm_build_50 := len(dm_build_48.dm_build_1)
	dm_build_48.dm_build_7(1)

	return copy(dm_build_48.dm_build_1[dm_build_50:], Dm_build_1265.Dm_build_1446(dm_build_49))
}

func (dm_build_52 *Dm_build_0) Dm_build_51(dm_build_53 int16) int {
	dm_build_54 := len(dm_build_52.dm_build_1)
	dm_build_52.dm_build_7(2)

	return copy(dm_build_52.dm_build_1[dm_build_54:], Dm_build_1265.Dm_build_1449(dm_build_53))
}

func (dm_build_56 *Dm_build_0) Dm_build_55(dm_build_57 int32) int {
	dm_build_58 := len(dm_build_56.dm_build_1)
	dm_build_56.dm_build_7(4)

	return copy(dm_build_56.dm_build_1[dm_build_58:], Dm_build_1265.Dm_build_1452(dm_build_57))
}

func (dm_build_60 *Dm_build_0) Dm_build_59(dm_build_61 uint8) int {
	dm_build_62 := len(dm_build_60.dm_build_1)
	dm_build_60.dm_build_7(1)

	return copy(dm_build_60.dm_build_1[dm_build_62:], Dm_build_1265.Dm_build_1464(dm_build_61))
}

func (dm_build_64 *Dm_build_0) Dm_build_63(dm_build_65 uint16) int {
	dm_build_66 := len(dm_build_64.dm_build_1)
	dm_build_64.dm_build_7(2)

	return copy(dm_build_64.dm_build_1[dm_build_66:], Dm_build_1265.Dm_build_1467(dm_build_65))
}

func (dm_build_68 *Dm_build_0) Dm_build_67(dm_build_69 uint32) int {
	dm_build_70 := len(dm_build_68.dm_build_1)
	dm_build_68.dm_build_7(4)

	return copy(dm_build_68.dm_build_1[dm_build_70:], Dm_build_1265.Dm_build_1470(dm_build_69))
}

func (dm_build_72 *Dm_build_0) Dm_build_71(dm_build_73 uint64) int {
	dm_build_74 := len(dm_build_72.dm_build_1)
	dm_build_72.dm_build_7(8)

	return copy(dm_build_72.dm_build_1[dm_build_74:], Dm_build_1265.Dm_build_1473(dm_build_73))
}

func (dm_build_76 *Dm_build_0) Dm_build_75(dm_build_77 float32) int {
	dm_build_78 := len(dm_build_76.dm_build_1)
	dm_build_76.dm_build_7(4)

	return copy(dm_build_76.dm_build_1[dm_build_78:], Dm_build_1265.Dm_build_1470(math.Float32bits(dm_build_77)))
}

func (dm_build_80 *Dm_build_0) Dm_build_79(dm_build_81 float64) int {
	dm_build_82 := len(dm_build_80.dm_build_1)
	dm_build_80.dm_build_7(8)

	return copy(dm_build_80.dm_build_1[dm_build_82:], Dm_build_1265.Dm_build_1473(math.Float64bits(dm_build_81)))
}

func (dm_build_84 *Dm_build_0) Dm_build_83(dm_build_85 []byte) int {
	dm_build_86 := len(dm_build_84.dm_build_1)
	dm_build_84.dm_build_7(len(dm_build_85))
	return copy(dm_build_84.dm_build_1[dm_build_86:], dm_build_85)
}

func (dm_build_88 *Dm_build_0) Dm_build_87(dm_build_89 []byte) int {
	return dm_build_88.Dm_build_55(int32(len(dm_build_89))) + dm_build_88.Dm_build_83(dm_build_89)
}

func (dm_build_91 *Dm_build_0) Dm_build_90(dm_build_92 []byte) int {
	return dm_build_91.Dm_build_59(uint8(len(dm_build_92))) + dm_build_91.Dm_build_83(dm_build_92)
}

func (dm_build_94 *Dm_build_0) Dm_build_93(dm_build_95 []byte) int {
	return dm_build_94.Dm_build_63(uint16(len(dm_build_95))) + dm_build_94.Dm_build_83(dm_build_95)
}

func (dm_build_97 *Dm_build_0) Dm_build_96(dm_build_98 []byte) int {
	return dm_build_97.Dm_build_83(dm_build_98) + dm_build_97.Dm_build_43(0)
}

func (dm_build_100 *Dm_build_0) Dm_build_99(dm_build_101 string, dm_build_102 string, dm_build_103 *DmConnection) int {
	dm_build_104 := Dm_build_1265.Dm_build_1481(dm_build_101, dm_build_102, dm_build_103)
	return dm_build_100.Dm_build_87(dm_build_104)
}

func (dm_build_106 *Dm_build_0) Dm_build_105(dm_build_107 string, dm_build_108 string, dm_build_109 *DmConnection) int {
	dm_build_110 := Dm_build_1265.Dm_build_1481(dm_build_107, dm_build_108, dm_build_109)
	return dm_build_106.Dm_build_90(dm_build_110)
}

func (dm_build_112 *Dm_build_0) Dm_build_111(dm_build_113 string, dm_build_114 string, dm_build_115 *DmConnection) int {
	dm_build_116 := Dm_build_1265.Dm_build_1481(dm_build_113, dm_build_114, dm_build_115)
	return dm_build_112.Dm_build_93(dm_build_116)
}

func (dm_build_118 *Dm_build_0) Dm_build_117(dm_build_119 string, dm_build_120 string, dm_build_121 *DmConnection) int {
	dm_build_122 := Dm_build_1265.Dm_build_1481(dm_build_119, dm_build_120, dm_build_121)
	return dm_build_118.Dm_build_96(dm_build_122)
}

func (dm_build_124 *Dm_build_0) Dm_build_123() byte {
	dm_build_125 := Dm_build_1265.Dm_build_1358(dm_build_124.dm_build_1, dm_build_124.dm_build_2)
	dm_build_124.dm_build_2++
	return dm_build_125
}

func (dm_build_127 *Dm_build_0) Dm_build_126() int16 {
	dm_build_128 := Dm_build_1265.Dm_build_1362(dm_build_127.dm_build_1, dm_build_127.dm_build_2)
	dm_build_127.dm_build_2 += 2
	return dm_build_128
}

func (dm_build_130 *Dm_build_0) Dm_build_129() int32 {
	dm_build_131 := Dm_build_1265.Dm_build_1367(dm_build_130.dm_build_1, dm_build_130.dm_build_2)
	dm_build_130.dm_build_2 += 4
	return dm_build_131
}

func (dm_build_133 *Dm_build_0) Dm_build_132() int64 {
	dm_build_134 := Dm_build_1265.Dm_build_1372(dm_build_133.dm_build_1, dm_build_133.dm_build_2)
	dm_build_133.dm_build_2 += 8
	return dm_build_134
}

func (dm_build_136 *Dm_build_0) Dm_build_135() float32 {
	dm_build_137 := Dm_build_1265.Dm_build_1377(dm_build_136.dm_build_1, dm_build_136.dm_build_2)
	dm_build_136.dm_build_2 += 4
	return dm_build_137
}

func (dm_build_139 *Dm_build_0) Dm_build_138() float64 {
	dm_build_140 := Dm_build_1265.Dm_build_1381(dm_build_139.dm_build_1, dm_build_139.dm_build_2)
	dm_build_139.dm_build_2 += 8
	return dm_build_140
}

func (dm_build_142 *Dm_build_0) Dm_build_141() uint8 {
	dm_build_143 := Dm_build_1265.Dm_build_1385(dm_build_142.dm_build_1, dm_build_142.dm_build_2)
	dm_build_142.dm_build_2 += 1
	return dm_build_143
}

func (dm_build_145 *Dm_build_0) Dm_build_144() uint16 {
	dm_build_146 := Dm_build_1265.Dm_build_1389(dm_build_145.dm_build_1, dm_build_145.dm_build_2)
	dm_build_145.dm_build_2 += 2
	return dm_build_146
}

func (dm_build_148 *Dm_build_0) Dm_build_147() uint32 {
	dm_build_149 := Dm_build_1265.Dm_build_1394(dm_build_148.dm_build_1, dm_build_148.dm_build_2)
	dm_build_148.dm_build_2 += 4
	return dm_build_149
}

func (dm_build_151 *Dm_build_0) Dm_build_150(dm_build_152 int) []byte {
	dm_build_153 := Dm_build_1265.Dm_build_1416(dm_build_151.dm_build_1, dm_build_151.dm_build_2, dm_build_152)
	dm_build_151.dm_build_2 += dm_build_152
	return dm_build_153
}

func (dm_build_155 *Dm_build_0) Dm_build_154() []byte {
	return dm_build_155.Dm_build_150(int(dm_build_155.Dm_build_129()))
}

func (dm_build_157 *Dm_build_0) Dm_build_156() []byte {
	return dm_build_157.Dm_build_150(int(dm_build_157.Dm_build_123()))
}

func (dm_build_159 *Dm_build_0) Dm_build_158() []byte {
	return dm_build_159.Dm_build_150(int(dm_build_159.Dm_build_126()))
}

func (dm_build_161 *Dm_build_0) Dm_build_160(dm_build_162 int) []byte {
	return dm_build_161.Dm_build_150(dm_build_162)
}

func (dm_build_164 *Dm_build_0) Dm_build_163() []byte {
	dm_build_165 := 0
	for dm_build_164.Dm_build_123() != 0 {
		dm_build_165++
	}
	dm_build_164.Dm_build_25(dm_build_165, false, false)
	return dm_build_164.Dm_build_150(dm_build_165)
}

func (dm_build_167 *Dm_build_0) Dm_build_166(dm_build_168 int, dm_build_169 string, dm_build_170 *DmConnection) string {
	return Dm_build_1265.Dm_build_1517(dm_build_167.Dm_build_150(dm_build_168), dm_build_169, dm_build_170)
}

func (dm_build_172 *Dm_build_0) Dm_build_171(dm_build_173 string, dm_build_174 *DmConnection) string {
	return Dm_build_1265.Dm_build_1517(dm_build_172.Dm_build_154(), dm_build_173, dm_build_174)
}

func (dm_build_176 *Dm_build_0) Dm_build_175(dm_build_177 string, dm_build_178 *DmConnection) string {
	return Dm_build_1265.Dm_build_1517(dm_build_176.Dm_build_156(), dm_build_177, dm_build_178)
}

func (dm_build_180 *Dm_build_0) Dm_build_179(dm_build_181 string, dm_build_182 *DmConnection) string {
	return Dm_build_1265.Dm_build_1517(dm_build_180.Dm_build_158(), dm_build_181, dm_build_182)
}

func (dm_build_184 *Dm_build_0) Dm_build_183(dm_build_185 string, dm_build_186 *DmConnection) string {
	return Dm_build_1265.Dm_build_1517(dm_build_184.Dm_build_163(), dm_build_185, dm_build_186)
}

func (dm_build_188 *Dm_build_0) Dm_build_187(dm_build_189 int, dm_build_190 byte) int {
	return dm_build_188.Dm_build_223(dm_build_189, Dm_build_1265.Dm_build_1443(dm_build_190))
}

func (dm_build_192 *Dm_build_0) Dm_build_191(dm_build_193 int, dm_build_194 int16) int {
	return dm_build_192.Dm_build_223(dm_build_193, Dm_build_1265.Dm_build_1449(dm_build_194))
}

func (dm_build_196 *Dm_build_0) Dm_build_195(dm_build_197 int, dm_build_198 int32) int {
	return dm_build_196.Dm_build_223(dm_build_197, Dm_build_1265.Dm_build_1452(dm_build_198))
}

func (dm_build_200 *Dm_build_0) Dm_build_199(dm_build_201 int, dm_build_202 int64) int {
	return dm_build_200.Dm_build_223(dm_build_201, Dm_build_1265.Dm_build_1455(dm_build_202))
}

func (dm_build_204 *Dm_build_0) Dm_build_203(dm_build_205 int, dm_build_206 float32) int {
	return dm_build_204.Dm_build_223(dm_build_205, Dm_build_1265.Dm_build_1458(dm_build_206))
}

func (dm_build_208 *Dm_build_0) Dm_build_207(dm_build_209 int, dm_build_210 float64) int {
	return dm_build_208.Dm_build_223(dm_build_209, Dm_build_1265.Dm_build_1461(dm_build_210))
}

func (dm_build_212 *Dm_build_0) Dm_build_211(dm_build_213 int, dm_build_214 uint8) int {
	return dm_build_212.Dm_build_223(dm_build_213, Dm_build_1265.Dm_build_1464(dm_build_214))
}

func (dm_build_216 *Dm_build_0) Dm_build_215(dm_build_217 int, dm_build_218 uint16) int {
	return dm_build_216.Dm_build_223(dm_build_217, Dm_build_1265.Dm_build_1467(dm_build_218))
}

func (dm_build_220 *Dm_build_0) Dm_build_219(dm_build_221 int, dm_build_222 uint32) int {
	return dm_build_220.Dm_build_223(dm_build_221, Dm_build_1265.Dm_build_1470(dm_build_222))
}

func (dm_build_224 *Dm_build_0) Dm_build_223(dm_build_225 int, dm_build_226 []byte) int {
	return copy(dm_build_224.dm_build_1[dm_build_225:], dm_build_226)
}

func (dm_build_228 *Dm_build_0) Dm_build_227(dm_build_229 int, dm_build_230 []byte) int {
	return dm_build_228.Dm_build_195(dm_build_229, int32(len(dm_build_230))) + dm_build_228.Dm_build_223(dm_build_229+4, dm_build_230)
}

func (dm_build_232 *Dm_build_0) Dm_build_231(dm_build_233 int, dm_build_234 []byte) int {
	return dm_build_232.Dm_build_187(dm_build_233, byte(len(dm_build_234))) + dm_build_232.Dm_build_223(dm_build_233+1, dm_build_234)
}

func (dm_build_236 *Dm_build_0) Dm_build_235(dm_build_237 int, dm_build_238 []byte) int {
	return dm_build_236.Dm_build_191(dm_build_237, int16(len(dm_build_238))) + dm_build_236.Dm_build_223(dm_build_237+2, dm_build_238)
}

func (dm_build_240 *Dm_build_0) Dm_build_239(dm_build_241 int, dm_build_242 []byte) int {
	return dm_build_240.Dm_build_223(dm_build_241, dm_build_242) + dm_build_240.Dm_build_187(dm_build_241+len(dm_build_242), 0)
}

func (dm_build_244 *Dm_build_0) Dm_build_243(dm_build_245 int, dm_build_246 string, dm_build_247 string, dm_build_248 *DmConnection) int {
	return dm_build_244.Dm_build_227(dm_build_245, Dm_build_1265.Dm_build_1481(dm_build_246, dm_build_247, dm_build_248))
}

func (dm_build_250 *Dm_build_0) Dm_build_249(dm_build_251 int, dm_build_252 string, dm_build_253 string, dm_build_254 *DmConnection) int {
	return dm_build_250.Dm_build_231(dm_build_251, Dm_build_1265.Dm_build_1481(dm_build_252, dm_build_253, dm_build_254))
}

func (dm_build_256 *Dm_build_0) Dm_build_255(dm_build_257 int, dm_build_258 string, dm_build_259 string, dm_build_260 *DmConnection) int {
	return dm_build_256.Dm_build_235(dm_build_257, Dm_build_1265.Dm_build_1481(dm_build_258, dm_build_259, dm_build_260))
}

func (dm_build_262 *Dm_build_0) Dm_build_261(dm_build_263 int, dm_build_264 string, dm_build_265 string, dm_build_266 *DmConnection) int {
	return dm_build_262.Dm_build_239(dm_build_263, Dm_build_1265.Dm_build_1481(dm_build_264, dm_build_265, dm_build_266))
}

func (dm_build_268 *Dm_build_0) Dm_build_267(dm_build_269 int) byte {
	return Dm_build_1265.Dm_build_1486(dm_build_268.Dm_build_294(dm_build_269, 1))
}

func (dm_build_271 *Dm_build_0) Dm_build_270(dm_build_272 int) int16 {
	return Dm_build_1265.Dm_build_1489(dm_build_271.Dm_build_294(dm_build_272, 2))
}

func (dm_build_274 *Dm_build_0) Dm_build_273(dm_build_275 int) int32 {
	return Dm_build_1265.Dm_build_1492(dm_build_274.Dm_build_294(dm_build_275, 4))
}

func (dm_build_277 *Dm_build_0) Dm_build_276(dm_build_278 int) int64 {
	return Dm_build_1265.Dm_build_1495(dm_build_277.Dm_build_294(dm_build_278, 8))
}

func (dm_build_280 *Dm_build_0) Dm_build_279(dm_build_281 int) float32 {
	return Dm_build_1265.Dm_build_1498(dm_build_280.Dm_build_294(dm_build_281, 4))
}

func (dm_build_283 *Dm_build_0) Dm_build_282(dm_build_284 int) float64 {
	return Dm_build_1265.Dm_build_1501(dm_build_283.Dm_build_294(dm_build_284, 8))
}

func (dm_build_286 *Dm_build_0) Dm_build_285(dm_build_287 int) uint8 {
	return Dm_build_1265.Dm_build_1504(dm_build_286.Dm_build_294(dm_build_287, 1))
}

func (dm_build_289 *Dm_build_0) Dm_build_288(dm_build_290 int) uint16 {
	return Dm_build_1265.Dm_build_1507(dm_build_289.Dm_build_294(dm_build_290, 2))
}

func (dm_build_292 *Dm_build_0) Dm_build_291(dm_build_293 int) uint32 {
	return Dm_build_1265.Dm_build_1510(dm_build_292.Dm_build_294(dm_build_293, 4))
}

func (dm_build_295 *Dm_build_0) Dm_build_294(dm_build_296 int, dm_build_297 int) []byte {
	return dm_build_295.dm_build_1[dm_build_296 : dm_build_296+dm_build_297]
}

func (dm_build_299 *Dm_build_0) Dm_build_298(dm_build_300 int) []byte {
	dm_build_301 := dm_build_299.Dm_build_273(dm_build_300)
	return dm_build_299.Dm_build_294(dm_build_300+4, int(dm_build_301))
}

func (dm_build_303 *Dm_build_0) Dm_build_302(dm_build_304 int) []byte {
	dm_build_305 := dm_build_303.Dm_build_267(dm_build_304)
	return dm_build_303.Dm_build_294(dm_build_304+1, int(dm_build_305))
}

func (dm_build_307 *Dm_build_0) Dm_build_306(dm_build_308 int) []byte {
	dm_build_309 := dm_build_307.Dm_build_270(dm_build_308)
	return dm_build_307.Dm_build_294(dm_build_308+2, int(dm_build_309))
}

func (dm_build_311 *Dm_build_0) Dm_build_310(dm_build_312 int) []byte {
	dm_build_313 := 0
	for dm_build_311.Dm_build_267(dm_build_312) != 0 {
		dm_build_312++
		dm_build_313++
	}

	return dm_build_311.Dm_build_294(dm_build_312-dm_build_313, int(dm_build_313))
}

func (dm_build_315 *Dm_build_0) Dm_build_314(dm_build_316 int, dm_build_317 string, dm_build_318 *DmConnection) string {
	return Dm_build_1265.Dm_build_1517(dm_build_315.Dm_build_298(dm_build_316), dm_build_317, dm_build_318)
}

func (dm_build_320 *Dm_build_0) Dm_build_319(dm_build_321 int, dm_build_322 string, dm_build_323 *DmConnection) string {
	return Dm_build_1265.Dm_build_1517(dm_build_320.Dm_build_302(dm_build_321), dm_build_322, dm_build_323)
}

func (dm_build_325 *Dm_build_0) Dm_build_324(dm_build_326 int, dm_build_327 string, dm_build_328 *DmConnection) string {
	return Dm_build_1265.Dm_build_1517(dm_build_325.Dm_build_306(dm_build_326), dm_build_327, dm_build_328)
}

func (dm_build_330 *Dm_build_0) Dm_build_329(dm_build_331 int, dm_build_332 string, dm_build_333 *DmConnection) string {
	return Dm_build_1265.Dm_build_1517(dm_build_330.Dm_build_310(dm_build_331), dm_build_332, dm_build_333)
}
