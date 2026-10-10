/* C89 adaptation of glankk/libgfxd gbi.h v0.3.6.
 * Source: https://github.com/glankk/libgfxd/blob/49ec1bb893a16b769ddfd0b329d238a658dc0ea2/gbi.h
 * Constants and encodings from the open reconstruction; no SDK types.
 * Include the project Gfx declaration before this header.
 *
 * MIT License
 *
 * Copyright (c) 2016-2021 glank (glankk@github.com)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#ifndef UNBAKE_GBI_H
#define UNBAKE_GBI_H

/* use fast3d by default */
#if !defined(F3D_GBI) && !defined(F3DEX_GBI) && !defined(F3DEX_GBI_2)
# define F3D_GBI
#endif

/* commands for fast3d and f3dex */
#if defined(F3D_GBI) || defined(F3DEX_GBI)
# define G_SPNOOP		0x00
# define G_MTX			0x01
# define G_MOVEMEM		0x03
# define G_VTX			0x04
# define G_DL			0x06
# if defined(F3D_BETA)
#  define G_RDPHALF_2		0xB2
#  define G_RDPHALF_1		0xB3
#  define G_PERSPNORM		0xB4
# else
#  define G_RDPHALF_2		0xB3
#  define G_RDPHALF_1		0xB4
# endif
# define G_LINE3D		0xB5
# define G_CLEARGEOMETRYMODE	0xB6
# define G_SETGEOMETRYMODE	0xB7
# define G_ENDDL		0xB8
# define G_SETOTHERMODE_L	0xB9
# define G_SETOTHERMODE_H	0xBA
# define G_TEXTURE		0xBB
# define G_MOVEWORD		0xBC
# define G_POPMTX		0xBD
# define G_CULLDL		0xBE
# define G_TRI1			0xBF
# define G_NOOP			0xC0
#endif

/* commands for f3dex */
#if defined(F3DEX_GBI)
# define G_LOAD_UCODE		0xAF
# define G_BRANCH_Z		0xB0
# define G_TRI2			0xB1
# if !defined(F3D_BETA)
#  define G_MODIFYVTX		0xB2
# endif
#endif

/* commands for f3dex2 */
#if defined(F3DEX_GBI_2)
# define G_NOOP			0x00
# define G_VTX			0x01
# define G_MODIFYVTX		0x02
# define G_CULLDL		0x03
# define G_BRANCH_Z		0x04
# define G_TRI1			0x05
# define G_TRI2			0x06
# define G_QUAD			0x07
# define G_LINE3D		0x08
# define G_SPECIAL_3		0xD3
# define G_SPECIAL_2		0xD4
# define G_SPECIAL_1		0xD5
# define G_DMA_IO		0xD6
# define G_TEXTURE		0xD7
# define G_POPMTX		0xD8
# define G_GEOMETRYMODE		0xD9
# define G_MTX			0xDA
# define G_MOVEWORD		0xDB
# define G_MOVEMEM		0xDC
# define G_LOAD_UCODE		0xDD
# define G_DL			0xDE
# define G_ENDDL		0xDF
# define G_SPNOOP		0xE0
# define G_RDPHALF_1		0xE1
# define G_SETOTHERMODE_L	0xE2
# define G_SETOTHERMODE_H	0xE3
# define G_RDPHALF_2		0xF1
#endif

/* rdp commands */
#define G_TEXRECT		0xE4
#define G_TEXRECTFLIP		0xE5
#define G_RDPLOADSYNC		0xE6
#define G_RDPPIPESYNC		0xE7
#define G_RDPTILESYNC		0xE8
#define G_RDPFULLSYNC		0xE9
#define G_SETKEYGB		0xEA
#define G_SETKEYR		0xEB
#define G_SETCONVERT		0xEC
#define G_SETSCISSOR		0xED
#define G_SETPRIMDEPTH		0xEE
#define G_RDPSETOTHERMODE	0xEF
#define G_LOADTLUT		0xF0
#define G_SETTILESIZE		0xF2
#define G_LOADBLOCK		0xF3
#define G_LOADTILE		0xF4
#define G_SETTILE		0xF5
#define G_FILLRECT		0xF6
#define G_SETFILLCOLOR		0xF7
#define G_SETFOGCOLOR		0xF8
#define G_SETBLENDCOLOR		0xF9
#define G_SETPRIMCOLOR		0xFA
#define G_SETENVCOLOR		0xFB
#define G_SETCOMBINE		0xFC
#define G_SETTIMG		0xFD
#define G_SETZIMG		0xFE
#define G_SETCIMG		0xFF

/* commands for s2dex */
#if defined(F3DEX_GBI)
# define G_BG_1CYC		0x01
# define G_BG_COPY		0x02
# define G_OBJ_RECTANGLE	0x03
# define G_OBJ_SPRITE		0x04
# define G_OBJ_MOVEMEM		0x05
# define G_SELECT_DL		0xB0
# define G_OBJ_RENDERMODE	0xB1
# define G_OBJ_RECTANGLE_R	0xB2
# define G_OBJ_LOADTXTR		0xC1
# define G_OBJ_LDTX_SPRITE	0xC2
# define G_OBJ_LDTX_RECT	0xC3
# define G_OBJ_LDTX_RECT_R	0xC4
#endif

/* commands for s2dex2 */
#if defined(F3DEX_GBI_2)
# define G_OBJ_RECTANGLE	0x01
# define G_OBJ_SPRITE		0x02
# define G_SELECT_DL		0x04
# define G_OBJ_LOADTXTR		0x05
# define G_OBJ_LDTX_SPRITE	0x06
# define G_OBJ_LDTX_RECT	0x07
# define G_OBJ_LDTX_RECT_R	0x08
# define G_BG_1CYC		0x09
# define G_BG_COPY		0x0A
# define G_OBJ_RENDERMODE	0x0B
# define G_OBJ_RECTANGLE_R	0xDA
# define G_OBJ_MOVEMEM		0xDC
#endif

/* commands for s2dex and s2dex2 */
#if defined(F3DEX_GBI) || defined(F3DEX_GBI_2)
# define G_RDPHALF_0		0xE4
#endif

/* image formats */
#define G_IM_FMT_RGBA		0
#define G_IM_FMT_YUV		1
#define G_IM_FMT_CI		2
#define G_IM_FMT_IA		3
#define G_IM_FMT_I		4
#define G_IM_SIZ_4b		0
#define G_IM_SIZ_8b		1
#define G_IM_SIZ_16b		2
#define G_IM_SIZ_32b		3

/* texture settings */
#define G_TX_NOMIRROR		(gI_(0x0) << 0)
#define G_TX_MIRROR		(gI_(0x1) << 0)
#define G_TX_WRAP		(gI_(0x0) << 1)
#define G_TX_CLAMP		(gI_(0x1) << 1)
#define G_TX_NOMASK		gI_(0)
#define G_TX_NOLOD		gI_(0)
#define G_OFF			gI_(0)
#define G_ON			gI_(1)

/* tile indices */
#define G_TX_LOADTILE		7
#define G_TX_RENDERTILE		0

/* loadblock constants */
#define G_TX_DXT_FRAC		11
#define G_TX_LDBLK_MAX_TXL	2047

/* geometry mode */
#define G_ZBUFFER		(gI_(0x1) << 0)
#define G_SHADE			(gI_(0x1) << 2)
#define G_CULL_BOTH		(G_CULL_FRONT | G_CULL_BACK)
#define G_FOG			(gI_(0x1) << 16)
#define G_LIGHTING		(gI_(0x1) << 17)
#define G_TEXTURE_GEN		(gI_(0x1) << 18)
#define G_TEXTURE_GEN_LINEAR	(gI_(0x1) << 19)
#define G_LOD			(gI_(0x1) << 20)

/* geometry mode for fast3d */
#if defined(F3D_GBI)
# define G_CLIPPING		(gI_(0x0) << 0)
#endif

/* geometry mode for fast3d and f3dex */
#if defined(F3D_GBI) || defined(F3DEX_GBI)
# define G_TEXTURE_ENABLE	(gI_(0x1) << 1)
# define G_SHADING_SMOOTH	(gI_(0x1) << 9)
# define G_CULL_FRONT		(gI_(0x1) << 12)
# define G_CULL_BACK		(gI_(0x1) << 13)
#endif

/* geometry mode for f3dex and f3dex2 */
#if defined(F3DEX_GBI) || defined(F3DEX_GBI_2)
# define G_CLIPPING		(gI_(0x1) << 23)
#endif

/* geometry mode for f3dex2 */
#if defined(F3DEX_GBI_2)
# define G_TEXTURE_ENABLE	(gI_(0x0) << 0)
# define G_CULL_FRONT		(gI_(0x1) << 9)
# define G_CULL_BACK		(gI_(0x1) << 10)
# define G_SHADING_SMOOTH	(gI_(0x1) << 21)
# if defined(F3DEX2_POS_LIGHTS)
#  define G_LIGHTING_POSITIONAL	(gI_(0x1) << 22)
# endif
#endif

/* othermode lo */
#define G_MDSFT_ALPHACOMPARE	0
#define G_MDSFT_ZSRCSEL		2
#define G_MDSFT_RENDERMODE	3
#define G_MDSFT_BLENDER		16
#define G_MDSIZ_ALPHACOMPARE	2
#define G_MDSIZ_ZSRCSEL		1
#define G_MDSIZ_RENDERMODE	29
#define G_MDSIZ_BLENDER		13

#define G_AC_NONE		(gI_(0x0) << G_MDSFT_ALPHACOMPARE)
#define G_AC_THRESHOLD		(gI_(0x1) << G_MDSFT_ALPHACOMPARE)
#define G_AC_DITHER		(gI_(0x3) << G_MDSFT_ALPHACOMPARE)
#define G_ZS_PIXEL		(gI_(0x0) << G_MDSFT_ZSRCSEL)
#define G_ZS_PRIM		(gI_(0x1) << G_MDSFT_ZSRCSEL)
#define AA_EN			(gI_(0x1) << (G_MDSFT_RENDERMODE + 0))
#define Z_CMP			(gI_(0x1) << (G_MDSFT_RENDERMODE + 1))
#define Z_UPD			(gI_(0x1) << (G_MDSFT_RENDERMODE + 2))
#define IM_RD			(gI_(0x1) << (G_MDSFT_RENDERMODE + 3))
#define CLR_ON_CVG		(gI_(0x1) << (G_MDSFT_RENDERMODE + 4))
#define CVG_DST_CLAMP		(gI_(0x0) << (G_MDSFT_RENDERMODE + 5))
#define CVG_DST_WRAP		(gI_(0x1) << (G_MDSFT_RENDERMODE + 5))
#define CVG_DST_FULL		(gI_(0x2) << (G_MDSFT_RENDERMODE + 5))
#define CVG_DST_SAVE		(gI_(0x3) << (G_MDSFT_RENDERMODE + 5))
#define ZMODE_OPA		(gI_(0x0) << (G_MDSFT_RENDERMODE + 7))
#define ZMODE_INTER		(gI_(0x1) << (G_MDSFT_RENDERMODE + 7))
#define ZMODE_XLU		(gI_(0x2) << (G_MDSFT_RENDERMODE + 7))
#define ZMODE_DEC		(gI_(0x3) << (G_MDSFT_RENDERMODE + 7))
#define CVG_X_ALPHA		(gI_(0x1) << (G_MDSFT_RENDERMODE + 9))
#define ALPHA_CVG_SEL		(gI_(0x1) << (G_MDSFT_RENDERMODE + 10))
#define FORCE_BL		(gI_(0x1) << (G_MDSFT_RENDERMODE + 11))

#define G_BL_1MA		gI_(0x0)
#define G_BL_1			gI_(0x2)
#define G_BL_0			gI_(0x3)
#define G_BL_CLR_IN		gI_(0x0)
#define G_BL_CLR_MEM		gI_(0x1)
#define G_BL_CLR_BL		gI_(0x2)
#define G_BL_CLR_FOG		gI_(0x3)
#define G_BL_A_IN		gI_(0x0)
#define G_BL_A_FOG		gI_(0x1)
#define G_BL_A_MEM		gI_(0x1)
#define G_BL_A_SHADE		gI_(0x2)

#define GBL_c1(p, a, m, b) \
	( \
		gF_(p, 2, 30) | \
		gF_(a, 2, 26) | \
		gF_(m, 2, 22) | \
		gF_(b, 2, 18) \
	)
#define GBL_c2(p, a, m, b) \
	( \
		gF_(p, 2, 28) | \
		gF_(a, 2, 24) | \
		gF_(m, 2, 20) | \
		gF_(b, 2, 16) \
	)

/* render modes */
#define G_RM_OPA_SURF \
	( \
		CVG_DST_CLAMP | ZMODE_OPA | FORCE_BL | \
		GBL_c1(G_BL_CLR_IN, G_BL_0, G_BL_CLR_IN, G_BL_1) \
	)
#define G_RM_OPA_SURF2 \
	( \
		CVG_DST_CLAMP | ZMODE_OPA | FORCE_BL | \
		GBL_c2(G_BL_CLR_IN, G_BL_0, G_BL_CLR_IN, G_BL_1) \
	)
#define G_RM_AA_OPA_SURF \
	( \
		AA_EN | IM_RD | CVG_DST_CLAMP | ZMODE_OPA | ALPHA_CVG_SEL | \
		GBL_c1(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM) \
	)
#define G_RM_AA_OPA_SURF2 \
	( \
		AA_EN | IM_RD | CVG_DST_CLAMP | ZMODE_OPA | ALPHA_CVG_SEL | \
		GBL_c2(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM) \
	)
#define G_RM_RA_OPA_SURF \
	( \
		AA_EN | CVG_DST_CLAMP | ZMODE_OPA | ALPHA_CVG_SEL | \
		GBL_c1(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM) \
	)
#define G_RM_RA_OPA_SURF2 \
	( \
		AA_EN | CVG_DST_CLAMP | ZMODE_OPA | ALPHA_CVG_SEL | \
		GBL_c2(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM) \
	)
#define G_RM_ZB_OPA_SURF \
	( \
		Z_CMP | Z_UPD | CVG_DST_FULL | ZMODE_OPA | ALPHA_CVG_SEL | \
		GBL_c1(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM) \
	)
#define G_RM_ZB_OPA_SURF2 \
	( \
		Z_CMP | Z_UPD | CVG_DST_FULL | ZMODE_OPA | ALPHA_CVG_SEL | \
		GBL_c2(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM) \
	)
#define G_RM_AA_ZB_OPA_SURF \
	( \
		AA_EN | Z_CMP | Z_UPD | IM_RD | CVG_DST_CLAMP | ZMODE_OPA | \
		ALPHA_CVG_SEL | \
		GBL_c1(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM) \
	)
#define G_RM_AA_ZB_OPA_SURF2 \
	( \
		AA_EN | Z_CMP | Z_UPD | IM_RD | CVG_DST_CLAMP | ZMODE_OPA | \
		ALPHA_CVG_SEL | \
		GBL_c2(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM) \
	)
#define G_RM_RA_ZB_OPA_SURF \
	( \
		AA_EN | Z_CMP | Z_UPD | CVG_DST_CLAMP | ZMODE_OPA | \
		ALPHA_CVG_SEL | \
		GBL_c1(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM) \
	)
#define G_RM_RA_ZB_OPA_SURF2 \
	( \
		AA_EN | Z_CMP | Z_UPD | CVG_DST_CLAMP | ZMODE_OPA | \
		ALPHA_CVG_SEL | \
		GBL_c2(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM) \
	)

#define G_RM_XLU_SURF \
	( \
		IM_RD | CVG_DST_FULL | ZMODE_OPA | FORCE_BL | \
		GBL_c1(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA) \
	)
#define G_RM_XLU_SURF2 \
	( \
		IM_RD | CVG_DST_FULL | ZMODE_OPA | FORCE_BL | \
		GBL_c2(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA) \
	)
#define G_RM_AA_XLU_SURF \
	( \
		AA_EN | IM_RD | CLR_ON_CVG | CVG_DST_WRAP | ZMODE_OPA | \
		FORCE_BL | \
		GBL_c1(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA) \
	)
#define G_RM_AA_XLU_SURF2 \
	( \
		AA_EN | IM_RD | CLR_ON_CVG | CVG_DST_WRAP | ZMODE_OPA | \
		FORCE_BL | \
		GBL_c2(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA) \
	)
#define G_RM_ZB_XLU_SURF \
	( \
		Z_CMP | IM_RD | CVG_DST_FULL | ZMODE_XLU | FORCE_BL | \
		GBL_c1(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA) \
	)
#define G_RM_ZB_XLU_SURF2 \
	( \
		Z_CMP | IM_RD | CVG_DST_FULL | ZMODE_XLU | FORCE_BL | \
		GBL_c2(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA) \
	)
#define G_RM_AA_ZB_XLU_SURF \
	( \
		AA_EN | Z_CMP | IM_RD | CLR_ON_CVG | CVG_DST_WRAP | \
		ZMODE_XLU | FORCE_BL | \
		GBL_c1(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA) \
	)
#define G_RM_AA_ZB_XLU_SURF2 \
	( \
		AA_EN | Z_CMP | IM_RD | CLR_ON_CVG | CVG_DST_WRAP | \
		ZMODE_XLU | FORCE_BL | \
		GBL_c2(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA) \
	)

#define G_RM_ZB_OPA_DECAL \
	( \
		Z_CMP | CVG_DST_FULL | ZMODE_DEC | ALPHA_CVG_SEL | \
		GBL_c1(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM) \
	)
#define G_RM_ZB_OPA_DECAL2 \
	( \
		Z_CMP | CVG_DST_FULL | ZMODE_DEC | ALPHA_CVG_SEL | \
		GBL_c2(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM) \
	)
#define G_RM_AA_ZB_OPA_DECAL \
	( \
		AA_EN | Z_CMP | IM_RD | CVG_DST_WRAP | ZMODE_DEC | \
		ALPHA_CVG_SEL | \
		GBL_c1(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM) \
	)
#define G_RM_AA_ZB_OPA_DECAL2 \
	( \
		AA_EN | Z_CMP | IM_RD | CVG_DST_WRAP | ZMODE_DEC | \
		ALPHA_CVG_SEL | \
		GBL_c2(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM) \
	)
#define G_RM_RA_ZB_OPA_DECAL \
	( \
		AA_EN | Z_CMP | CVG_DST_WRAP | ZMODE_DEC | ALPHA_CVG_SEL | \
		GBL_c1(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM) \
	)
#define G_RM_RA_ZB_OPA_DECAL2 \
	( \
		AA_EN | Z_CMP | CVG_DST_WRAP | ZMODE_DEC | ALPHA_CVG_SEL | \
		GBL_c2(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM) \
	)

#define G_RM_ZB_XLU_DECAL \
	( \
		Z_CMP | IM_RD | CVG_DST_FULL | ZMODE_DEC | FORCE_BL | \
		GBL_c1(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA) \
	)
#define G_RM_ZB_XLU_DECAL2 \
	( \
		Z_CMP | IM_RD | CVG_DST_FULL | ZMODE_DEC | FORCE_BL | \
		GBL_c2(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA) \
	)
#define G_RM_AA_ZB_XLU_DECAL \
	( \
		AA_EN | Z_CMP | IM_RD | CLR_ON_CVG | CVG_DST_WRAP | \
		ZMODE_DEC | FORCE_BL | \
		GBL_c1(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA) \
	)
#define G_RM_AA_ZB_XLU_DECAL2 \
	( \
		AA_EN | Z_CMP | IM_RD | CLR_ON_CVG | CVG_DST_WRAP | \
		ZMODE_DEC | FORCE_BL | \
		GBL_c2(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA) \
	)

#define G_RM_AA_ZB_OPA_INTER \
	( \
		AA_EN | Z_CMP | Z_UPD | IM_RD | CVG_DST_CLAMP | ZMODE_INTER | \
		ALPHA_CVG_SEL | \
		GBL_c1(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM) \
	)
#define G_RM_AA_ZB_OPA_INTER2 \
	( \
		AA_EN | Z_CMP | Z_UPD | IM_RD | CVG_DST_CLAMP | ZMODE_INTER | \
		ALPHA_CVG_SEL | \
		GBL_c2(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM) \
	)
#define G_RM_RA_ZB_OPA_INTER \
	( \
		AA_EN | Z_CMP | Z_UPD | CVG_DST_CLAMP | ZMODE_INTER | \
		ALPHA_CVG_SEL | \
		GBL_c1(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM) \
	)
#define G_RM_RA_ZB_OPA_INTER2 \
	( \
		AA_EN | Z_CMP | Z_UPD | CVG_DST_CLAMP | ZMODE_INTER | \
		ALPHA_CVG_SEL | \
		GBL_c2(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM) \
	)

#define G_RM_AA_ZB_XLU_INTER \
	( \
		AA_EN | Z_CMP | IM_RD | CLR_ON_CVG | CVG_DST_WRAP | \
		ZMODE_INTER | FORCE_BL | \
		GBL_c1(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA) \
	)
#define G_RM_AA_ZB_XLU_INTER2 \
	( \
		AA_EN | Z_CMP | IM_RD | CLR_ON_CVG | CVG_DST_WRAP | \
		ZMODE_INTER | FORCE_BL | \
		GBL_c2(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA) \
	)

#define G_RM_AA_XLU_LINE \
	( \
		AA_EN | IM_RD | CVG_DST_CLAMP | ZMODE_OPA | CVG_X_ALPHA | \
		ALPHA_CVG_SEL | FORCE_BL | \
		GBL_c1(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA) \
	)
#define G_RM_AA_XLU_LINE2 \
	( \
		AA_EN | IM_RD | CVG_DST_CLAMP | ZMODE_OPA | CVG_X_ALPHA | \
		ALPHA_CVG_SEL | FORCE_BL | \
		GBL_c2(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA) \
	)
#define G_RM_AA_ZB_XLU_LINE \
	( \
		AA_EN | Z_CMP | IM_RD | CVG_DST_CLAMP | ZMODE_XLU | \
		CVG_X_ALPHA | ALPHA_CVG_SEL | FORCE_BL | \
		GBL_c1(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA) \
	)
#define G_RM_AA_ZB_XLU_LINE2 \
	( \
		AA_EN | Z_CMP | IM_RD | CVG_DST_CLAMP | ZMODE_XLU | \
		CVG_X_ALPHA | ALPHA_CVG_SEL | FORCE_BL | \
		GBL_c2(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA) \
	)

#define G_RM_AA_DEC_LINE \
	( \
		AA_EN | IM_RD | CVG_DST_FULL | ZMODE_OPA | CVG_X_ALPHA | \
		ALPHA_CVG_SEL | FORCE_BL | \
		GBL_c1(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA) \
	)
#define G_RM_AA_DEC_LINE2 \
	( \
		AA_EN | IM_RD | CVG_DST_FULL | ZMODE_OPA | CVG_X_ALPHA | \
		ALPHA_CVG_SEL | FORCE_BL | \
		GBL_c2(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA) \
	)
#define G_RM_AA_ZB_DEC_LINE \
	( \
		AA_EN | Z_CMP | IM_RD | CVG_DST_SAVE | ZMODE_DEC | \
		CVG_X_ALPHA | ALPHA_CVG_SEL | FORCE_BL | \
		GBL_c1(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA) \
	)
#define G_RM_AA_ZB_DEC_LINE2 \
	( \
		AA_EN | Z_CMP | IM_RD | CVG_DST_SAVE | ZMODE_DEC | \
		CVG_X_ALPHA | ALPHA_CVG_SEL | FORCE_BL | \
		GBL_c2(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA) \
	)


#define G_RM_TEX_EDGE \
	( \
		AA_EN | CVG_DST_CLAMP | ZMODE_OPA | CVG_X_ALPHA | \
		ALPHA_CVG_SEL | FORCE_BL | \
		GBL_c1(G_BL_CLR_IN, G_BL_0, G_BL_CLR_IN, G_BL_1) \
	)
#define G_RM_TEX_EDGE2 \
	( \
		AA_EN | CVG_DST_CLAMP | ZMODE_OPA | CVG_X_ALPHA | \
		ALPHA_CVG_SEL | FORCE_BL | \
		GBL_c2(G_BL_CLR_IN, G_BL_0, G_BL_CLR_IN, G_BL_1) \
	)
#define G_RM_AA_TEX_EDGE \
	( \
		AA_EN | IM_RD | CVG_DST_CLAMP | ZMODE_OPA | CVG_X_ALPHA | \
		ALPHA_CVG_SEL | \
		GBL_c1(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM) \
	)
#define G_RM_AA_TEX_EDGE2 \
	( \
		AA_EN | IM_RD | CVG_DST_CLAMP | ZMODE_OPA | CVG_X_ALPHA | \
		ALPHA_CVG_SEL | \
		GBL_c2(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM) \
	)
#define G_RM_AA_ZB_TEX_EDGE \
	( \
		AA_EN | Z_CMP | Z_UPD | IM_RD | CVG_DST_CLAMP | ZMODE_OPA | \
		CVG_X_ALPHA | ALPHA_CVG_SEL | \
		GBL_c1(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM) \
	)
#define G_RM_AA_ZB_TEX_EDGE2 \
	( \
		AA_EN | Z_CMP | Z_UPD | IM_RD | CVG_DST_CLAMP | ZMODE_OPA | \
		CVG_X_ALPHA | ALPHA_CVG_SEL | \
		GBL_c2(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM) \
	)

#define G_RM_AA_ZB_TEX_INTER \
	( \
		AA_EN | Z_CMP | Z_UPD | IM_RD | CVG_DST_CLAMP | ZMODE_INTER | \
		CVG_X_ALPHA | ALPHA_CVG_SEL | \
		GBL_c1(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM) \
	)
#define G_RM_AA_ZB_TEX_INTER2 \
	( \
		AA_EN | Z_CMP | Z_UPD | IM_RD | CVG_DST_CLAMP | ZMODE_INTER | \
		CVG_X_ALPHA | ALPHA_CVG_SEL | \
		GBL_c2(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM) \
	)

#define G_RM_AA_SUB_SURF \
	( \
		AA_EN | IM_RD | CVG_DST_FULL | ZMODE_OPA | ALPHA_CVG_SEL | \
		GBL_c1(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM) \
	)
#define G_RM_AA_SUB_SURF2 \
	( \
		AA_EN | IM_RD | CVG_DST_FULL | ZMODE_OPA | ALPHA_CVG_SEL | \
		GBL_c2(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM) \
	)
#define G_RM_AA_ZB_SUB_SURF \
	( \
		AA_EN | Z_CMP | Z_UPD | IM_RD | CVG_DST_FULL | ZMODE_OPA | \
		ALPHA_CVG_SEL | \
		GBL_c1(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM) \
	)
#define G_RM_AA_ZB_SUB_SURF2 \
	( \
		AA_EN | Z_CMP | Z_UPD | IM_RD | CVG_DST_FULL | ZMODE_OPA | \
		ALPHA_CVG_SEL | \
		GBL_c2(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM) \
	)

#define G_RM_PCL_SURF \
	( \
		G_AC_DITHER | CVG_DST_FULL | ZMODE_OPA | FORCE_BL | \
		GBL_c1(G_BL_CLR_IN, G_BL_0, G_BL_CLR_IN, G_BL_1) \
	)
#define G_RM_PCL_SURF2 \
	( \
		G_AC_DITHER | CVG_DST_FULL | ZMODE_OPA | FORCE_BL | \
		GBL_c2(G_BL_CLR_IN, G_BL_0, G_BL_CLR_IN, G_BL_1) \
	)
#define G_RM_AA_PCL_SURF \
	( \
		G_AC_DITHER | AA_EN | IM_RD | CVG_DST_CLAMP | ZMODE_OPA | \
		GBL_c1(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA) \
	)
#define G_RM_AA_PCL_SURF2 \
	( \
		G_AC_DITHER | AA_EN | IM_RD | CVG_DST_CLAMP | ZMODE_OPA | \
		GBL_c2(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA) \
	)
#define G_RM_ZB_PCL_SURF \
	( \
		G_AC_DITHER | Z_CMP | Z_UPD | CVG_DST_FULL | ZMODE_OPA | \
		GBL_c1(G_BL_CLR_IN, G_BL_0, G_BL_CLR_IN, G_BL_1) \
	)
#define G_RM_ZB_PCL_SURF2 \
	( \
		G_AC_DITHER | Z_CMP | Z_UPD | CVG_DST_FULL | ZMODE_OPA | \
		GBL_c2(G_BL_CLR_IN, G_BL_0, G_BL_CLR_IN, G_BL_1) \
	)
#define G_RM_AA_ZB_PCL_SURF \
	( \
		G_AC_DITHER | AA_EN | Z_CMP | Z_UPD | IM_RD | CVG_DST_CLAMP | \
		ZMODE_OPA | \
		GBL_c1(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA) \
	)
#define G_RM_AA_ZB_PCL_SURF2 \
	( \
		G_AC_DITHER | AA_EN | Z_CMP | Z_UPD | IM_RD | CVG_DST_CLAMP | \
		ZMODE_OPA | \
		GBL_c2(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA) \
	)

#define G_RM_AA_OPA_TERR \
	( \
		AA_EN | IM_RD | CVG_DST_CLAMP | ZMODE_OPA | ALPHA_CVG_SEL | \
		GBL_c1(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA) \
	)
#define G_RM_AA_OPA_TERR2 \
	( \
		AA_EN | IM_RD | CVG_DST_CLAMP | ZMODE_OPA | ALPHA_CVG_SEL | \
		GBL_c2(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA) \
	)
#define G_RM_AA_ZB_OPA_TERR \
	( \
		AA_EN | Z_CMP | Z_UPD | IM_RD | CVG_DST_CLAMP | ZMODE_OPA | \
		ALPHA_CVG_SEL | \
		GBL_c1(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA) \
	)
#define G_RM_AA_ZB_OPA_TERR2 \
	( \
		AA_EN | Z_CMP | Z_UPD | IM_RD | CVG_DST_CLAMP | ZMODE_OPA | \
		ALPHA_CVG_SEL | \
		GBL_c2(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA) \
	)

#define G_RM_AA_TEX_TERR \
	( \
		AA_EN | IM_RD | CVG_DST_CLAMP | ZMODE_OPA | CVG_X_ALPHA | \
		ALPHA_CVG_SEL | \
		GBL_c1(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA) \
	)
#define G_RM_AA_TEX_TERR2 \
	( \
		AA_EN | IM_RD | CVG_DST_CLAMP | ZMODE_OPA | CVG_X_ALPHA | \
		ALPHA_CVG_SEL | \
		GBL_c2(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA) \
	)
#define G_RM_AA_ZB_TEX_TERR \
	( \
		AA_EN | Z_CMP | Z_UPD | IM_RD | CVG_DST_CLAMP | ZMODE_OPA | \
		CVG_X_ALPHA | ALPHA_CVG_SEL | \
		GBL_c1(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA) \
	)
#define G_RM_AA_ZB_TEX_TERR2 \
	( \
		AA_EN | Z_CMP | Z_UPD | IM_RD | CVG_DST_CLAMP | ZMODE_OPA | \
		CVG_X_ALPHA | ALPHA_CVG_SEL | \
		GBL_c2(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA) \
	)

#define G_RM_AA_SUB_TERR \
	( \
		AA_EN | IM_RD | CVG_DST_FULL | ZMODE_OPA | ALPHA_CVG_SEL | \
		GBL_c1(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA) \
	)
#define G_RM_AA_SUB_TERR2 \
	( \
		AA_EN | IM_RD | CVG_DST_FULL | ZMODE_OPA | ALPHA_CVG_SEL | \
		GBL_c2(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA) \
	)
#define G_RM_AA_ZB_SUB_TERR \
	( \
		AA_EN | Z_CMP | Z_UPD | IM_RD | CVG_DST_FULL | ZMODE_OPA | \
		ALPHA_CVG_SEL | \
		GBL_c1(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA) \
	)
#define G_RM_AA_ZB_SUB_TERR2 \
	( \
		AA_EN | Z_CMP | Z_UPD | IM_RD | CVG_DST_FULL | ZMODE_OPA | \
		ALPHA_CVG_SEL | \
		GBL_c2(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA) \
	)

#define G_RM_CLD_SURF \
	( \
		IM_RD | CVG_DST_SAVE | ZMODE_OPA | FORCE_BL | \
		GBL_c1(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA) \
	)
#define G_RM_CLD_SURF2 \
	( \
		IM_RD | CVG_DST_SAVE | ZMODE_OPA | FORCE_BL | \
		GBL_c2(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA) \
	)
#define G_RM_ZB_CLD_SURF \
	( \
		Z_CMP | IM_RD | CVG_DST_SAVE | ZMODE_XLU | FORCE_BL | \
		GBL_c1(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA) \
	)
#define G_RM_ZB_CLD_SURF2 \
	( \
		Z_CMP | IM_RD | CVG_DST_SAVE | ZMODE_XLU | FORCE_BL | \
		GBL_c2(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA) \
	)

#define G_RM_ZB_OVL_SURF \
	( \
		Z_CMP | IM_RD | CVG_DST_SAVE | ZMODE_DEC | FORCE_BL | \
		GBL_c1(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA) \
	)
#define G_RM_ZB_OVL_SURF2 \
	( \
		Z_CMP | IM_RD | CVG_DST_SAVE | ZMODE_DEC | FORCE_BL | \
		GBL_c2(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA) \
	)

#define G_RM_ADD \
	( \
		IM_RD | CVG_DST_SAVE | ZMODE_OPA | FORCE_BL | \
		GBL_c1(G_BL_CLR_IN, G_BL_A_FOG, G_BL_CLR_MEM, G_BL_1) \
	)
#define G_RM_ADD2 \
	( \
		IM_RD | CVG_DST_SAVE | ZMODE_OPA | FORCE_BL | \
		GBL_c2(G_BL_CLR_IN, G_BL_A_FOG, G_BL_CLR_MEM, G_BL_1) \
	)

#define G_RM_FOG_SHADE_A \
	GBL_c1(G_BL_CLR_FOG, G_BL_A_SHADE, G_BL_CLR_IN, G_BL_1MA)

#define G_RM_FOG_PRIM_A \
	GBL_c1(G_BL_CLR_FOG, G_BL_A_FOG, G_BL_CLR_IN, G_BL_1MA)

#define G_RM_PASS \
	GBL_c1(G_BL_CLR_IN, G_BL_0, G_BL_CLR_IN, G_BL_1)

#define G_RM_VISCVG \
	( \
		IM_RD | FORCE_BL | \
		GBL_c1(G_BL_CLR_IN, G_BL_0, G_BL_CLR_BL, G_BL_A_MEM) \
	)
#define G_RM_VISCVG2 \
	( \
		IM_RD | FORCE_BL | \
		GBL_c2(G_BL_CLR_IN, G_BL_0, G_BL_CLR_BL, G_BL_A_MEM) \
	)

#define G_RM_OPA_CI \
	( \
		CVG_DST_CLAMP | ZMODE_OPA | \
		GBL_c1(G_BL_CLR_IN, G_BL_0, G_BL_CLR_IN, G_BL_1) \
	)
#define G_RM_OPA_CI2 \
	( \
		CVG_DST_CLAMP | ZMODE_OPA | \
		GBL_c2(G_BL_CLR_IN, G_BL_0, G_BL_CLR_IN, G_BL_1) \
	)

#define G_RM_NOOP		GBL_c1(0, 0, 0, 0)
#define G_RM_NOOP2		GBL_c2(0, 0, 0, 0)

#define G_RM_SPRITE		G_RM_OPA_SURF
#define G_RM_SPRITE2		G_RM_OPA_SURF2
#define G_RM_RA_SPRITE \
	( \
		AA_EN | CVG_DST_CLAMP | ZMODE_OPA | CVG_X_ALPHA | \
		ALPHA_CVG_SEL | \
		GBL_c1(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA) \
	)
#define G_RM_RA_SPRITE2 \
	( \
		AA_EN | CVG_DST_CLAMP | ZMODE_OPA | CVG_X_ALPHA | \
		ALPHA_CVG_SEL | \
		GBL_c2(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA) \
	)
#define G_RM_AA_SPRITE		G_RM_AA_TEX_TERR
#define G_RM_AA_SPRITE2		G_RM_AA_TEX_TERR2
#define G_RM_XLU_SPRITE		G_RM_XLU_SURF
#define G_RM_XLU_SPRITE2	G_RM_XLU_SURF2
#define G_RM_AA_XLU_SPRITE	G_RM_AA_XLU_SURF
#define G_RM_AA_XLU_SPRITE2	G_RM_AA_XLU_SURF2

#define G_OBJRM_NOTXCLAMP	(gI_(0x1) << 0)
#define G_OBJRM_XLU		(gI_(0x1) << 1)
#define G_OBJRM_ANTIALIAS	(gI_(0x1) << 2)
#define G_OBJRM_BILERP		(gI_(0x1) << 3)
#define G_OBJRM_SHRINKSIZE_1	(gI_(0x1) << 4)
#define G_OBJRM_SHRINKSIZE_2	(gI_(0x1) << 5)
#define G_OBJRM_WIDEN		(gI_(0x1) << 6)

/* othermode hi */
#define G_MDSFT_ALPHADITHER	4
#define G_MDSFT_RGBDITHER	6
#define G_MDSFT_COMBKEY		8
#define G_MDSFT_TEXTCONV	9
#define G_MDSFT_TEXTFILT	12
#define G_MDSFT_TEXTLUT		14
#define G_MDSFT_TEXTLOD		16
#define G_MDSFT_TEXTDETAIL	17
#define G_MDSFT_TEXTPERSP	19
#define G_MDSFT_CYCLETYPE	20
#define G_MDSFT_PIPELINE	23
#define G_MDSIZ_ALPHADITHER	2
#define G_MDSIZ_RGBDITHER	2
#define G_MDSIZ_COMBKEY		1
#define G_MDSIZ_TEXTCONV	3
#define G_MDSIZ_TEXTFILT	2
#define G_MDSIZ_TEXTLUT		2
#define G_MDSIZ_TEXTLOD		1
#define G_MDSIZ_TEXTDETAIL	2
#define G_MDSIZ_TEXTPERSP	1
#define G_MDSIZ_CYCLETYPE	2
#define G_MDSIZ_PIPELINE	1

#define G_AD_PATTERN		(gI_(0x0) << G_MDSFT_ALPHADITHER)
#define G_AD_NOTPATTERN		(gI_(0x1) << G_MDSFT_ALPHADITHER)
#define G_AD_NOISE		(gI_(0x2) << G_MDSFT_ALPHADITHER)
#define G_AD_DISABLE		(gI_(0x3) << G_MDSFT_ALPHADITHER)
#define G_CD_MAGICSQ		(gI_(0x0) << G_MDSFT_RGBDITHER)
#define G_CD_BAYER		(gI_(0x1) << G_MDSFT_RGBDITHER)
#define G_CD_NOISE		(gI_(0x2) << G_MDSFT_RGBDITHER)
#define G_CD_DISABLE		(gI_(0x3) << G_MDSFT_RGBDITHER)
#define G_CD_ENABLE		(gI_(0x2) << G_MDSFT_RGBDITHER)
#define G_CK_NONE		(gI_(0x0) << G_MDSFT_COMBKEY)
#define G_CK_KEY		(gI_(0x1) << G_MDSFT_COMBKEY)
#define G_TC_CONV		(gI_(0x0) << G_MDSFT_TEXTCONV)
#define G_TC_FILTCONV		(gI_(0x5) << G_MDSFT_TEXTCONV)
#define G_TC_FILT		(gI_(0x6) << G_MDSFT_TEXTCONV)
#define G_TF_POINT		(gI_(0x0) << G_MDSFT_TEXTFILT)
#define G_TF_BILERP		(gI_(0x2) << G_MDSFT_TEXTFILT)
#define G_TF_AVERAGE		(gI_(0x3) << G_MDSFT_TEXTFILT)
#define G_TT_NONE		(gI_(0x0) << G_MDSFT_TEXTLUT)
#define G_TT_RGBA16		(gI_(0x2) << G_MDSFT_TEXTLUT)
#define G_TT_IA16		(gI_(0x3) << G_MDSFT_TEXTLUT)
#define G_TL_TILE		(gI_(0x0) << G_MDSFT_TEXTLOD)
#define G_TL_LOD		(gI_(0x1) << G_MDSFT_TEXTLOD)
#define G_TD_CLAMP		(gI_(0x0) << G_MDSFT_TEXTDETAIL)
#define G_TD_SHARPEN		(gI_(0x1) << G_MDSFT_TEXTDETAIL)
#define G_TD_DETAIL		(gI_(0x2) << G_MDSFT_TEXTDETAIL)
#define G_TP_NONE		(gI_(0x0) << G_MDSFT_TEXTPERSP)
#define G_TP_PERSP		(gI_(0x1) << G_MDSFT_TEXTPERSP)
#define G_CYC_1CYCLE		(gI_(0x0) << G_MDSFT_CYCLETYPE)
#define G_CYC_2CYCLE		(gI_(0x1) << G_MDSFT_CYCLETYPE)
#define G_CYC_COPY		(gI_(0x2) << G_MDSFT_CYCLETYPE)
#define G_CYC_FILL		(gI_(0x3) << G_MDSFT_CYCLETYPE)
#define G_PM_NPRIMITIVE		(gI_(0x0) << G_MDSFT_PIPELINE)
#define G_PM_1PRIMITIVE		(gI_(0x1) << G_MDSFT_PIPELINE)

/* color conversion constants */
#define G_CV_K0			(175)
#define G_CV_K1			(-43)
#define G_CV_K2			(-89)
#define G_CV_K3			(222)
#define G_CV_K4			(114)
#define G_CV_K5			(42)

/* color combiner */
#define G_CCMUX_COMBINED	0
#define G_CCMUX_TEXEL0		1
#define G_CCMUX_TEXEL1		2
#define G_CCMUX_PRIMITIVE	3
#define G_CCMUX_SHADE		4
#define G_CCMUX_ENVIRONMENT	5
#define G_CCMUX_1		6
#define G_CCMUX_NOISE		7
#define G_CCMUX_0		31
#define G_CCMUX_CENTER		6
#define G_CCMUX_K4		7
#define G_CCMUX_SCALE		6
#define G_CCMUX_COMBINED_ALPHA	7
#define G_CCMUX_TEXEL0_ALPHA	8
#define G_CCMUX_TEXEL1_ALPHA	9
#define G_CCMUX_PRIMITIVE_ALPHA	10
#define G_CCMUX_SHADE_ALPHA	11
#define G_CCMUX_ENV_ALPHA	12
#define G_CCMUX_LOD_FRACTION	13
#define G_CCMUX_PRIM_LOD_FRAC	14
#define G_CCMUX_K5		15
#define G_ACMUX_COMBINED	0
#define G_ACMUX_TEXEL0		1
#define G_ACMUX_TEXEL1		2
#define G_ACMUX_PRIMITIVE	3
#define G_ACMUX_SHADE		4
#define G_ACMUX_ENVIRONMENT	5
#define G_ACMUX_1		6
#define G_ACMUX_0		7
#define G_ACMUX_LOD_FRACTION	0
#define G_ACMUX_PRIM_LOD_FRAC	6

/*
 * combine modes
 *	( A		- B )		* C		+ D
*/
#define G_CC_MODULATEI \
	TEXEL0,		0,		SHADE,		0, \
	0,		0,		0,		SHADE
#define G_CC_MODULATEIA \
	TEXEL0,		0,		SHADE,		0, \
	TEXEL0,		0,		SHADE,		0
#define G_CC_MODULATEIDECALA \
	TEXEL0,		0,		SHADE,		0, \
	0,		0,		0,		TEXEL0
#define G_CC_MODULATERGB \
	G_CC_MODULATEI
#define G_CC_MODULATERGBA \
	G_CC_MODULATEIA
#define G_CC_MODULATERGBDECALA \
	G_CC_MODULATEIDECALA
#define G_CC_MODULATEI_PRIM \
	TEXEL0,		0,		PRIMITIVE,	0, \
	0,		0,		0,		PRIMITIVE
#define G_CC_MODULATEIA_PRIM \
	TEXEL0,		0,		PRIMITIVE,	0, \
	TEXEL0,		0,		PRIMITIVE,	0
#define G_CC_MODULATEIDECALA_PRIM \
	TEXEL0,		0,		PRIMITIVE,	0, \
	0,		0,		0,		TEXEL0
#define G_CC_MODULATERGB_PRIM \
	G_CC_MODULATEI_PRIM
#define G_CC_MODULATERGBA_PRIM \
	G_CC_MODULATEIA_PRIM
#define G_CC_MODULATERGBDECALA_PRIM \
	G_CC_MODULATEIDECALA_PRIM
#define G_CC_DECALRGB \
	0,		0,		0,		TEXEL0, \
	0,		0,		0,		SHADE
#define G_CC_DECALRGBA \
	0,		0,		0,		TEXEL0, \
	0,		0,		0,		TEXEL0
#define G_CC_BLENDI \
	ENVIRONMENT,	SHADE,		TEXEL0,		SHADE, \
	0,		0,		0,		SHADE
#define G_CC_BLENDIA \
	ENVIRONMENT,	SHADE,		TEXEL0,		SHADE, \
	TEXEL0,		0,		SHADE,		0
#define G_CC_BLENDIDECALA \
	ENVIRONMENT,	SHADE,		TEXEL0,		SHADE, \
	0,		0,		0,		TEXEL0
#define G_CC_BLENDRGBA \
	TEXEL0,		SHADE,		TEXEL0_ALPHA,	SHADE, \
	0,		0,		0,		SHADE
#define G_CC_BLENDRGBDECALA \
	TEXEL0,		SHADE,		TEXEL0_ALPHA,	SHADE, \
	0,		0,		0,		TEXEL0
#define G_CC_REFLECTRGB \
	ENVIRONMENT,	0,		TEXEL0,		SHADE, \
	0,		0,		0,		SHADE
#define G_CC_REFLECTRGBDECALA \
	ENVIRONMENT,	0,		TEXEL0,		SHADE, \
	0,		0,		0,		TEXEL0
#define G_CC_HILITERGB \
	PRIMITIVE,	SHADE,		TEXEL0,		SHADE, \
	0,		0,		0,		SHADE
#define G_CC_HILITERGBA \
	PRIMITIVE,	SHADE,		TEXEL0,		SHADE, \
	PRIMITIVE,	SHADE,		TEXEL0,		SHADE
#define G_CC_HILITERGBDECALA \
	PRIMITIVE,	SHADE,		TEXEL0,		SHADE, \
	0,		0,		0,		TEXEL0
#define G_CC_1CYUV2RGB \
	TEXEL0,		K4,		K5,		TEXEL0, \
	0,		0,		0,		SHADE
#define G_CC_PRIMITIVE \
	0,		0,		0,		PRIMITIVE, \
	0,		0,		0,		PRIMITIVE
#define G_CC_SHADE \
	0,		0,		0,		SHADE, \
	0,		0,		0,		SHADE
#define G_CC_ADDRGB \
	1,		0,		TEXEL0,		SHADE, \
	0,		0,		0,		SHADE
#define G_CC_ADDRGBDECALA \
	1,		0,		TEXEL0,		SHADE, \
	0,		0,		0,		TEXEL0
#define G_CC_SHADEDECALA \
	0,		0,		0,		SHADE, \
	0,		0,		0,		TEXEL0
#define G_CC_BLENDPE \
	PRIMITIVE,	ENVIRONMENT,	TEXEL0,		ENVIRONMENT, \
	TEXEL0,		0,		SHADE,		0
#define G_CC_BLENDPEDECALA \
	PRIMITIVE,	ENVIRONMENT,	TEXEL0,		ENVIRONMENT, \
	0,		0,		0,		TEXEL0
#define G_CC_TRILERP \
	TEXEL1,		TEXEL0,		LOD_FRACTION,	TEXEL0, \
	TEXEL1,		TEXEL0,		LOD_FRACTION,	TEXEL0
#define G_CC_TEMPLERP \
	TEXEL1,		TEXEL0,		PRIM_LOD_FRAC,	TEXEL0, \
	TEXEL1,		TEXEL0,		PRIM_LOD_FRAC,	TEXEL0
#define G_CC_INTERFERENCE \
	TEXEL0,		0,		TEXEL1,		0, \
	TEXEL0,		0,		TEXEL1,		0
#define _G_CC_BLENDPE \
	ENVIRONMENT,	PRIMITIVE,	TEXEL0,		PRIMITIVE, \
	TEXEL0,		0,		SHADE,		0
#define _G_CC_BLENDPEDECALA \
	ENVIRONMENT,	PRIMITIVE,	TEXEL0,		PRIMITIVE, \
	0,		0,		0,		TEXEL0
#define _G_CC_SPARSEST \
	PRIMITIVE,	TEXEL0,		LOD_FRACTION,	TEXEL0, \
	PRIMITIVE,	TEXEL0,		LOD_FRACTION,	TEXEL0
#define _G_CC_TWOCOLORTEX \
	PRIMITIVE,	SHADE,		TEXEL0,		SHADE, \
	0,		0,		0,		SHADE
#define G_CC_MODULATEI2 \
	COMBINED,	0,		SHADE,		0, \
	0,		0,		0,		SHADE
#define G_CC_MODULATEIA2 \
	COMBINED,	0,		SHADE,		0, \
	COMBINED,	0,		SHADE,		0
#define G_CC_MODULATERGB2 \
	G_CC_MODULATEI2
#define G_CC_MODULATERGBA2 \
	G_CC_MODULATEIA2
#define G_CC_MODULATEI_PRIM2 \
	COMBINED,	0,		PRIMITIVE,	0, \
	0,		0,		0,		PRIMITIVE
#define G_CC_MODULATEIA_PRIM2 \
	COMBINED,	0,		PRIMITIVE,	0, \
	COMBINED,	0,		PRIMITIVE,	0
#define G_CC_MODULATERGB_PRIM2 \
	G_CC_MODULATEI_PRIM2
#define G_CC_MODULATERGBA_PRIM2 \
	G_CC_MODULATEIA_PRIM2
#define G_CC_DECALRGB2 \
	0,		0,		0,		COMBINED, \
	0,		0,		0,		SHADE
#define G_CC_BLENDI2 \
	ENVIRONMENT,	SHADE,		COMBINED,	SHADE, \
	0,		0,		0,		SHADE
#define G_CC_BLENDIA2 \
	ENVIRONMENT,	SHADE,		COMBINED,	SHADE, \
	COMBINED,	0,		SHADE,		0
#define G_CC_HILITERGB2 \
	ENVIRONMENT,	COMBINED,	TEXEL0,		COMBINED, \
	0,		0,		0,		SHADE
#define G_CC_HILITERGBA2 \
	ENVIRONMENT,	COMBINED,	TEXEL0,		COMBINED, \
	ENVIRONMENT,	COMBINED,	TEXEL0,		COMBINED
#define G_CC_HILITERGBDECALA2 \
	ENVIRONMENT,	COMBINED,	TEXEL0,		COMBINED, \
	0,		0,		0,		TEXEL0
#define G_CC_HILITERGBPASSA2 \
	ENVIRONMENT,	COMBINED,	TEXEL0,		COMBINED, \
	0,		0,		0,		COMBINED
#define G_CC_CHROMA_KEY2 \
	TEXEL0,		CENTER,		SCALE,		0, \
	0,		0,		0,		0
#define G_CC_YUV2RGB \
	TEXEL1,		K4,		K5,		TEXEL1, \
	0,		0,		0,		0
#define G_CC_PASS2 \
	0,		0,		0,		COMBINED, \
	0,		0,		0,		COMBINED
#define G_CC_LERP(a0, b0, c0, d0, Aa0, Ab0, Ac0, Ad0, \
		a1, b1, c1, d1, Aa1, Ab1, Ac1, Ad1) \
	( \
		gFL_(G_CCMUX_##a0, 4, 52) | \
		gFL_(G_CCMUX_##c0, 5, 47) | \
		gFL_(G_ACMUX_##Aa0, 3, 44) | \
		gFL_(G_ACMUX_##Ac0, 3, 41) | \
		gFL_(G_CCMUX_##a1, 4, 37) | \
		gFL_(G_CCMUX_##c1, 5, 32) | \
		gFL_(G_CCMUX_##b0, 4, 28) | \
		gFL_(G_CCMUX_##b1, 4, 24) | \
		gFL_(G_ACMUX_##Aa1, 3, 21) | \
		gFL_(G_ACMUX_##Ac1, 3, 18) | \
		gFL_(G_CCMUX_##d0, 3, 15) | \
		gFL_(G_ACMUX_##Ab0, 3, 12) | \
		gFL_(G_ACMUX_##Ad0, 3, 9) | \
		gFL_(G_CCMUX_##d1, 3, 6) | \
		gFL_(G_ACMUX_##Ab1, 3, 3) | \
		gFL_(G_ACMUX_##Ad1, 3, 0) \
	)
#define G_CC_MODE(mode1, mode2)	G_CC_LERP(mode1, mode2)

/* scissor modes */
#define G_SC_NON_INTERLACE	gI_(0x0)
#define G_SC_EVEN_INTERLACE	gI_(0x2)
#define G_SC_ODD_INTERLACE	gI_(0x3)

/* display list branch flags */
#define G_DL_PUSH		gI_(0x0)
#define G_DL_NOPUSH		gI_(0x1)

/* conditional branching flags (f3dex and f3dex2) */
#if defined(F3DEX_GBI) || defined(F3DEX_GBI_2)
# define G_BZ_PERSP		0
# define G_BZ_ORTHO		1
#endif

/* matrix params */
#define G_MTX_MUL		(gI_(0x0) << 1)
#define G_MTX_LOAD		(gI_(0x1) << 1)

/* matrix params for fast3d and f3dex */
#if defined(F3D_GBI) || defined(F3DEX_GBI)
# define G_MTX_MODELVIEW	(gI_(0x0) << 0)
# define G_MTX_PROJECTION	(gI_(0x1) << 0)
# define G_MTX_NOPUSH		(gI_(0x0) << 2)
# define G_MTX_PUSH		(gI_(0x1) << 2)
#endif

/* matrix params for f3dex2 */
#if defined(F3DEX_GBI_2)
# define G_MTX_NOPUSH		(gI_(0x0) << 0)
# define G_MTX_PUSH		(gI_(0x1) << 0)
# define G_MTX_MODELVIEW	(gI_(0x0) << 2)
# define G_MTX_PROJECTION	(gI_(0x1) << 2)
#endif

/* moveword indices */
#define G_MW_MATRIX		0
#define G_MW_NUMLIGHT		2
#define G_MW_CLIP		4
#define G_MW_SEGMENT		6
#define G_MW_FOG		8
#define G_MW_GENSTAT		8
#define G_MW_LIGHTCOL		10
#define G_MW_PERSPNORM		14

/* moveword indices for fast3d and f3dex */
#if defined(F3D_GBI) || defined(F3DEX_GBI)
# define G_MW_POINTS		12
#endif

/* moveword indices for f3dex2 */
#if defined(F3DEX_GBI_2)
# define G_MW_FORCEMTX		12
#endif

/* moveword offsets */
#define G_MWO_NUMLIGHT		gI_(0x00)
#define G_MWO_CLIP_RNX		gI_(0x04)
#define G_MWO_CLIP_RNY		gI_(0x0C)
#define G_MWO_CLIP_RPX		gI_(0x14)
#define G_MWO_CLIP_RPY		gI_(0x1C)
#define G_MWO_SEGMENT_0		gI_(0x00)
#define G_MWO_SEGMENT_1		gI_(0x04)
#define G_MWO_SEGMENT_2		gI_(0x08)
#define G_MWO_SEGMENT_3		gI_(0x0C)
#define G_MWO_SEGMENT_4		gI_(0x10)
#define G_MWO_SEGMENT_5		gI_(0x14)
#define G_MWO_SEGMENT_6		gI_(0x18)
#define G_MWO_SEGMENT_7		gI_(0x1C)
#define G_MWO_SEGMENT_8		gI_(0x20)
#define G_MWO_SEGMENT_9		gI_(0x24)
#define G_MWO_SEGMENT_A		gI_(0x28)
#define G_MWO_SEGMENT_B		gI_(0x2C)
#define G_MWO_SEGMENT_C		gI_(0x30)
#define G_MWO_SEGMENT_D		gI_(0x34)
#define G_MWO_SEGMENT_E		gI_(0x38)
#define G_MWO_SEGMENT_F		gI_(0x3C)
#define G_MWO_FOG		gI_(0x00)
#define G_MWO_aLIGHT_1		gI_(0x00)
#define G_MWO_bLIGHT_1		gI_(0x04)
#define G_MWO_MATRIX_XX_XY_I	gI_(0x00)
#define G_MWO_MATRIX_XZ_XW_I	gI_(0x04)
#define G_MWO_MATRIX_YX_YY_I	gI_(0x08)
#define G_MWO_MATRIX_YZ_YW_I	gI_(0x0C)
#define G_MWO_MATRIX_ZX_ZY_I	gI_(0x10)
#define G_MWO_MATRIX_ZZ_ZW_I	gI_(0x14)
#define G_MWO_MATRIX_WX_WY_I	gI_(0x18)
#define G_MWO_MATRIX_WZ_WW_I	gI_(0x1C)
#define G_MWO_MATRIX_XX_XY_F	gI_(0x20)
#define G_MWO_MATRIX_XZ_XW_F	gI_(0x24)
#define G_MWO_MATRIX_YX_YY_F	gI_(0x28)
#define G_MWO_MATRIX_YZ_YW_F	gI_(0x2C)
#define G_MWO_MATRIX_ZX_ZY_F	gI_(0x30)
#define G_MWO_MATRIX_ZZ_ZW_F	gI_(0x34)
#define G_MWO_MATRIX_WX_WY_F	gI_(0x38)
#define G_MWO_MATRIX_WZ_WW_F	gI_(0x3C)
#define G_MWO_POINT_RGBA	gI_(0x10)
#define G_MWO_POINT_ST		gI_(0x14)
#define G_MWO_POINT_XYSCREEN	gI_(0x18)
#define G_MWO_POINT_ZSCREEN	gI_(0x1C)

/* moveword offsets for fast3d and f3dex */
#if defined(F3D_GBI) || defined(F3DEX_GBI)
# define G_MWO_aLIGHT_2		gI_(0x20)
# define G_MWO_bLIGHT_2		gI_(0x24)
# define G_MWO_aLIGHT_3		gI_(0x40)
# define G_MWO_bLIGHT_3		gI_(0x44)
# define G_MWO_aLIGHT_4		gI_(0x60)
# define G_MWO_bLIGHT_4		gI_(0x64)
# define G_MWO_aLIGHT_5		gI_(0x80)
# define G_MWO_bLIGHT_5		gI_(0x84)
# define G_MWO_aLIGHT_6		gI_(0xA0)
# define G_MWO_bLIGHT_6		gI_(0xA4)
# define G_MWO_aLIGHT_7		gI_(0xC0)
# define G_MWO_bLIGHT_7		gI_(0xC4)
# define G_MWO_aLIGHT_8		gI_(0xE0)
# define G_MWO_bLIGHT_8		gI_(0xE4)
#endif

/* moveword offsets for f3dex2 */
#if defined(F3DEX_GBI_2)
# define G_MWO_aLIGHT_2		gI_(0x18)
# define G_MWO_bLIGHT_2		gI_(0x1C)
# define G_MWO_aLIGHT_3		gI_(0x30)
# define G_MWO_bLIGHT_3		gI_(0x34)
# define G_MWO_aLIGHT_4		gI_(0x48)
# define G_MWO_bLIGHT_4		gI_(0x4C)
# define G_MWO_aLIGHT_5		gI_(0x60)
# define G_MWO_bLIGHT_5		gI_(0x64)
# define G_MWO_aLIGHT_6		gI_(0x78)
# define G_MWO_bLIGHT_6		gI_(0x7C)
# define G_MWO_aLIGHT_7		gI_(0x90)
# define G_MWO_bLIGHT_7		gI_(0x94)
# define G_MWO_aLIGHT_8		gI_(0xA8)
# define G_MWO_bLIGHT_8		gI_(0xAC)
#endif

/* movemem params for fast3d and f3dex */
#if defined(F3D_GBI) || defined(F3DEX_GBI)
# define G_MV_VIEWPORT		128
# define G_MV_LOOKATY		130
# define G_MV_LOOKATX		132
# define G_MV_L0		134
# define G_MV_L1		136
# define G_MV_L2		138
# define G_MV_L3		140
# define G_MV_L4		142
# define G_MV_L5		144
# define G_MV_L6		146
# define G_MV_L7		148
# define G_MV_TXTATT		150
# define G_MV_MATRIX_2		152
# define G_MV_MATRIX_3		154
# define G_MV_MATRIX_4		156
# define G_MV_MATRIX_1		158
#endif

/* movemem params for f3dex2 */
#if defined(F3DEX_GBI_2)
# define G_MV_MMTX		2
# define G_MV_PMTX		6
# define G_MV_VIEWPORT		8
# define G_MV_LIGHT		10
# define G_MV_POINT		12
# define G_MV_MATRIX		14
# define G_MVO_LOOKATX		gI_(0 * 0x18)
# define G_MVO_LOOKATY		gI_(1 * 0x18)
# define G_MVO_L0		gI_(2 * 0x18)
# define G_MVO_L1		gI_(3 * 0x18)
# define G_MVO_L2		gI_(4 * 0x18)
# define G_MVO_L3		gI_(5 * 0x18)
# define G_MVO_L4		gI_(6 * 0x18)
# define G_MVO_L5		gI_(7 * 0x18)
# define G_MVO_L6		gI_(8 * 0x18)
# define G_MVO_L7		gI_(9 * 0x18)
#endif

/* frustum ratios */
#define FRUSTRATIO_1		gI_(1)
#define FRUSTRATIO_2		gI_(2)
#define FRUSTRATIO_3		gI_(3)
#define FRUSTRATIO_4		gI_(4)
#define FRUSTRATIO_5		gI_(5)
#define FRUSTRATIO_6		gI_(6)

/* light params */
#define NUMLIGHTS_0		1
#define NUMLIGHTS_1		1
#define NUMLIGHTS_2		2
#define NUMLIGHTS_3		3
#define NUMLIGHTS_4		4
#define NUMLIGHTS_5		5
#define NUMLIGHTS_6		6
#define NUMLIGHTS_7		7
#define LIGHT_1			1
#define LIGHT_2			2
#define LIGHT_3			3
#define LIGHT_4			4
#define LIGHT_5			5
#define LIGHT_6			6
#define LIGHT_7			7
#define LIGHT_8			8

/* light params for fast3d and f3dex */
#if defined(F3D_GBI) || defined(F3DEX_GBI)
# define NUML(n)		(((n) + 1) * 32 + 0x80000000)
#endif

/* light params for f3dex2 */
#if defined(F3DEX_GBI_2)
# define NUML(n)		((n) * 0x18)
#endif

/* background load types */
#define G_BGLT_LOADBLOCK	gI_(0x0033)
#define G_BGLT_LOADTILE		gI_(0xFFF4)

/* background flags */
#define G_BG_FLAG_FLIPS		(gI_(0x1) << 0)
#define G_BG_FLAG_FLIPT		(gI_(0x1) << 1)

/* object load types */
#define G_OBJLT_TXTRBLOCK	gI_(0x00001033)
#define G_OBJLT_TXTRTILE	gI_(0x00FC1034)
#define G_OBJLT_TLUT		gI_(0x00000030)

/* object flags */
#define G_OBJ_FLAG_FLIPS	(gI_(0x1) << 0)
#define G_OBJ_FLAG_FLIPT	(gI_(0x1) << 4)


#define _GBI_V3(a,b,c,f) ((f) == 0 ? (a) : (f) == 1 ? (b) : (c))
#define gI_(v) ((unsigned int)(v))
#define gF_(v, w, s) _SHIFTL(v, s, w)
#ifndef _SHIFTL
#define _SHIFTL(v, s, w) (((unsigned int)(v) & (0xFFFFFFFFU >> (32 - (w)))) << (s))
#endif
/* Single evaluation of pkt, as in traditional GBI command builders. */
#define _GBI_CMD(pkt, a, b) { Gfx *_gbi = (Gfx *)(pkt); _gbi->words.w0 = (a); _gbi->words.w1 = (b); }

#if defined(F3DEX_GBI_2)
#define gSPSetOtherMode(pkt, cmd, sft, len, data) \
    _GBI_CMD(pkt, _SHIFTL(cmd, 24, 8) | _SHIFTL(32 - (sft) - (len), 8, 8) | _SHIFTL((len) - 1, 0, 8), (unsigned int)(data))
#define gsSPSetOtherMode(cmd, sft, len, data) \
    { { _SHIFTL(cmd, 24, 8) | _SHIFTL(32 - (sft) - (len), 8, 8) | _SHIFTL((len) - 1, 0, 8), (unsigned int)(data) } }
#define gSPMatrix(pkt, mtx, param) \
    _GBI_CMD(pkt, _SHIFTL(G_MTX, 24, 8) | _SHIFTL(7, 19, 5) | _SHIFTL((param) ^ G_MTX_PUSH, 0, 8), (unsigned int)(mtx))
#define gsSPMatrix(mtx, param) \
    { { _SHIFTL(G_MTX, 24, 8) | _SHIFTL(7, 19, 5) | _SHIFTL((param) ^ G_MTX_PUSH, 0, 8), (unsigned int)(mtx) } }
#define gSPPopMatrixN(pkt, param, n) \
    _GBI_CMD(pkt, _SHIFTL(G_POPMTX, 24, 8) | _SHIFTL(7, 19, 5) | 2, (unsigned int)(n) * 64)
#define gsSPPopMatrixN(param, n) \
    { { _SHIFTL(G_POPMTX, 24, 8) | _SHIFTL(7, 19, 5) | 2, (unsigned int)(n) * 64 } }
#define gSPMoveWord(pkt, index, offset, data) \
    _GBI_CMD(pkt, _SHIFTL(G_MOVEWORD, 24, 8) | _SHIFTL(index, 16, 8) | _SHIFTL(offset, 0, 16), (unsigned int)(data))
#define gsSPMoveWord(index, offset, data) \
    { { _SHIFTL(G_MOVEWORD, 24, 8) | _SHIFTL(index, 16, 8) | _SHIFTL(offset, 0, 16), (unsigned int)(data) } }
#define gSPMoveMem(pkt, index, offset, size, data) \
    _GBI_CMD(pkt, _SHIFTL(G_MOVEMEM, 24, 8) | _SHIFTL(((size) - 1) / 8, 19, 5) | _SHIFTL((offset) / 8, 8, 8) | _SHIFTL(index, 0, 8), (unsigned int)(data))
#define gsSPMoveMem(index, offset, size, data) \
    { { _SHIFTL(G_MOVEMEM, 24, 8) | _SHIFTL(((size) - 1) / 8, 19, 5) | _SHIFTL((offset) / 8, 8, 8) | _SHIFTL(index, 0, 8), (unsigned int)(data) } }
#define gSPGeometryMode(pkt, clear, set) \
    _GBI_CMD(pkt, _SHIFTL(G_GEOMETRYMODE, 24, 8) | _SHIFTL(~(clear), 0, 24), (unsigned int)(set))
#define gsSPGeometryMode(clear, set) \
    { { _SHIFTL(G_GEOMETRYMODE, 24, 8) | _SHIFTL(~(clear), 0, 24), (unsigned int)(set) } }
#define gSPTexture(pkt, s, t, level, tile, on) \
    _GBI_CMD(pkt, _SHIFTL(G_TEXTURE, 24, 8) | _SHIFTL(level, 11, 3) | _SHIFTL(tile, 8, 3) | _SHIFTL(on, 1, 7), _SHIFTL(s, 16, 16) | _SHIFTL(t, 0, 16))
#define gsSPTexture(s, t, level, tile, on) \
    { { _SHIFTL(G_TEXTURE, 24, 8) | _SHIFTL(level, 11, 3) | _SHIFTL(tile, 8, 3) | _SHIFTL(on, 1, 7), _SHIFTL(s, 16, 16) | _SHIFTL(t, 0, 16) } }
/* SDK texture extension: preserve the reserved xparam byte. */
#define gSPTextureL(pkt, s, t, level, xparam, tile, on) \
    _GBI_CMD(pkt, _SHIFTL(G_TEXTURE,24,8) | _SHIFTL(xparam,16,8) | _SHIFTL(level,11,3) | _SHIFTL(tile,8,3) | _SHIFTL(on,1,7), _SHIFTL(s,16,16) | _SHIFTL(t,0,16))
#define gsSPTextureL(s, t, level, xparam, tile, on) \
    {{ _SHIFTL(G_TEXTURE,24,8) | _SHIFTL(xparam,16,8) | _SHIFTL(level,11,3) | _SHIFTL(tile,8,3) | _SHIFTL(on,1,7), _SHIFTL(s,16,16) | _SHIFTL(t,0,16) }}
#define gSPLineW3D(pkt, v0, v1, wd, flag) \
    _GBI_CMD(pkt, _SHIFTL(G_LINE3D,24,8) | _SHIFTL(((flag) ? (v1) : (v0)) * 2,16,8) | _SHIFTL(((flag) ? (v0) : (v1)) * 2,8,8) | _SHIFTL(wd,0,8), 0)
#define gsSPLineW3D(v0, v1, wd, flag) \
    {{ _SHIFTL(G_LINE3D,24,8) | _SHIFTL(((flag) ? (v1) : (v0)) * 2,16,8) | _SHIFTL(((flag) ? (v0) : (v1)) * 2,8,8) | _SHIFTL(wd,0,8), 0 }}
#define gSPLine3D(pkt, v0, v1, flag) gSPLineW3D(pkt, v0, v1, 0, flag)
#define gsSPLine3D(v0, v1, flag) gsSPLineW3D(v0, v1, 0, flag)
#define gSPVertex(pkt, v, n, v0) \
    _GBI_CMD(pkt, _SHIFTL(G_VTX, 24, 8) | _SHIFTL(n, 12, 8) | _SHIFTL((v0) + (n), 1, 7), (unsigned int)(v))
#define gsSPVertex(v, n, v0) \
    { { _SHIFTL(G_VTX, 24, 8) | _SHIFTL(n, 12, 8) | _SHIFTL((v0) + (n), 1, 7), (unsigned int)(v) } }
#define gSP1Triangle(pkt, v0, v1, v2, flag) \
    _GBI_CMD(pkt, _SHIFTL(G_TRI1, 24, 8) | _SHIFTL(_GBI_V3(v0,v1,v2,flag) * 2, 16, 8) | _SHIFTL(_GBI_V3(v1,v2,v0,flag) * 2, 8, 8) | _SHIFTL(_GBI_V3(v2,v0,v1,flag) * 2, 0, 8), 0)
#define gsSP1Triangle(v0, v1, v2, flag) \
    { { _SHIFTL(G_TRI1, 24, 8) | _SHIFTL(_GBI_V3(v0,v1,v2,flag) * 2, 16, 8) | _SHIFTL(_GBI_V3(v1,v2,v0,flag) * 2, 8, 8) | _SHIFTL(_GBI_V3(v2,v0,v1,flag) * 2, 0, 8), 0 } }
#define gSP2Triangles(pkt, v00, v01, v02, flag0, v10, v11, v12, flag1) \
    _GBI_CMD(pkt, _SHIFTL(G_TRI2, 24, 8) | _SHIFTL(_GBI_V3(v00,v01,v02,flag0) * 2, 16, 8) | _SHIFTL(_GBI_V3(v01,v02,v00,flag0) * 2, 8, 8) | _SHIFTL(_GBI_V3(v02,v00,v01,flag0) * 2, 0, 8), _SHIFTL(_GBI_V3(v10,v11,v12,flag1) * 2, 16, 8) | _SHIFTL(_GBI_V3(v11,v12,v10,flag1) * 2, 8, 8) | _SHIFTL(_GBI_V3(v12,v10,v11,flag1) * 2, 0, 8))
#define gsSP2Triangles(v00, v01, v02, flag0, v10, v11, v12, flag1) \
    { { _SHIFTL(G_TRI2, 24, 8) | _SHIFTL(_GBI_V3(v00,v01,v02,flag0) * 2, 16, 8) | _SHIFTL(_GBI_V3(v01,v02,v00,flag0) * 2, 8, 8) | _SHIFTL(_GBI_V3(v02,v00,v01,flag0) * 2, 0, 8), _SHIFTL(_GBI_V3(v10,v11,v12,flag1) * 2, 16, 8) | _SHIFTL(_GBI_V3(v11,v12,v10,flag1) * 2, 8, 8) | _SHIFTL(_GBI_V3(v12,v10,v11,flag1) * 2, 0, 8) } }
#define gSPModifyVertex(pkt, v, where, data) \
    _GBI_CMD(pkt, _SHIFTL(G_MODIFYVTX, 24, 8) | _SHIFTL(where, 16, 8) | _SHIFTL((v) * 2, 0, 16), (unsigned int)(data))
#define gsSPModifyVertex(v, where, data) \
    { { _SHIFTL(G_MODIFYVTX, 24, 8) | _SHIFTL(where, 16, 8) | _SHIFTL((v) * 2, 0, 16), (unsigned int)(data) } }
#else
#define gSPSetOtherMode(pkt, cmd, sft, len, data) _GBI_CMD(pkt, _SHIFTL(cmd,24,8) | _SHIFTL(sft,8,8) | _SHIFTL(len,0,8), (unsigned int)(data))
#define gsSPSetOtherMode(cmd, sft, len, data) {{ _SHIFTL(cmd,24,8) | _SHIFTL(sft,8,8) | _SHIFTL(len,0,8), (unsigned int)(data) }}
#define gSPMatrix(pkt, mtx, param) _GBI_CMD(pkt, _SHIFTL(G_MTX,24,8) | _SHIFTL(param,16,8) | 64, (unsigned int)(mtx))
#define gsSPMatrix(mtx, param) {{ _SHIFTL(G_MTX,24,8) | _SHIFTL(param,16,8) | 64, (unsigned int)(mtx) }}
#define gSPMoveWord(pkt, index, offset, data) _GBI_CMD(pkt, _SHIFTL(G_MOVEWORD,24,8) | _SHIFTL(offset,8,16) | _SHIFTL(index,0,8), (unsigned int)(data))
#define gsSPMoveWord(index, offset, data) {{ _SHIFTL(G_MOVEWORD,24,8) | _SHIFTL(offset,8,16) | _SHIFTL(index,0,8), (unsigned int)(data) }}
#define gSPSetGeometryMode(pkt, mode) _GBI_CMD(pkt, _SHIFTL(G_SETGEOMETRYMODE,24,8), (unsigned int)(mode))
#define gSPClearGeometryMode(pkt, mode) _GBI_CMD(pkt, _SHIFTL(G_CLEARGEOMETRYMODE,24,8), (unsigned int)(mode))
#define gsSPSetGeometryMode(mode) {{ _SHIFTL(G_SETGEOMETRYMODE,24,8), (unsigned int)(mode) }}
#define gsSPClearGeometryMode(mode) {{ _SHIFTL(G_CLEARGEOMETRYMODE,24,8), (unsigned int)(mode) }}
#if defined(F3D_GBI)
#define gSP1Triangle(pkt, v0, v1, v2, flag) _GBI_CMD(pkt, _SHIFTL(G_TRI1,24,8), _SHIFTL(flag,24,8) | _SHIFTL((v0)*10,16,8) | _SHIFTL((v1)*10,8,8) | _SHIFTL((v2)*10,0,8))
#define gsSP1Triangle(v0, v1, v2, flag) {{ _SHIFTL(G_TRI1,24,8), _SHIFTL(flag,24,8) | _SHIFTL((v0)*10,16,8) | _SHIFTL((v1)*10,8,8) | _SHIFTL((v2)*10,0,8) }}
#else
#define gSP1Triangle(pkt, v0, v1, v2, flag) _GBI_CMD(pkt, _SHIFTL(G_TRI1,24,8), (((_GBI_V3(v0,v1,v2,flag)) * 2 & 0xFE) << 16) | (((_GBI_V3(v1,v2,v0,flag)) * 2 & 0xFE) << 8) | (((_GBI_V3(v2,v0,v1,flag)) * 2 & 0xFE) << 0))
#define gsSP1Triangle(v0, v1, v2, flag) {{ _SHIFTL(G_TRI1,24,8), (((_GBI_V3(v0,v1,v2,flag)) * 2 & 0xFE) << 16) | (((_GBI_V3(v1,v2,v0,flag)) * 2 & 0xFE) << 8) | (((_GBI_V3(v2,v0,v1,flag)) * 2 & 0xFE) << 0) }}
#endif
#endif
/* libgfxd single load command and the standard two-command wrappers. */
#define gLoadUcode(pkt, uc_start, uc_dsize) _GBI_CMD(pkt, _SHIFTL(G_LOAD_UCODE,24,8) | _SHIFTL((uc_dsize)-1,0,16), (unsigned int)(uc_start))
#define gsLoadUcode(uc_start, uc_dsize) {{ _SHIFTL(G_LOAD_UCODE,24,8) | _SHIFTL((uc_dsize)-1,0,16), (unsigned int)(uc_start) }}
#define gSPLoadUcodeEx(pkt, uc_start, uc_dstart, uc_dsize) { gDPHalf1(pkt, uc_dstart); gLoadUcode(pkt, uc_start, uc_dsize); }
#define gsSPLoadUcodeEx(uc_start, uc_dstart, uc_dsize) gsDPHalf1(uc_dstart), gsLoadUcode(uc_start, uc_dsize)
#define gSPLoadUcode(pkt, uc_start, uc_dstart) gSPLoadUcodeEx(pkt, uc_start, uc_dstart, 0x800)
#define gsSPLoadUcode(uc_start, uc_dstart) gsSPLoadUcodeEx(uc_start, uc_dstart, 0x800)
#define gDPPipeSync(pkt) \
    _GBI_CMD(pkt, _SHIFTL(G_RDPPIPESYNC, 24, 8), 0)
#define gsDPPipeSync() \
    { { _SHIFTL(G_RDPPIPESYNC, 24, 8), 0 } }
#define gDPLoadSync(pkt) \
    _GBI_CMD(pkt, _SHIFTL(G_RDPLOADSYNC, 24, 8), 0)
#define gsDPLoadSync() \
    { { _SHIFTL(G_RDPLOADSYNC, 24, 8), 0 } }
#define gDPTileSync(pkt) \
    _GBI_CMD(pkt, _SHIFTL(G_RDPTILESYNC, 24, 8), 0)
#define gsDPTileSync() \
    { { _SHIFTL(G_RDPTILESYNC, 24, 8), 0 } }
#define gDPFullSync(pkt) \
    _GBI_CMD(pkt, _SHIFTL(G_RDPFULLSYNC, 24, 8), 0)
#define gsDPFullSync() \
    { { _SHIFTL(G_RDPFULLSYNC, 24, 8), 0 } }
#define gDPNoOp(pkt) \
    _GBI_CMD(pkt, _SHIFTL(G_NOOP, 24, 8), 0)
#define gsDPNoOp() \
    { { _SHIFTL(G_NOOP, 24, 8), 0 } }
#define gSPEndDisplayList(pkt) \
    _GBI_CMD(pkt, _SHIFTL(G_ENDDL, 24, 8), 0)
#define gsSPEndDisplayList() \
    { { _SHIFTL(G_ENDDL, 24, 8), 0 } }
#define gSPNoOp(pkt) \
    _GBI_CMD(pkt, _SHIFTL(G_SPNOOP, 24, 8), 0)
#define gsSPNoOp() \
    { { _SHIFTL(G_SPNOOP, 24, 8), 0 } }
#define gDPSetFillColor(pkt, data) \
    _GBI_CMD(pkt, _SHIFTL(G_SETFILLCOLOR, 24, 8), (unsigned int)(data))
#define gsDPSetFillColor(data) \
    { { _SHIFTL(G_SETFILLCOLOR, 24, 8), (unsigned int)(data) } }
#define gDPSetDepthImage(pkt, data) \
    _GBI_CMD(pkt, _SHIFTL(G_SETZIMG, 24, 8), (unsigned int)(data))
#define gsDPSetDepthImage(data) \
    { { _SHIFTL(G_SETZIMG, 24, 8), (unsigned int)(data) } }
#define gDPHalf1(pkt, data) \
    _GBI_CMD(pkt, _SHIFTL(G_RDPHALF_1, 24, 8), (unsigned int)(data))
#define gsDPHalf1(data) \
    { { _SHIFTL(G_RDPHALF_1, 24, 8), (unsigned int)(data) } }
#define gDPHalf2(pkt, data) \
    _GBI_CMD(pkt, _SHIFTL(G_RDPHALF_2, 24, 8), (unsigned int)(data))
#define gsDPHalf2(data) \
    { { _SHIFTL(G_RDPHALF_2, 24, 8), (unsigned int)(data) } }
#define gDPSetPrimColor(pkt, m, l, r, g, b, a) \
    _GBI_CMD(pkt, _SHIFTL(G_SETPRIMCOLOR, 24, 8) | _SHIFTL(m, 8, 8) | _SHIFTL(l, 0, 8), _SHIFTL(r, 24, 8) | _SHIFTL(g, 16, 8) | _SHIFTL(b, 8, 8) | _SHIFTL(a, 0, 8))
#define gsDPSetPrimColor(m, l, r, g, b, a) \
    { { _SHIFTL(G_SETPRIMCOLOR, 24, 8) | _SHIFTL(m, 8, 8) | _SHIFTL(l, 0, 8), _SHIFTL(r, 24, 8) | _SHIFTL(g, 16, 8) | _SHIFTL(b, 8, 8) | _SHIFTL(a, 0, 8) } }
#define gDPSetEnvColor(pkt, r, g, b, a) \
    _GBI_CMD(pkt, _SHIFTL(G_SETENVCOLOR, 24, 8), _SHIFTL(r, 24, 8) | _SHIFTL(g, 16, 8) | _SHIFTL(b, 8, 8) | _SHIFTL(a, 0, 8))
#define gsDPSetEnvColor(r, g, b, a) \
    { { _SHIFTL(G_SETENVCOLOR, 24, 8), _SHIFTL(r, 24, 8) | _SHIFTL(g, 16, 8) | _SHIFTL(b, 8, 8) | _SHIFTL(a, 0, 8) } }
#define gDPSetFogColor(pkt, r, g, b, a) \
    _GBI_CMD(pkt, _SHIFTL(G_SETFOGCOLOR, 24, 8), _SHIFTL(r, 24, 8) | _SHIFTL(g, 16, 8) | _SHIFTL(b, 8, 8) | _SHIFTL(a, 0, 8))
#define gsDPSetFogColor(r, g, b, a) \
    { { _SHIFTL(G_SETFOGCOLOR, 24, 8), _SHIFTL(r, 24, 8) | _SHIFTL(g, 16, 8) | _SHIFTL(b, 8, 8) | _SHIFTL(a, 0, 8) } }
#define gDPSetBlendColor(pkt, r, g, b, a) \
    _GBI_CMD(pkt, _SHIFTL(G_SETBLENDCOLOR, 24, 8), _SHIFTL(r, 24, 8) | _SHIFTL(g, 16, 8) | _SHIFTL(b, 8, 8) | _SHIFTL(a, 0, 8))
#define gsDPSetBlendColor(r, g, b, a) \
    { { _SHIFTL(G_SETBLENDCOLOR, 24, 8), _SHIFTL(r, 24, 8) | _SHIFTL(g, 16, 8) | _SHIFTL(b, 8, 8) | _SHIFTL(a, 0, 8) } }
#define gDPSetColorImage(pkt, fmt, siz, width, img) \
    _GBI_CMD(pkt, _SHIFTL(G_SETCIMG, 24, 8) | _SHIFTL(fmt, 21, 3) | _SHIFTL(siz, 19, 2) | _SHIFTL((width) - 1, 0, 12), (unsigned int)(img))
#define gsDPSetColorImage(fmt, siz, width, img) \
    { { _SHIFTL(G_SETCIMG, 24, 8) | _SHIFTL(fmt, 21, 3) | _SHIFTL(siz, 19, 2) | _SHIFTL((width) - 1, 0, 12), (unsigned int)(img) } }
#define gDPSetTextureImage(pkt, fmt, siz, width, img) \
    _GBI_CMD(pkt, _SHIFTL(G_SETTIMG, 24, 8) | _SHIFTL(fmt, 21, 3) | _SHIFTL(siz, 19, 2) | _SHIFTL((width) - 1, 0, 12), (unsigned int)(img))
#define gsDPSetTextureImage(fmt, siz, width, img) \
    { { _SHIFTL(G_SETTIMG, 24, 8) | _SHIFTL(fmt, 21, 3) | _SHIFTL(siz, 19, 2) | _SHIFTL((width) - 1, 0, 12), (unsigned int)(img) } }
#define gDPFillRectangle(pkt, ulx, uly, lrx, lry) \
    _GBI_CMD(pkt, _SHIFTL(G_FILLRECT, 24, 8) | _SHIFTL(lrx, 14, 10) | _SHIFTL(lry, 2, 10), _SHIFTL(ulx, 14, 10) | _SHIFTL(uly, 2, 10))
#define gsDPFillRectangle(ulx, uly, lrx, lry) \
    { { _SHIFTL(G_FILLRECT, 24, 8) | _SHIFTL(lrx, 14, 10) | _SHIFTL(lry, 2, 10), _SHIFTL(ulx, 14, 10) | _SHIFTL(uly, 2, 10) } }
#define gDPSetScissorFrac(pkt, mode, ulx, uly, lrx, lry) \
    _GBI_CMD(pkt, _SHIFTL(G_SETSCISSOR, 24, 8) | _SHIFTL(ulx, 12, 12) | _SHIFTL(uly, 0, 12), _SHIFTL(mode, 24, 2) | _SHIFTL(lrx, 12, 12) | _SHIFTL(lry, 0, 12))
#define gsDPSetScissorFrac(mode, ulx, uly, lrx, lry) \
    { { _SHIFTL(G_SETSCISSOR, 24, 8) | _SHIFTL(ulx, 12, 12) | _SHIFTL(uly, 0, 12), _SHIFTL(mode, 24, 2) | _SHIFTL(lrx, 12, 12) | _SHIFTL(lry, 0, 12) } }
#define gDPSetTile(pkt, fmt, siz, line, tmem, tile, palette, cmt, maskt, shiftt, cms, masks, shifts) \
    _GBI_CMD(pkt, _SHIFTL(G_SETTILE, 24, 8) | _SHIFTL(fmt, 21, 3) | _SHIFTL(siz, 19, 2) | _SHIFTL(line, 9, 9) | _SHIFTL(tmem, 0, 9), _SHIFTL(tile, 24, 3) | _SHIFTL(palette, 20, 4) | _SHIFTL(cmt, 18, 2) | _SHIFTL(maskt, 14, 4) | _SHIFTL(shiftt, 10, 4) | _SHIFTL(cms, 8, 2) | _SHIFTL(masks, 4, 4) | _SHIFTL(shifts, 0, 4))
#define gsDPSetTile(fmt, siz, line, tmem, tile, palette, cmt, maskt, shiftt, cms, masks, shifts) \
    { { _SHIFTL(G_SETTILE, 24, 8) | _SHIFTL(fmt, 21, 3) | _SHIFTL(siz, 19, 2) | _SHIFTL(line, 9, 9) | _SHIFTL(tmem, 0, 9), _SHIFTL(tile, 24, 3) | _SHIFTL(palette, 20, 4) | _SHIFTL(cmt, 18, 2) | _SHIFTL(maskt, 14, 4) | _SHIFTL(shiftt, 10, 4) | _SHIFTL(cms, 8, 2) | _SHIFTL(masks, 4, 4) | _SHIFTL(shifts, 0, 4) } }
#define gDPSetTileSize(pkt, tile, uls, ult, lrs, lrt) \
    _GBI_CMD(pkt, _SHIFTL(G_SETTILESIZE, 24, 8) | _SHIFTL(uls, 12, 12) | _SHIFTL(ult, 0, 12), _SHIFTL(tile, 24, 3) | _SHIFTL(lrs, 12, 12) | _SHIFTL(lrt, 0, 12))
#define gsDPSetTileSize(tile, uls, ult, lrs, lrt) \
    { { _SHIFTL(G_SETTILESIZE, 24, 8) | _SHIFTL(uls, 12, 12) | _SHIFTL(ult, 0, 12), _SHIFTL(tile, 24, 3) | _SHIFTL(lrs, 12, 12) | _SHIFTL(lrt, 0, 12) } }
#define gDPLoadTile(pkt, tile, uls, ult, lrs, lrt) \
    _GBI_CMD(pkt, _SHIFTL(G_LOADTILE, 24, 8) | _SHIFTL(uls, 12, 12) | _SHIFTL(ult, 0, 12), _SHIFTL(tile, 24, 3) | _SHIFTL(lrs, 12, 12) | _SHIFTL(lrt, 0, 12))
#define gsDPLoadTile(tile, uls, ult, lrs, lrt) \
    { { _SHIFTL(G_LOADTILE, 24, 8) | _SHIFTL(uls, 12, 12) | _SHIFTL(ult, 0, 12), _SHIFTL(tile, 24, 3) | _SHIFTL(lrs, 12, 12) | _SHIFTL(lrt, 0, 12) } }
#define gDPLoadBlock(pkt, tile, uls, ult, lrs, dxt) \
    _GBI_CMD(pkt, _SHIFTL(G_LOADBLOCK, 24, 8) | _SHIFTL(uls, 12, 12) | _SHIFTL(ult, 0, 12), _SHIFTL(tile, 24, 3) | _SHIFTL(lrs, 12, 12) | _SHIFTL(dxt, 0, 12))
#define gsDPLoadBlock(tile, uls, ult, lrs, dxt) \
    { { _SHIFTL(G_LOADBLOCK, 24, 8) | _SHIFTL(uls, 12, 12) | _SHIFTL(ult, 0, 12), _SHIFTL(tile, 24, 3) | _SHIFTL(lrs, 12, 12) | _SHIFTL(dxt, 0, 12) } }
#define gDPLoadTLUTCmd(pkt, tile, count) \
    _GBI_CMD(pkt, _SHIFTL(G_LOADTLUT, 24, 8), _SHIFTL(tile, 24, 3) | _SHIFTL(count, 14, 10))
#define gsDPLoadTLUTCmd(tile, count) \
    { { _SHIFTL(G_LOADTLUT, 24, 8), _SHIFTL(tile, 24, 3) | _SHIFTL(count, 14, 10) } }
#define gDPSetPrimDepth(pkt, z, dz) \
    _GBI_CMD(pkt, _SHIFTL(G_SETPRIMDEPTH, 24, 8), _SHIFTL(z, 16, 16) | _SHIFTL(dz, 0, 16))
#define gsDPSetPrimDepth(z, dz) \
    { { _SHIFTL(G_SETPRIMDEPTH, 24, 8), _SHIFTL(z, 16, 16) | _SHIFTL(dz, 0, 16) } }
#define gDPSetCombineLERP(pkt, a0, b0, c0, d0, Aa0, Ab0, Ac0, Ad0, a1, b1, c1, d1, Aa1, Ab1, Ac1, Ad1) \
    _GBI_CMD(pkt, _SHIFTL(G_SETCOMBINE, 24, 8) | _SHIFTL(G_CCMUX_##a0, 20, 4) | _SHIFTL(G_CCMUX_##c0, 15, 5) | _SHIFTL(G_ACMUX_##Aa0, 12, 3) | _SHIFTL(G_ACMUX_##Ac0, 9, 3) | _SHIFTL(G_CCMUX_##a1, 5, 4) | _SHIFTL(G_CCMUX_##c1, 0, 5), _SHIFTL(G_CCMUX_##b0, 28, 4) | _SHIFTL(G_CCMUX_##b1, 24, 4) | _SHIFTL(G_ACMUX_##Aa1, 21, 3) | _SHIFTL(G_ACMUX_##Ac1, 18, 3) | _SHIFTL(G_CCMUX_##d0, 15, 3) | _SHIFTL(G_ACMUX_##Ab0, 12, 3) | _SHIFTL(G_ACMUX_##Ad0, 9, 3) | _SHIFTL(G_CCMUX_##d1, 6, 3) | _SHIFTL(G_ACMUX_##Ab1, 3, 3) | _SHIFTL(G_ACMUX_##Ad1, 0, 3))
#define gsDPSetCombineLERP(a0, b0, c0, d0, Aa0, Ab0, Ac0, Ad0, a1, b1, c1, d1, Aa1, Ab1, Ac1, Ad1) \
    { { _SHIFTL(G_SETCOMBINE, 24, 8) | _SHIFTL(G_CCMUX_##a0, 20, 4) | _SHIFTL(G_CCMUX_##c0, 15, 5) | _SHIFTL(G_ACMUX_##Aa0, 12, 3) | _SHIFTL(G_ACMUX_##Ac0, 9, 3) | _SHIFTL(G_CCMUX_##a1, 5, 4) | _SHIFTL(G_CCMUX_##c1, 0, 5), _SHIFTL(G_CCMUX_##b0, 28, 4) | _SHIFTL(G_CCMUX_##b1, 24, 4) | _SHIFTL(G_ACMUX_##Aa1, 21, 3) | _SHIFTL(G_ACMUX_##Ac1, 18, 3) | _SHIFTL(G_CCMUX_##d0, 15, 3) | _SHIFTL(G_ACMUX_##Ab0, 12, 3) | _SHIFTL(G_ACMUX_##Ad0, 9, 3) | _SHIFTL(G_CCMUX_##d1, 6, 3) | _SHIFTL(G_ACMUX_##Ab1, 3, 3) | _SHIFTL(G_ACMUX_##Ad1, 0, 3) } }
#define gSPDisplayList(pkt, dl) \
    _GBI_CMD(pkt, _SHIFTL(G_DL, 24, 8) | _SHIFTL(G_DL_PUSH, 16, 8), (unsigned int)(dl))
#define gsSPDisplayList(dl) \
    { { _SHIFTL(G_DL, 24, 8) | _SHIFTL(G_DL_PUSH, 16, 8), (unsigned int)(dl) } }
#define gSPBranchList(pkt, dl) \
    _GBI_CMD(pkt, _SHIFTL(G_DL, 24, 8) | _SHIFTL(G_DL_NOPUSH, 16, 8), (unsigned int)(dl))
#define gsSPBranchList(dl) \
    { { _SHIFTL(G_DL, 24, 8) | _SHIFTL(G_DL_NOPUSH, 16, 8), (unsigned int)(dl) } }

#define gDPTexRect(pkt, ulx, uly, lrx, lry, tile) _GBI_CMD(pkt, _SHIFTL(G_TEXRECT,24,8) | _SHIFTL(lrx,12,12) | _SHIFTL(lry,0,12), _SHIFTL(tile,24,3) | _SHIFTL(ulx,12,12) | _SHIFTL(uly,0,12))
#define gsDPTexRect(ulx, uly, lrx, lry, tile) {{ _SHIFTL(G_TEXRECT,24,8) | _SHIFTL(lrx,12,12) | _SHIFTL(lry,0,12), _SHIFTL(tile,24,3) | _SHIFTL(ulx,12,12) | _SHIFTL(uly,0,12) }}
#define gSPTextureRectangle(pkt, ulx, uly, lrx, lry, tile, s, t, dsdx, dtdy) { gDPTexRect(pkt, ulx, uly, lrx, lry, tile); gDPHalf1(pkt, _SHIFTL(s,16,16) | _SHIFTL(t,0,16)); gDPHalf2(pkt, _SHIFTL(dsdx,16,16) | _SHIFTL(dtdy,0,16)); }
#define gsSPTextureRectangle(ulx, uly, lrx, lry, tile, s, t, dsdx, dtdy) gsDPTexRect(ulx, uly, lrx, lry, tile), gsDPHalf1(_SHIFTL(s,16,16) | _SHIFTL(t,0,16)), gsDPHalf2(_SHIFTL(dsdx,16,16) | _SHIFTL(dtdy,0,16))
#define gDPSetScissor(pkt, mode, ulx, uly, lrx, lry) gDPSetScissorFrac(pkt, mode, (int)((float)(ulx) * 4.0F), (int)((float)(uly) * 4.0F), (int)((float)(lrx) * 4.0F), (int)((float)(lry) * 4.0F))
#define gsDPSetScissor(mode, ulx, uly, lrx, lry) gsDPSetScissorFrac(mode, (int)((float)(ulx) * 4.0F), (int)((float)(uly) * 4.0F), (int)((float)(lrx) * 4.0F), (int)((float)(lry) * 4.0F))
#define gDPSetRenderMode(pkt, c1, c2) gSPSetOtherMode(pkt, G_SETOTHERMODE_L, G_MDSFT_RENDERMODE, 29, (c1) | (c2))
#define gsDPSetRenderMode(c1, c2) gsSPSetOtherMode(G_SETOTHERMODE_L, G_MDSFT_RENDERMODE, 29, (c1) | (c2))
#define gSPSegment(pkt, seg, base) gSPMoveWord(pkt, G_MW_SEGMENT, (seg) * 4, base)
#define gsSPSegment(seg, base) gsSPMoveWord(G_MW_SEGMENT, (seg) * 4, base)
#define gDPSetCycleType(pkt, data) gSPSetOtherMode(pkt, G_SETOTHERMODE_H, G_MDSFT_CYCLETYPE, 2, data)
#define gsDPSetCycleType(data) gsSPSetOtherMode(G_SETOTHERMODE_H, G_MDSFT_CYCLETYPE, 2, data)
#define gDPSetTexturePersp(pkt, data) gSPSetOtherMode(pkt, G_SETOTHERMODE_H, G_MDSFT_TEXTPERSP, 1, data)
#define gsDPSetTexturePersp(data) gsSPSetOtherMode(G_SETOTHERMODE_H, G_MDSFT_TEXTPERSP, 1, data)
#define gDPSetTextureDetail(pkt, data) gSPSetOtherMode(pkt, G_SETOTHERMODE_H, G_MDSFT_TEXTDETAIL, 2, data)
#define gsDPSetTextureDetail(data) gsSPSetOtherMode(G_SETOTHERMODE_H, G_MDSFT_TEXTDETAIL, 2, data)
#define gDPSetTextureLOD(pkt, data) gSPSetOtherMode(pkt, G_SETOTHERMODE_H, G_MDSFT_TEXTLOD, 1, data)
#define gsDPSetTextureLOD(data) gsSPSetOtherMode(G_SETOTHERMODE_H, G_MDSFT_TEXTLOD, 1, data)
#define gDPSetTextureLUT(pkt, data) gSPSetOtherMode(pkt, G_SETOTHERMODE_H, G_MDSFT_TEXTLUT, 2, data)
#define gsDPSetTextureLUT(data) gsSPSetOtherMode(G_SETOTHERMODE_H, G_MDSFT_TEXTLUT, 2, data)
#define gDPSetTextureFilter(pkt, data) gSPSetOtherMode(pkt, G_SETOTHERMODE_H, G_MDSFT_TEXTFILT, 2, data)
#define gsDPSetTextureFilter(data) gsSPSetOtherMode(G_SETOTHERMODE_H, G_MDSFT_TEXTFILT, 2, data)
#define gDPSetTextureConvert(pkt, data) gSPSetOtherMode(pkt, G_SETOTHERMODE_H, G_MDSFT_TEXTCONV, 3, data)
#define gsDPSetTextureConvert(data) gsSPSetOtherMode(G_SETOTHERMODE_H, G_MDSFT_TEXTCONV, 3, data)
#define gDPSetCombineKey(pkt, data) gSPSetOtherMode(pkt, G_SETOTHERMODE_H, G_MDSFT_COMBKEY, 1, data)
#define gsDPSetCombineKey(data) gsSPSetOtherMode(G_SETOTHERMODE_H, G_MDSFT_COMBKEY, 1, data)
#define gDPSetColorDither(pkt, data) gSPSetOtherMode(pkt, G_SETOTHERMODE_H, G_MDSFT_RGBDITHER, 2, data)
#define gsDPSetColorDither(data) gsSPSetOtherMode(G_SETOTHERMODE_H, G_MDSFT_RGBDITHER, 2, data)
#define gDPSetAlphaDither(pkt, data) gSPSetOtherMode(pkt, G_SETOTHERMODE_H, G_MDSFT_ALPHADITHER, 2, data)
#define gsDPSetAlphaDither(data) gsSPSetOtherMode(G_SETOTHERMODE_H, G_MDSFT_ALPHADITHER, 2, data)
#define gDPSetPipelineMode(pkt, data) gSPSetOtherMode(pkt, G_SETOTHERMODE_H, G_MDSFT_PIPELINE, 1, data)
#define gsDPSetPipelineMode(data) gsSPSetOtherMode(G_SETOTHERMODE_H, G_MDSFT_PIPELINE, 1, data)
#define gDPSetAlphaCompare(pkt, data) gSPSetOtherMode(pkt, G_SETOTHERMODE_L, G_MDSFT_ALPHACOMPARE, 2, data)
#define gsDPSetAlphaCompare(data) gsSPSetOtherMode(G_SETOTHERMODE_L, G_MDSFT_ALPHACOMPARE, 2, data)
#define gDPSetDepthSource(pkt, data) gSPSetOtherMode(pkt, G_SETOTHERMODE_L, G_MDSFT_ZSRCSEL, 1, data)
#define gsDPSetDepthSource(data) gsSPSetOtherMode(G_SETOTHERMODE_L, G_MDSFT_ZSRCSEL, 1, data)

#endif /* UNBAKE_GBI_H */
