/*
 * Copyright (C) 2018 bzt (bztsrc@github)
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 */

#include <stdio.h>
#include <mini_uart.h>


/*  GIMP header image file format (RGB)  */

unsigned int homer_width = 96;
unsigned int homer_height = 64;

/*  Call this macro repeatedly.  After each use, the pixel data can be extracted  */

#define HEADER_PIXEL(data,pixel) {\
pixel[0] = (((data[0] - 33) << 2) | ((data[1] - 33) >> 4)); \
pixel[1] = ((((data[1] - 33) & 0xF) << 4) | ((data[2] - 33) >> 2)); \
pixel[2] = ((((data[2] - 33) & 0x3) << 6) | ((data[3] - 33))); \
data += 4; \
}
char *homer_data =
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!1)$!Q5*$2=C$\"9B#!U5%BUM'3R((#Z-%S%T#!Y7!A-&!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!#R-?$REJ%2YP%C%W'3F%$BAI$2AM*DJ:#B%7$\"%9%2YR(#^*!A-&"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!#B5A%B]Y$BMK\"1I0'4*+\"B)B!!!!\"1];$\"QV$3>#$C9`$2]T#R9F(D&1"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!#\"1D%S=\\!19,#B)A$B-?(C9N+CMI34Q=?'9>BWY>?75=75E7.T)I'\"E="
	")4)]!!!\"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!1-%%S-X\"QY9#R)>(\"QD=6=FJHUHY\\-L`_1J`_E?`_9A`_AA`_IH`^YIVLM@"
	"F9%O5&*#!1I9\"QQ3!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!%3!\\'2=BFXEU:UU?QJ%VW;EI_^-B`^EA`^EA`^IB`^IB`^IA`^IB`^QA"
	"`^EB\\^%^K*NK!QQC\"AI2!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!$BUR'BI7P:1ZV+-I<F9CQ*=L\\]9A`^U@`^IB`^IB`^IB`^IB`^IB`^IB`^IB"
	"`^IC`.I;`_.#O[^\\\"QQ;!!!\"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!1E1+DB(>6IKV*UOT;%JL9!NU[=K`^QD`^I@`^IB`^IB`^IB`^IB`^IB`^IB`^IB"
	"`^MA`^IC`N9<_^^3A(RD%2IG!!!!!!!!!!!!!!!!!!!#!!!!!!-*!!!%!!!!!!9,"
	"!!!$!!!'!!%\"!!5/$\"-=!!!%!!!!!!!!!!!&#\"!9!!5.!!!!!!!!!!%\"!!!$!!!$"
	"!!%'!!!!!!!$!!!!!!=1#A]:!!!&!!!!!!!\"!!50#!Y8!!)*!!!!!!!$!!!+!!-*"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"#RANE7QKS*=NUJQOT;!LT:UM\\M1F`^M@`^I@`^IB`^IB`^IB`^IB`^IB`^IB`^IB"
	"`^IB`^IB`^ED`NIH[>2V.%*/!!!!!!!!!!!!\"1A+=Y'.O<`$8WJ^DZGCP-,)3&NN"
	"G;7MK\\;])$64I\\#ZQ]H-J\\#U(CU_$C-PH[KRR-P1LLH\"(DB0!!!!(#Y^I+WXL,;^"
	";(\"]OM$'=([/(D\"&KLD!QML/I[SR'3M['#M]JL+`R-H*K<3\\&SV&=Y?:PM@-78+("
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!QU:"
	".CU?WKAUT;%JU*YOTK!MTJQK_N-G`^E>`^IB`^IB`^IB`^IB`^IB`^IB`^IB`^IB"
	"`^IB`^IB`NMA_^I?`_^<B(R2\"B9K!!!!!!!!\"AA+DZG@````DZ?=U^@9````=8B]"
	"[OXOW.D;GJ[@````^0,S````HKOYH[[\\````^00T```^N](%!!M8&#%PX/(D_`T["
	"EJ35````G[7PI\\3[```_]P0S````H;GXG;GW```_]`,S````K<<!AJ#;````>)/9"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1%\"!R)G"
	"FX5OV;)NTJYMTJ]LTJ]LT[%I_N5E`^IB`^IB`^IB`^IB`^IB`^IB`^IB`^IB`^IB"
	"`^IB`^IB`^M@`^AC`.US`_W6%\"QO!!!!!!!!!Q5(?I3/`@\\_LL#Q[?@H````F*/4"
	"````J[?HY?,B\\/XOH;#@```_R=D,P=$\"````J+;I\\O\\P[/PO!!U;'3)OX/,H_`PZ"
	"HJ[?````F:C=X?$C]P,SH*[@_PL[S=L,Q-$%````G:K<\\O`OZ/DL>H[%````9XC1"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!-((31P"
	"R*=QU*YJTJ]LTJ]LTJ]LU+)K_N5E`^EA`^IB`^IB`^IB`^IB`^IB`^IB`^IB`^IB"
	"`^IB`^IB`^IB`^EC`>AB``/\"8&R1!AQ=!!!!!1)$9W^[_@L]S]X/^P<W````P,S]"
	"````C)K.Z/DK\\O\\OIK3E```_S=H+QM4&````K+OM\\_`PZ?HM!R%?'3-OX/,H```^"
	"\\?\\O````F*?=X?(D]`0TIK3E_PL[T-\\1Q-4$````HK#A\\`(OZ?HM:X2]````5'6^"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!-)1U-Z"
	"T*MLT:YNTJ]LTJ]LU*]MU*]I_N5D`^IB`^IB`^IB`^IB`^IB`^IB`^IB`^IB`^IB"
	"`^IB`^IB`^IB`^IB`NA9`_:JGZ2Q!!!*!!!!!!!!5FVI^`DZ\\`$Q_`P\\`P\\_Z?8F"
	"````:(;$Z_@D\\?\\OI[3G`@`_R]L+QM0%````K+OM\\_`PZ?DM\"\"!@'#-OW_0F```_"
	"^P@X````EZC<X?,D]`0TIK3G_PL[S]\\1Q=4%````HK#B\\`$PZODJ9H'\"````/U^D"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!&4%5S"
	"U:UKT:]NTJ]LTJ]LU*]LTZYK_N1F`^IA`^IB`^IB`^IB`^IB`^IC`^IB`^IB`^IB"
	"`^IB`^IB`^IC`^IB`^E=`>^,T-+6$BAK!1)%!!!!0UJ6]@0V````Z/0DYO,B````"
	"````6'W$ZO@G\\?XNHJ_B`P``RML,Q-0&````J+?I\\O\\PZOHM!!U<'#)NX?,G_PT["
	"E*#1````F*C<XO,E]P,SHJ_B_PL[SMT0Q=0&````G:S>\\_`O[?TM77S!^`4S+TV4"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!AA.4%=Y"
	"TZUMT+!NTJ]LTJ]LTZ]LT*QI_.%H`NM?`NE@`^MA`_9@`_=B`_%9`NE?`^EC`^E>"
	"`^AB`NAA`^Q:`_-=`_1B`^YA^.RCDIRO&2YJ!!!!,TF$Z?DH`P``R=<'R=8(````"
	"`0PX7XS>PM@,_0HYT-\\/````N,X$M<L#````T^(2^`@WWNX>!!51'CEXX/0E_@P["
	"EZ+6````G*[HR]X0_PL[T=T/````NLX!L\\?`````S]T._@HVV.L>8X'+\\_\\J1V6N"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!-*1U9^"
	"TJMKTZ]MTZ]LTJ]LTJ]KSZQJ[M)J`^I@_.ABW-%OE(IMAG]JO+%W^N5N_>A@`.I;"
	"`.AC_>=CZ=9VIY]QG9-OS,)T_>ARS<6L+$2#!!!!(CEUU^D;^`DYJL3]GKCW_@LY"
	"Y/4I0%60.6:N]@,V_@L[\\@$S2VJH0&\"=\\?`S_PPY_PX]4G;\"!!!!(#Z\"W>`@]P4T"
	"DZ+4`0X^F+/T3GO%^P8V_PP[]0(R37\"W1&>K[OXQ_@LW_@H[06NZ>YG6```_5GC&"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!-(*#QO"
	"S:ERTJ]KTJ]LTJ]LTJ]LT:QMY<=GPKAHD96EDYW;Q]84T.(<K+GYB8^\\HYY\\\\MUJ"
	"TL!?C8V5BY32P,\\+RMD7FZ?LAHNR=X\".'S9T!!!!!QA.%C1V&#1X$BUK$2UK%S5W"
	"%\"]Q!Q=-!!!\"'CZ#15^>&CAX!!%'!!!&&CE[0%F:(#V!!!)'!!!!\"1I0%2]N%\"]P"
	"%\"QH%\"]P$2MH!!!$'CI\\15Z<&SI_!!!\"!!)'&S5W0%F8(#U_!A5+$\"EE&CA^#B5B"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!)$#2-A"
	"P:-YTK!ITJ]LTJ]LTJ]KWK=T?6I<L;CI]`4W`````````````````P``TMX566%F"
	"CY2Y[OPP````````````````_@L\\IK+G)4.'!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!\"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!\"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1%#!!!\"!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1]D"
	"CWYSV+1JTJ]LTJ]LU+%KGX1@DIS.`````@\\]`P\\_`P\\_`P\\_`P\\_`P\\_```_RM0,"
	"<'RJ`````P\\_`P\\_`P\\_`P\\_`P\\_````8'\"H\"B%<!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\"!1)$!1)$"
	"!1)$!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!&!!)*\"QU5(BY>1%1^,C]C$\"%6!!)(!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\"\"!?"
	"4$QCX+ERT:]MTJYNTJYJ=&UX]P,T``T_]P,T[OLK`````P\\_`P\\_`P\\^`@X\\````"
	">H:Y[?HK```_`P\\_`P\\_````\\?TNXN\\AV^45%#B#!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1)'&S-O4V&*8&F("
	"0%&\"#QY4!!%'!!-)!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!)$!!E@,#5D,#UN-#]MOJ)VRZIIXM)EI:%J%BQL!!!#!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	")C=QSJENU;!LUK%MRZ=KCY\"K_PL\\`@X^@8N^(2U>`````````P\\_`P\\_`P\\_````"
	"L[_QR]@)```_`@X^`@X^````KKCK35J,_P8P#\"Q\\!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!)$&C1QDH!WRJ9ISJIH"
	"TK5P/$-J-4%O*#EN\"2-F!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!1-&%BQOFXYR]MEB^^EHD(9FAW!FY<%N_NAD`>I>C(QQ$29E!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"%#!TGX9FV+5TOI]JRZAOF)NY`@T^```_RM0'H*S=`````P\\_`P\\_`P\\_`P\\_````"
	"L+SMR]@)`````@X^_`P\\`@X^^P4W^`8ZR=$!$SJ%!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\"AU2;6=YTK%OVK%I^>)G"
	"DX=IE()NT:QMTZIO:65Q$REL!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!\"QU9=6MP]=1H`?!>`^A@``!G@W9EJH]MW\\5IY--?RKIH+T9^!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!)$\"B%?"
	"!AY>>6UKL)-M.3AAG8=GC8B7^@8W`0X^`````````@X^`P\\_`P\\_`P\\_`P\\^````"
	":72HM\\#UM<#KHZO1CY.SE)J`Q]8&````5FJI&3-R!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!QM3)3QX;&!A?W!KJI]DMJIL"
	"A'!DW[=UZLUD^^-B_N-K5F%R!AA.!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!1E4!!UJ+SQM=F1DWK9O]N!A`^ME`NI7[=MX/#9:?W)EEXM>F(QH/DAM!!UB"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!A5*&3>\""
	"#S\"\"7V!Y>6ECL)5X;6!A@V]FT=L.`````@X_`P\\_`P\\_`P\\_`P\\``P\\`````KK?T"
	"9VUXQL\"@TLB4X=B6]>FAZ^S';'&8AI;0(3E\\!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!AQ8/4=PLYAOV;]FX])FS;]B9V5A"
	"FX-K[,QI`NM?`_1FK:-A9F)H%BQM!A]?!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!%%)35HQKEQ]MY@MZQI6U!BW+EO^^1D`^]O3DM9N:5K_>1D`^ED`^AB_^9S7V5Z"
	"\"1QB!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!A5)#BUT"
	"$#![04=U;6)FTZMR<F9DMIQM4T]O]0$T```^`@X^`0`]`@\\]`0`V``\\YS=T5:VIN"
	"`_-O`^QB`^A<`NE?`.I>`^YWFY^E)#=Q#!Y3!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!$RAEJ9!RV[5G`.AA`^EF`^I=_.5I"
	">'%HWLIJ_^AH8%Q9D7UORZ9PN)QX.T5Q!15-!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"$\");D8YI`^U=`^I@`_1DT\\9J75A:S+)Q9EU=Q:QR`^Y@`^IA`NI?`^M>`NI8Y-R4"
	"\"1U=!!%$!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1-'$2YX"
	"$\"AJ%R5:85MHUZYNF8-EI8=LRZIS;FIUO<KQZ/0G\\?PR\\?POY.\\EOL;MCHMY^NAF"
	"`>=?`>AB`^AA`NIC`^AD[=-D:6MSI*2>%\"5;!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!11(,T!OR:=PYLUD^.%G`NI>`^EA`^Q@"
	"X]-I@'YI?GAEK)%VY;]J[<]C_^-?W,MJ*#QL!!%$!!!!!!!!!!!!!!!!!!!!!!!!"
	"'C%LMY]E`^MJ`.Q:`>EC`^YAV\\EM44I>FH)K_^9F`^M@`NE<`.MP]>-[_^=<\\^%["
	"/$U`!!%%!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!%#$\"MS"
	"!A1(#B5E?7!FV*YNS*IOQJ-MT[!JX,-CR+QGIZ-_I9^3K*F0OK:&W<UQ^N5KZ]!G"
	"Z\\MV\\]-WZ<AMRZYGDX!=9V%U4E1S?'^&$B-7!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1)355WS:IG]MYIE8YE^N1C`^A>`NE;"
	"`_E^?WV.CGAIX,!F^N)D`^QA_.AEY]9F;'5Y!!)'!!!!!!!!!!!!!!!!!!!!!!!!"
	"*C]XGGUJI9EP`^]D`^AB`>M=^N=>?W=GP:9E`^M?`N=<_^=LZNO\"B8!L_^A=]^5Y"
	"3EJ#!!!\"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1%\"$\"Q["
	"!1-)#B%?EX%RV*]OT;!JTJ]LT:ULYL9J`^IC`^U;__%HP+-P8UQ41#]40SY@/SI>"
	"/3E7-C1/.31:7U=TDX.;S;2]SL32?8\"G'#V&$R9>!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!-'5UIYU:QK_.=>RKAIB8-W`_:$`.9O"
	"``6\\=WR,M9AH_MYI`NI>_NYH;FQAWLYKA(J(!!%'!!!!!!!!!!!!!!!!!!!!!!!!"
	"(#-GIHYI*BA3J)MN^N)A`^EE`>I=FHYCJIQE^.=Z]NN=VM:\\:&9SX]=A`NE=^.J)"
	"55V$!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"\"QY:.DIN8UY@E8)LSZUOT[!LTJYKZ<EF^.1CM:AO75-Q9%M_HI*FPJJPQ:JOQ*BQ"
	"Q*FRQ*JPQ*NQQZRPU[VZV,&_U\\\"]ZM+4N:_!0%2.$\"5A\"1Q6#B!:\"!A/!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!9.4EIUT*QH_.)J`^Y?J:%A?8&3Q<2_"
	"L:^Q04-=QZYP`^]@^.)JBX!H0DA=^.1T<'Z6!!-(!!!!!!!!!!!!!!!!!!!!!!!!"
	"$2)8D'YQ7U-A;F5JR:UQ^]IC]=QI@75GC']EDI-`?G^1@H!L[-EG`^]C`>A>_N^B"
	"8V^7!Q=/!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!QU?"
	"<7)MX\\]HZMIKT,!AS*MNTJ]KT:YKWKUN@GEH?&Z+M)ZHT;F[U+R\\U+Z_U;^_U+Z_"
	"U+Z_U+^^UL\"_U\\'!U\\'!U\\\"_UL#\"U;^`WL7$R+O&2%.':':EC9*Y-DR+!A5)!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!-.(31OH(QNTJQK_-]D`^Q@\\^!E8&-=P+)G"
	"T\\)BU,5J?71GL:5>MJEH>'-IN*MC]NJ3,TF#!A1'!!!!!!!!!!!!!!!!!!!!!!!!"
	"!15)6EQMRJIQ955E9%I=@'!I2D)8CWYJ]=MI]=UMOK!>KJ)F`^]?`^I@`>M>_NR)"
	"QLC#(3UY!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!%#$2-D"
	"P*-N<VIQ+3!1PZUPT[%ITJ]LU;)P@'-K>V^%QJFMV,\"`UL##UL#!UL#!UL&_UL#!"
	"UL#!UL#\"UL#\"UL#!UL#!UL#!UL#!UL#\"V,'!SKZ[P;6`V<C$V\\;*A(2N\"QM2!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!)(&\"YHL)1OV;!QT:YI_.%D`_!CF9%BR+=K`^Q>"
	"`^AA`^ICZ]ADL:9SM:IJX<UH`_6\"F)FA\"R)B!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!%\"-=HXMRV[EQLY9SFH=IQZAWV;%J[]!E`.]9Q;=KMZEE`^UC`^IB`^AB`>I;"
	"`_>GFZ\"K(T&)!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!%##R-?"
	"QJAZD'AGH(1RDX%HW;1PU+!JNY]P3TALNZ&IU\\&_U,'\"UL\"`UL\"`UL\"`UL&^UL\"_"
	"UL#!UL##UL##UL\"`UL'!UL#!UL#!U\\#\"U<'\"UL&YPJZTS[:[SL#\"4V\"3!Q=-!!!!"
	"!!!!!!!!!!!!!!!!!!!!!AA0+4%VKI%LVK)NSZYKW[]I`NEA`NICKJ!LZ=9A`^MC"
	"`NIA`.MC`^MC`_!<`^Y@`_1`T,^])S]_!!%%!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!9.(S1MMIAKW;EPU[-LU+!KT:QLY\\5J`^M@U\\9FZ]9F`^IA`^IB`NIC`NM?"
	"`.IB`_BCHJ:R$BML!A-$!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1Q:"
	"6UINR*5QWK9XU;-WP*!IW+AN:UIEBGB2S[6XU<*^U<&`UL&`UL&_UL&_UL&_UL&_"
	"UL\"`UL#!UL'!UL&_UL&_UL#!UL#!UL#\"UL3!O*>K3DQPPJNPIZ'\"$2AJ!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!97,D)RKY%MV+%OTZYMV;1K^M]B`^MB`^EA_>9C`>A>`^ID"
	"`^IB`^IB`^A>_>II`_NHR\\FZ.U.-!A=0!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!19,+3YVMYALU+!MTJ]LTJUMW;IM`^Q<`^M@_^I@`^IB`^IB`^IB`^IC"
	"`NIC_NA?`>Z2H*>Q%3!S!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"\"B!<,41W4$A72D-<MYIOV[=V/SE9P*2MT;F]U<'#U<&_UL*^UL&_UL&_UL'!UL#!"
	"UL#!UL#!UL'!UL&_UL&_UL#!UL#!UL#!VL6`FX>=#!5&R;7(&#-Q$2AE!A5*!!!!"
	"!!!!!!!!!!!!!!=71$=OQ*5SUK!LSK%MU:YI^-QF`^IB`^IB`^ED`^I@`NMC`^EA"
	"`^IB`^EA_^EM`_[*JJBS*$.\"\"1E0!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!A=.-$)PN)]NUZ]MTZ]NT:MH^]YI`^M?`^IA`^IB`^IB`^IB`^IB"
	"`^IA`^M?`>AA`O.5EYRC)$\"%!!-'!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!\"1M>&UKX;EKPJ)M54QKQ*:MT;R]UL&_UL&_UL'!UL#!UL#!UL#!UL#!"
	"UL'!UL'!UL##UL#!UL#!UL#!UL#!UL#!V<3\"R+\"VNJ*ML*:U\"2%G!!!!!!!!!!!!"
	"!!!!!!!!\"Q];4UI[QZEQUZ]LT:YMUK9H^-YD`^M@`^IB`^IB`^IB`^IB`^IB`^MA"
	"`^ID_^M?`O:YA8BF!2-J!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!E90DAKVK-QU:]LU*UQV[AE`>=D`^IB`^IB`^IB`^IB`^IB"
	"`^IB`^IB`^E?`>E@`_20M[FV*D%^!QE2!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!1U=75ADX;IMOIYK75-TQ*BKU+Z\\UL&_UL&_UL&_UL&_UL&_UL#!UL#!"
	"UL'!UL'!UL##UL#!UL#!UL#!U\\#\"KYZHK)VMXLO+[];56V2-$2QO!!!!!!!!!!!!"
	"!!!%\"!YA;6=QS*ANUK!KTJQRV[MF^N%C`^QB`^IB`^IB`^EA`^IB`^IB`^IB`^IB"
	"`>A=`_*>K;\"U&#-U!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!\"B-K651AW[ATT+%LU*]IZ\\QH`^IA`^ID`^IA`^IA`^IB"
	"`^IA`^IB`^EB`^IB`^A?`^V!S\\^[+$6\"\"1M4!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!922DIAXKQOTK!Q0SUCQZNLT[V]UL#!UL\"`UL&`UL&^UL&_UL#!UL#!"
	"UL#!UL#!UL'\"U<'!U<'!U<'\"U,*_U,##2$5P1%B11UF7(#Z$!!!!!!!!!!!!!!)&"
	"&#%QDH!QUK%QTZ]KTJQPW+MF_^5E`^IB`^IB`^IB`^IB`^IB`^IB`^MA`NEE`NE;"
	"_^Z%Z.33)T%_\"1Q0!1-&!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!%2YMCGIPT[%NTJYNU;)I]]EE`^IA`^I?`^IB`^IB"
	"`^IB`^IB`^IB`^IB`^IB`NA<`_%[X=NS36.9#2-A!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!9/.3A7X[USV[=R7$]?GXRAU;N]UL#\"UL#!UL&`UL&_UL&_UL#!UL#!"
	"UL#!UL#!UL'!U<'!U<'!U,'\"W,'#HY:E)T\"#!!!!!!!!!!!!!!!!!!!!!!9.)SUU"
	"GX1HU[-ITJYLT:UMX<!G`NAE`^E@`^IB`^IB`^IB`^IB`^IB`^IB`^IC`^E@_^QU"
	"^?+.1%B%\"R-?!!!!!!%\"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!)%*#9DNIUPU+!KT:YNV+)J^=MG`^MB`^EC`^IB"
	"`^IB`^IB`^IB`^IB`^IB`^IA`>A>`^]Q[N6C=(\"C#REM!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!AA2,C5;X[UWUK%KM)ET5T]RRK*VUL&`UL##UL&`UL&`UL&`UL\"`UL\"`"
	"UL\"`UL\"`U\\&`UL'!U<'!XLS)KI^G,$-`!!)&!!!!!!!!!!!!!!!!\"21H4E9TN)IN"
	"V[1PTZ]LT*UNYL=D`.9C`^EA`^EB`^IB`^IB`^IB`^IB`^IC`^I@`^E@`>IE_O:["
	"<'N9\"B%B!A1%!!!!!1)$!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!50/3]CU;=WU*YNTZ]MU;-H]]UF`^I@`^IA"
	"`^IC`^IB`^IB`^IB`^EA`^IB`^IB`^I@`>MA_/\"8F:\"H%35^#B%;!!!!!!!!!!!!"
	"!!!!!!!!!AE2,C=;Y+UXTZ]NUK%OA'%MA'6-U\\/!UL&\\UL&`UL#!UL#!UL&_UL&_"
	"UL&_UL&_U\\&_U,+\"Y<S'CH\"2*$6*!A9-!!!!!!!!!!!!\"QE*#\"QY=&QKTJQLU*]K"
	"U*YOSZMHZ\\YF`>EC`^IB`^IB`^IB`^IB`^IB`^IB`^IA`NMC`^AE_^=B`/:GFJ\"Q"
	"&SE\\!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!E<651BT[-LT[!LTJYOV+=J^]]G`^I?"
	"`^IC`^IB`^IB`^IB`^IB`^IB`^IB`^IB`^EA`>A<`_6-P+VH*T%Z\"!I3!!!!!!%$"
	"!!!!!!!!!!9//#M;X[QTT;!LTK!LTJ]M9UAABX\"7SKS!V,+#V,+\"U\\'!U\\&`U\\*`"
	"V,*`V,.`U\\&`P*ZW9VB+%S1X!!!!!!!!!A9/%#%T\"R-C'S-MGH)GW+9RT;!KU*YM"
	"U;!I\\-)F`^I?`^I@`^IB`^IB`^IB`^IB`^IB`^IB`^IB`>ED`>A=`_22R\\O('35Z"
	"!!%#!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!#!Y<=&UOU:]NTZ]JT*]MVK=I^]]D"
	"`^QA`^IA`^IB`^IB`^IB`^IB`^IB`^IB`^IB`^IB`.E@`^]OVL^+6F5V#AU=)39T"
	"!!M9!!!!!!E64$QCWKIOT:]JU;%LV+)NW;MOJI]B=&YWDH6:N*6TSKF]U\\#&S[NY"
	"O*BXG9\"E?7B+9&F'#B5E!!!!!!!!!!1//U\".J+'E=(\"U6%IYH8AJU+%NTJULT[)M"
	"\\=-E`^EB`^EB`^IC`^IB`^IB`^IB`^IB`^MB`^IA`^IB`N=>`_&-U-#!,$R+\"!Y7"
	"!!%\"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!%#$R5@H(ASU[!NTJ]OTJ]LV;9G"
	"^^!C`^IA`^EB`^ID`^IB`^IB`^IB`^IB`^IB`^IB`NMA`^IB`^EC_>=BH9QI3%\"!"
	";WFN\"\"!I!1Y>;F1EZ\\1[V;9ZR:AQLY9KK))ER;IBP[5AC(5D<W)J>7)]9%YU6UMQ"
	"='1SI)I@XM:3T<[-!QA/!!!!!A1'-4Z0Q],#Y.@;Y^L8V=L(B9*`<6-KTK%L]MQE"
	"`^IB`^IC`^IB`^IB`^IB`^IB`^IB`^IB`^MC`>MB`N=?`>MZZ^7,/52)\"QY7!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!))&\"9@LI9VV;)JU*]MTZUP"
	"V[EF_>%E`^I=`^EB`^IB`^IB`^IB`^IB`^IB`^IB`^ID`^IA`^MB`NAB^>A><W6)"
	"Z.X?@(N]&#1`1$EK34QR049R5UZ/:G.BB)7*FJ7>G:CAFZ/2@8W\"<7.(S,!M_NAE"
	"`^U>`^Y?`?&0R\\K((SZ*.5JE.%.8A8R\\WN<4Y^82X>@7XND9Z.H:JKCL@W]^\\-QF"
	"`^Q>`^IA`^IB`^IB`^IB`^IB`^IB`^IB`^IB`>E>_NQT]_/,87&8#2-B!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1.(#%EKI-OU;)LTJ]N"
	"T:UMW;II_>%D`^M@`^IA`^ID`^IB`^IB`^IB`^IB`^IB`^IB`^IC`^M<W<YIB9.`"
	"_`L[[O0C;G2C?H>XY.T<ZO$?Z_(?]/LJ````````````````````P,P\"CY6VUL9F"
	"`^]B`NA>`>M[TM#,E9W.Q,KUWND7D)O/R,[]Y.<6Y.<5X.44Z?(C````V.4=?8*8"
	"U,1=`^Q?`^M@`^IC`^IB`^IB`^IB`^IB`^EB`.QS`OG,=8\"@#B-H!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1-',CYFPZ%TTZ]L"
	"TK!LTZQOV[=G_>%G`^I@`^IC`^IB`^IB`^IB`^IB`^IB`^IB`^EB`_)BCHEAQ]8+"
	"`````0T\\Z?(A7665M[SLZ>P;XN85^`4R`P`_`P\\_`P\\_````GZK=K+?J^@D[559\\"
	"Z]ML`^Q>`.AKV=;-F)_/;'2H````PLW_J+'>X^L8W^<5\\?LK`PX``P\\_`P\\_\\_`P"
	"@H28Y--H`.MA`^MB`^IB`^IB`^IB`^EA`.AC`?K&>X:@%C!S!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1./D1HRZAO"
	"U;!JTJ]LT:]LV[MI_>5A`^MC`^IB`^IB`^IB`^IB`^IB`^IB`^QC]>!A<72-_0DZ"
	"`P\\_`@X^_`LYT]T*96R;V-\\,YN\\<`````P\\_`P\\_`P\\_````/DA\\````````\\/TQ"
	"5%AA^>5A`>AEWMS&3%6&V^@9````^P<X8VZA[O4C]@$P`@\\_`P\\_`P\\_`P\\_```_"
	"X>\\E=7J+]N1B`^MA`^IB`^IB`NE?_^AD__:\\H:6S%3-[!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!95149F"
	"QJ1OU+%LTJ]LT:YMW+UH_N1B`^MA`^IB`^IB`^IB`^IB`^EB`_!AIYQAL;WR````"
	"`P\\_`P\\_````_@@VGZC7G:75^@,S`````P\\_`P\\_````XNX?='ZR`````@X^````"
	"QM(\"H)=I_NA;W=G$6VB6R]@(````````5V25ZO4E`````P\\_`P\\_`P\\_`P\\_`P\\_"
	"````V>0=<G!O^^AC`^MB`^IB`>EG`_VYK;*Y'CQ[!1)#!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!AE3"
	"24IKSJIOTK%IT:]PT:YKW+MG_^5C`^M@`^IA`^IA`^EC`>M>\\-UG<GB2`````P\\^"
	"`P\\_`P\\_`P\\_`P\\_YO(@?8>W]`,S``\\```X```X`````J+/EQM($`````P\\_`P\\_"
	"_PP\\E)K!X=N#>'F(Z/8J8FV?\\OXO````N\\7WDI[1`````P\\_`P\\_`P\\_`P\\_`P\\_"
	"`P\\_````S]X&FI-B`NQC`.E:`_FQJ*VV%S%R\"R%5!!%#!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!1I84$UJSJMTU;!JTJ]LT:UMW[QH_^5F`^IB`^IB`^I@`^IED(MKX.T=`````P`^"
	"`P\\_`P\\_`P\\_`P\\__`PYC);&SMH*XN\\?W^P<W^L<X.T>B)3'[OLK`P\\^`P\\_`P\\_"
	"```_^P<Z7F6-PLK`````^`@Y5V*5````````4ER/`````P\\_`P\\_`P\\_`P\\_`P\\_"
	"`P\\```\\\\_PTZFJ\"_YM)D_/:JP,\"`(3Y^!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!951TQIQZ9NU+%LT[!KTZUMX+]G`.9A`^EB`^YBQ[IEG:?5`@X^`P\\_`P\\_"
	"`P\\_`P\\_`P\\_`P\\_```_Z?8E04M^L;SOI;#CJ++FIK'DL[[Q^`@Y`P\\^`P\\_`P\\_"
	"`P\\_`P`]```````__`X[````O,;Z;':JDYS1BI7(`````P\\_`P\\_`P\\_`P\\_`P\\_"
	"`P\\_`@\\_`P\\]T=\\0IJ6GR<[%+TF+\"!E0!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!\"1U90$1IRZAMU;!NTJ]LT*UJW[UJ`^I>YM->>'N?_0@[`P\\_`P\\_`P\\_"
	"`P\\_`P\\_`P\\_`P\\_``\\`````:W:I^`@X`````P\\``P\\_`P\\_`P\\_`P\\_`P\\_`P\\_"
	"`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_\\/TNEZ+8\\/TM_`P\\`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_"
	"`P\\_`P\\_`P\\_`P``<7RE*$B-\"QY4!!!\"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!=4.3]GPJ1PU+!MTJ]LTZUKT[IK;F]]Y_DH```^`P\\_`P\\_`P\\_"
	"`P\\_`P\\_`P\\_`P\\_``\\`````O,;YO,GY`````P\\_`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_"
	"`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_`0T]GZK?XNTA``\\```\\_`P\\_`P\\_`P\\_`P\\_`P\\_"
	"`P\\_`P\\_`P\\_````BY3($2QK!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!92-CEEKI-PV;5PRZ=O:F)XS=H/`````@\\_`P\\_`P\\_`P\\_"
	"`P\\_`P\\_`P\\_`P\\_`P\\_````[OHKQ=(\"`````P\\_`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_"
	"`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_````O\\K]K;?K`````P\\_`P\\_`P\\_`P\\_`P\\_`P\\_"
	"`P\\_`P\\``P\\]```]<XC\"\"R!9!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!\"QQ7.SQIF(5P6U9HMKSS\\OPH```^`P`_`P\\_`P\\_`P\\_"
	"`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_`@X^`0T]`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_"
	"`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_`0T^4UV1`````P\\_`P\\_`P\\_`P\\_`P\\_`P\\_"
	"`PX_`@T^````GJ[D(C^#!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!\"QM15&.9/TA[OL3VZ.T:X>86\\/DH`PX^`P\\_`P\\_`P\\_"
	"`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_"
	"`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_````='ZQT-P-`````P\\_`P\\_`P\\_`P\\_`P\\_"
	"````^P8VG:O?&39^!Q5)!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!Q9)$\"9EIJW?[_$?X^H6Y.@6X><4Z_4B_`PZ`````P\\`"
	"`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_"
	"`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_````Z/0E76>;`````P\\_`P\\_```_``````\\\\"
	"S-L*8':U#\"1H!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!$%\"IL?XK\"XN@2YNP:Y.<5X><5Y>P:^@8T`P``"
	"`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_"
	"`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_````3%6*```````````````_P\\[_=(K)"
	"'35V!A9+!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1/.4>#KK3EV>(0YNH7XND5X>H8\\/HG"
	"`0T\\`P```P\\_`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_"
	"`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_````\\/TMA9#$Q,`\"V>8:CIO30UJ9%3!R!!-*"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!%&!!A4-DB%=H.]J:_CT-<%UMX-"
	"W^87[/<H^P<W`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_"
	"`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_````N<7W56*6&\"YO$\"]P\"2!?#\"AG\"R)8!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!#!19-#25F(3!J9VZ;"
	";'6D=X\"QSML+`````P\\_`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_"
	"`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_````\\/PM>XO$&#-X\"A9'!1-&!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!%\"!A1'!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!QQ>@8W$\\/8C"
	"Z_(>^P0Q`````P\\_`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_"
	"`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_```_````D:'5%CE\\!Q5&\"!M2!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!%\"!A5)!!!!!!!!!!%#!A1'!!%#!!!!!!!!!!!!!!9/15>6Y><5Y.85"
	"Z.X=`@X]`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_"
	"`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_`@`_````LK[W'SE`#\"!;!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!%\"\"AQ4!!!!!!!!!!!!!A9+)T2.RLW_Y>D:W^85"
	"^`4T`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_"
	"`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_`P\\_`@X^`@X\\G*_H&SI`!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"";



//#include <mbox.h>
#include <lfb.h>

//#include "homer.h"

//extern unsigned int homer_width;
//extern unsigned int homer_height;

void lfb_showpicture()
{
	int x,y;
	unsigned char *ptr=lfb_buffer();
	char *data=homer_data, pixel[4];
//int width = 1920, height = 1060;
//unsigned int pitch = 0;
//unsigned int isrgb = 1;

	ptr += (lfb_height()-homer_height)/2*lfb_pitch() + (lfb_width()-homer_width)*2;
	for(y=0;y<homer_height;y++) {
		for(x=0;x<homer_width;x++) {
			HEADER_PIXEL(data, pixel);
			// the image is in RGB. So if we have an RGB framebuffer, we can copy the pixels
			// directly, but for BGR we must swap R (pixel[0]) and B (pixel[2]) channels.
			*((unsigned int*)ptr)=isrgb ? *((unsigned int *)&pixel) : (unsigned int)(pixel[0]<<16 | pixel[1]<<8 | pixel[2]);
			ptr+=4;
		}
		ptr+=lfb_pitch()-homer_width*4;
	}
}
void kernel_main()
{
	//mini_uart_init_as_stdio();
	puts("Homer demo");
	lfb_init();
	puts("Init finished");
	lfb_showpicture();
	puts("Show finished");

	while(1);
}
