using namespace std;

class Sprites {
	public:

	int Stage = 0;
	int Judgeline = 1;
	int NormalNote = 2;
	int NormalNoteLeft = 3;
	int NormalNoteMiddle = 4;
	int NormalNoteRight = 5;
	int CriticalNote = 6;
	int CriticalNoteLeft = 7;
	int CriticalNoteMiddle = 8;
	int CriticalNoteRight = 9;
	int HoldNote = 10;
	int HoldNoteLeft = 11;
	int HoldNoteMiddle = 12;
	int HoldNoteRight = 13;
	int ScratchNote = 14;
	int ScratchNoteLeft = 15;
	int ScratchNoteMiddle = 16;
	int ScratchNoteRight = 17;
	int ScratchArrow = 18;
	int Hold = 19;
	int Scratch = 20;
	int StageBackground = 21;
	int TouchFeedback = 22;
	int TouchTick = 23;
	int TouchScratchTick = 24;
	int SyncLine = 25;
	int HiddenLine = 26;
	int JudgePerfectPlus = 27;
	int JudgePerfect = 28;
	int JudgeGreat = 29;
	int JudgeGood = 30;
	int JudgeBad = 31;
	int JudgeMiss = 32;
	int JudgeAuto = 33;
	int JudgeFast = 34;
	int JudgeSlow = 35;
	int ComboNormalText = 36;
	int ComboNormal0 = 37;
	int ComboNormal1 = 38;
	int ComboNormal2 = 39;
	int ComboNormal3 = 40;
	int ComboNormal4 = 41;
	int ComboNormal5 = 42;
	int ComboNormal6 = 43;
	int ComboNormal7 = 44;
	int ComboNormal8 = 45;
	int ComboNormal9 = 46;
	int ComboNormalPoint = 47;
	int ComboNormalPercent = 48;
	int ComboFCText = 49;
	int ComboFC0 = 50;
	int ComboFC1 = 51;
	int ComboFC2 = 52;
	int ComboFC3 = 53;
	int ComboFC4 = 54;
	int ComboFC5 = 55;
	int ComboFC6 = 56;
	int ComboFC7 = 57;
	int ComboFC8 = 58;
	int ComboFC9 = 59;
	int ComboFCPoint = 60;
	int ComboFCPercent = 61;
	int ComboAPText = 62;
	int ComboAP0 = 63;
	int ComboAP1 = 64;
	int ComboAP2 = 65;
	int ComboAP3 = 66;
	int ComboAP4 = 67;
	int ComboAP5 = 68;
	int ComboAP6 = 69;
	int ComboAP7 = 70;
	int ComboAP8 = 71;
	int ComboAP9 = 72;
	int ComboAPPoint = 73;
	int ComboAPPercent = 74;
	int GridYellow = 75;
	int SplitLine_1 = 76;
	int SplitLineTrans1_1 = 77;
	int SplitLineTrans2_1 = 78;
	int SplitLine_10010 = 79;
	int SplitLineTrans1_10010 = 80;
	int SplitLineTrans2_10010 = 81;
	int SplitLine_10020 = 82;
	int SplitLineTrans1_10020 = 83;
	int SplitLineTrans2_10020 = 84;
	int SplitLine_10030 = 85;
	int SplitLineTrans1_10030 = 86;
	int SplitLineTrans2_10030 = 87;
	int SplitLine_10040 = 88;
	int SplitLineTrans1_10040 = 89;
	int SplitLineTrans2_10040 = 90;
	int SplitLine_10050 = 91;
	int SplitLineTrans1_10050 = 92;
	int SplitLineTrans2_10050 = 93;
	int SplitLine_10060 = 94;
	int SplitLineTrans1_10060 = 95;
	int SplitLineTrans2_10060 = 96;
	int SplitLine_10070 = 97;
	int SplitLineTrans1_10070 = 98;
	int SplitLineTrans2_10070 = 99;
	int SplitLine_1010 = 100;
	int SplitLineTrans1_1010 = 101;
	int SplitLineTrans2_1010 = 102;
	int SplitLine_10100 = 103;
	int SplitLineTrans1_10100 = 104;
	int SplitLineTrans2_10100 = 105;
	int SplitLine_10110 = 106;
	int SplitLineTrans1_10110 = 107;
	int SplitLineTrans2_10110 = 108;
	int SplitLine_10120 = 109;
	int SplitLineTrans1_10120 = 110;
	int SplitLineTrans2_10120 = 111;
	int SplitLine_10130 = 112;
	int SplitLineTrans1_10130 = 113;
	int SplitLineTrans2_10130 = 114;
	int SplitLine_10140 = 115;
	int SplitLineTrans1_10140 = 116;
	int SplitLineTrans2_10140 = 117;
	int SplitLine_10150 = 118;
	int SplitLineTrans1_10150 = 119;
	int SplitLineTrans2_10150 = 120;
	int SplitLine_10160 = 121;
	int SplitLineTrans1_10160 = 122;
	int SplitLineTrans2_10160 = 123;
	int SplitLine_10161 = 124;
	int SplitLineTrans1_10161 = 125;
	int SplitLineTrans2_10161 = 126;
	int SplitLine_10162 = 127;
	int SplitLineTrans1_10162 = 128;
	int SplitLineTrans2_10162 = 129;
	int SplitLine_10170 = 130;
	int SplitLineTrans1_10170 = 131;
	int SplitLineTrans2_10170 = 132;
	int SplitLine_10180 = 133;
	int SplitLineTrans1_10180 = 134;
	int SplitLineTrans2_10180 = 135;
	int SplitLine_10190 = 136;
	int SplitLineTrans1_10190 = 137;
	int SplitLineTrans2_10190 = 138;
	int SplitLine_10191 = 139;
	int SplitLineTrans1_10191 = 140;
	int SplitLineTrans2_10191 = 141;
	int SplitLine_1020 = 142;
	int SplitLineTrans1_1020 = 143;
	int SplitLineTrans2_1020 = 144;
	int SplitLine_10200 = 145;
	int SplitLineTrans1_10200 = 146;
	int SplitLineTrans2_10200 = 147;
	int SplitLine_10220 = 148;
	int SplitLineTrans1_10220 = 149;
	int SplitLineTrans2_10220 = 150;
	int SplitLine_10230 = 151;
	int SplitLineTrans1_10230 = 152;
	int SplitLineTrans2_10230 = 153;
	int SplitLine_10240 = 154;
	int SplitLineTrans1_10240 = 155;
	int SplitLineTrans2_10240 = 156;
	int SplitLine_10250 = 157;
	int SplitLineTrans1_10250 = 158;
	int SplitLineTrans2_10250 = 159;
	int SplitLine_10260 = 160;
	int SplitLineTrans1_10260 = 161;
	int SplitLineTrans2_10260 = 162;
	int SplitLine_10270 = 163;
	int SplitLineTrans1_10270 = 164;
	int SplitLineTrans2_10270 = 165;
	int SplitLine_10280 = 166;
	int SplitLineTrans1_10280 = 167;
	int SplitLineTrans2_10280 = 168;
	int SplitLine_10290 = 169;
	int SplitLineTrans1_10290 = 170;
	int SplitLineTrans2_10290 = 171;
	int SplitLine_1030 = 172;
	int SplitLineTrans1_1030 = 173;
	int SplitLineTrans2_1030 = 174;
	int SplitLine_10300 = 175;
	int SplitLineTrans1_10300 = 176;
	int SplitLineTrans2_10300 = 177;
	int SplitLine_10310 = 178;
	int SplitLineTrans1_10310 = 179;
	int SplitLineTrans2_10310 = 180;
	int SplitLine_10320 = 181;
	int SplitLineTrans1_10320 = 182;
	int SplitLineTrans2_10320 = 183;
	int SplitLine_10321_1 = 184;
	int SplitLineTrans1_10321_1 = 185;
	int SplitLineTrans2_10321_1 = 186;
	int SplitLine_10321_2 = 187;
	int SplitLineTrans1_10321_2 = 188;
	int SplitLineTrans2_10321_2 = 189;
	int SplitLine_10321_3 = 190;
	int SplitLineTrans1_10321_3 = 191;
	int SplitLineTrans2_10321_3 = 192;
	int SplitLine_10321_4 = 193;
	int SplitLineTrans1_10321_4 = 194;
	int SplitLineTrans2_10321_4 = 195;
	int SplitLine_10321_5 = 196;
	int SplitLineTrans1_10321_5 = 197;
	int SplitLineTrans2_10321_5 = 198;
	int SplitLine_10322_1 = 199;
	int SplitLineTrans1_10322_1 = 200;
	int SplitLineTrans2_10322_1 = 201;
	int SplitLine_10322_2 = 202;
	int SplitLineTrans1_10322_2 = 203;
	int SplitLineTrans2_10322_2 = 204;
	int SplitLine_10322_3 = 205;
	int SplitLineTrans1_10322_3 = 206;
	int SplitLineTrans2_10322_3 = 207;
	int SplitLine_10322_4 = 208;
	int SplitLineTrans1_10322_4 = 209;
	int SplitLineTrans2_10322_4 = 210;
	int SplitLine_10322_5 = 211;
	int SplitLineTrans1_10322_5 = 212;
	int SplitLineTrans2_10322_5 = 213;
	int SplitLine_10323_1 = 214;
	int SplitLineTrans1_10323_1 = 215;
	int SplitLineTrans2_10323_1 = 216;
	int SplitLine_10323_2 = 217;
	int SplitLineTrans1_10323_2 = 218;
	int SplitLineTrans2_10323_2 = 219;
	int SplitLine_10323_3 = 220;
	int SplitLineTrans1_10323_3 = 221;
	int SplitLineTrans2_10323_3 = 222;
	int SplitLine_10323_4 = 223;
	int SplitLineTrans1_10323_4 = 224;
	int SplitLineTrans2_10323_4 = 225;
	int SplitLine_10323_5 = 226;
	int SplitLineTrans1_10323_5 = 227;
	int SplitLineTrans2_10323_5 = 228;
	int SplitLine_10324_1 = 229;
	int SplitLineTrans1_10324_1 = 230;
	int SplitLineTrans2_10324_1 = 231;
	int SplitLine_10324_2 = 232;
	int SplitLineTrans1_10324_2 = 233;
	int SplitLineTrans2_10324_2 = 234;
	int SplitLine_10324_3 = 235;
	int SplitLineTrans1_10324_3 = 236;
	int SplitLineTrans2_10324_3 = 237;
	int SplitLine_10325_1 = 238;
	int SplitLineTrans1_10325_1 = 239;
	int SplitLineTrans2_10325_1 = 240;
	int SplitLine_10325_2 = 241;
	int SplitLineTrans1_10325_2 = 242;
	int SplitLineTrans2_10325_2 = 243;
	int SplitLine_10325_3 = 244;
	int SplitLineTrans1_10325_3 = 245;
	int SplitLineTrans2_10325_3 = 246;
	int SplitLine_10325_4 = 247;
	int SplitLineTrans1_10325_4 = 248;
	int SplitLineTrans2_10325_4 = 249;
	int SplitLine_10326_1 = 250;
	int SplitLineTrans1_10326_1 = 251;
	int SplitLineTrans2_10326_1 = 252;
	int SplitLine_10326_2 = 253;
	int SplitLineTrans1_10326_2 = 254;
	int SplitLineTrans2_10326_2 = 255;
	int SplitLine_10326_3 = 256;
	int SplitLineTrans1_10326_3 = 257;
	int SplitLineTrans2_10326_3 = 258;
	int SplitLine_10326_4 = 259;
	int SplitLineTrans1_10326_4 = 260;
	int SplitLineTrans2_10326_4 = 261;
	int SplitLine_10326_5 = 262;
	int SplitLineTrans1_10326_5 = 263;
	int SplitLineTrans2_10326_5 = 264;
	int SplitLine_10327_1 = 265;
	int SplitLineTrans1_10327_1 = 266;
	int SplitLineTrans2_10327_1 = 267;
	int SplitLine_10327_2 = 268;
	int SplitLineTrans1_10327_2 = 269;
	int SplitLineTrans2_10327_2 = 270;
	int SplitLine_10327_3 = 271;
	int SplitLineTrans1_10327_3 = 272;
	int SplitLineTrans2_10327_3 = 273;
	int SplitLine_10327_4 = 274;
	int SplitLineTrans1_10327_4 = 275;
	int SplitLineTrans2_10327_4 = 276;
	int SplitLine_10328_1 = 277;
	int SplitLineTrans1_10328_1 = 278;
	int SplitLineTrans2_10328_1 = 279;
	int SplitLine_10328_2 = 280;
	int SplitLineTrans1_10328_2 = 281;
	int SplitLineTrans2_10328_2 = 282;
	int SplitLine_10328_3 = 283;
	int SplitLineTrans1_10328_3 = 284;
	int SplitLineTrans2_10328_3 = 285;
	int SplitLine_10328_4 = 286;
	int SplitLineTrans1_10328_4 = 287;
	int SplitLineTrans2_10328_4 = 288;
	int SplitLine_10328_5 = 289;
	int SplitLineTrans1_10328_5 = 290;
	int SplitLineTrans2_10328_5 = 291;
	int SplitLine_10330 = 292;
	int SplitLineTrans1_10330 = 293;
	int SplitLineTrans2_10330 = 294;
	int SplitLine_10340 = 295;
	int SplitLineTrans1_10340 = 296;
	int SplitLineTrans2_10340 = 297;
	int SplitLine_10350 = 298;
	int SplitLineTrans1_10350 = 299;
	int SplitLineTrans2_10350 = 300;
	int SplitLine_10360 = 301;
	int SplitLineTrans1_10360 = 302;
	int SplitLineTrans2_10360 = 303;
	int SplitLine_10361 = 304;
	int SplitLineTrans1_10361 = 305;
	int SplitLineTrans2_10361 = 306;
	int SplitLine_10370 = 307;
	int SplitLineTrans1_10370 = 308;
	int SplitLineTrans2_10370 = 309;
	int SplitLine_10380 = 310;
	int SplitLineTrans1_10380 = 311;
	int SplitLineTrans2_10380 = 312;
	int SplitLine_10390 = 313;
	int SplitLineTrans1_10390 = 314;
	int SplitLineTrans2_10390 = 315;
	int SplitLine_10391 = 316;
	int SplitLineTrans1_10391 = 317;
	int SplitLineTrans2_10391 = 318;
	int SplitLine_10392 = 319;
	int SplitLineTrans1_10392 = 320;
	int SplitLineTrans2_10392 = 321;
	int SplitLine_10393 = 322;
	int SplitLineTrans1_10393 = 323;
	int SplitLineTrans2_10393 = 324;
	int SplitLine_1040 = 325;
	int SplitLineTrans1_1040 = 326;
	int SplitLineTrans2_1040 = 327;
	int SplitLine_10400 = 328;
	int SplitLineTrans1_10400 = 329;
	int SplitLineTrans2_10400 = 330;
	int SplitLine_10410 = 331;
	int SplitLineTrans1_10410 = 332;
	int SplitLineTrans2_10410 = 333;
	int SplitLine_10420 = 334;
	int SplitLineTrans1_10420 = 335;
	int SplitLineTrans2_10420 = 336;
	int SplitLine_10430 = 337;
	int SplitLineTrans1_10430 = 338;
	int SplitLineTrans2_10430 = 339;
	int SplitLine_10440 = 340;
	int SplitLineTrans1_10440 = 341;
	int SplitLineTrans2_10440 = 342;
	int SplitLine_10450 = 343;
	int SplitLineTrans1_10450 = 344;
	int SplitLineTrans2_10450 = 345;
	int SplitLine_10460 = 346;
	int SplitLineTrans1_10460 = 347;
	int SplitLineTrans2_10460 = 348;
	int SplitLine_10461 = 349;
	int SplitLineTrans1_10461 = 350;
	int SplitLineTrans2_10461 = 351;
	int SplitLine_10470 = 352;
	int SplitLineTrans1_10470 = 353;
	int SplitLineTrans2_10470 = 354;
	int SplitLine_10480 = 355;
	int SplitLineTrans1_10480 = 356;
	int SplitLineTrans2_10480 = 357;
	int SplitLine_10481_1 = 358;
	int SplitLineTrans1_10481_1 = 359;
	int SplitLineTrans2_10481_1 = 360;
	int SplitLine_10481_2 = 361;
	int SplitLineTrans1_10481_2 = 362;
	int SplitLineTrans2_10481_2 = 363;
	int SplitLine_10481_3 = 364;
	int SplitLineTrans1_10481_3 = 365;
	int SplitLineTrans2_10481_3 = 366;
	int SplitLine_10482 = 367;
	int SplitLineTrans1_10482 = 368;
	int SplitLineTrans2_10482 = 369;
	int SplitLine_10490 = 370;
	int SplitLineTrans1_10490 = 371;
	int SplitLineTrans2_10490 = 372;
	int SplitLine_1050 = 373;
	int SplitLineTrans1_1050 = 374;
	int SplitLineTrans2_1050 = 375;
	int SplitLine_10500 = 376;
	int SplitLineTrans1_10500 = 377;
	int SplitLineTrans2_10500 = 378;
	int SplitLine_10510_1 = 379;
	int SplitLineTrans1_10510_1 = 380;
	int SplitLineTrans2_10510_1 = 381;
	int SplitLine_10510_2 = 382;
	int SplitLineTrans1_10510_2 = 383;
	int SplitLineTrans2_10510_2 = 384;
	int SplitLine_10510_3 = 385;
	int SplitLineTrans1_10510_3 = 386;
	int SplitLineTrans2_10510_3 = 387;
	int SplitLine_10511_1 = 388;
	int SplitLineTrans1_10511_1 = 389;
	int SplitLineTrans2_10511_1 = 390;
	int SplitLine_10511_2 = 391;
	int SplitLineTrans1_10511_2 = 392;
	int SplitLineTrans2_10511_2 = 393;
	int SplitLine_10511_3 = 394;
	int SplitLineTrans1_10511_3 = 395;
	int SplitLineTrans2_10511_3 = 396;
	int SplitLine_10512_1 = 397;
	int SplitLineTrans1_10512_1 = 398;
	int SplitLineTrans2_10512_1 = 399;
	int SplitLine_10512_2 = 400;
	int SplitLineTrans1_10512_2 = 401;
	int SplitLineTrans2_10512_2 = 402;
	int SplitLine_10513_1 = 403;
	int SplitLineTrans1_10513_1 = 404;
	int SplitLineTrans2_10513_1 = 405;
	int SplitLine_10513_2 = 406;
	int SplitLineTrans1_10513_2 = 407;
	int SplitLineTrans2_10513_2 = 408;
	int SplitLine_10514_1 = 409;
	int SplitLineTrans1_10514_1 = 410;
	int SplitLineTrans2_10514_1 = 411;
	int SplitLine_10514_2 = 412;
	int SplitLineTrans1_10514_2 = 413;
	int SplitLineTrans2_10514_2 = 414;
	int SplitLine_10514_3 = 415;
	int SplitLineTrans1_10514_3 = 416;
	int SplitLineTrans2_10514_3 = 417;
	int SplitLine_10515_1 = 418;
	int SplitLineTrans1_10515_1 = 419;
	int SplitLineTrans2_10515_1 = 420;
	int SplitLine_10515_2 = 421;
	int SplitLineTrans1_10515_2 = 422;
	int SplitLineTrans2_10515_2 = 423;
	int SplitLine_10515_3 = 424;
	int SplitLineTrans1_10515_3 = 425;
	int SplitLineTrans2_10515_3 = 426;
	int SplitLine_10516_1 = 427;
	int SplitLineTrans1_10516_1 = 428;
	int SplitLineTrans2_10516_1 = 429;
	int SplitLine_10516_2 = 430;
	int SplitLineTrans1_10516_2 = 431;
	int SplitLineTrans2_10516_2 = 432;
	int SplitLine_10516_3 = 433;
	int SplitLineTrans1_10516_3 = 434;
	int SplitLineTrans2_10516_3 = 435;
	int SplitLine_10517_1 = 436;
	int SplitLineTrans1_10517_1 = 437;
	int SplitLineTrans2_10517_1 = 438;
	int SplitLine_10517_2 = 439;
	int SplitLineTrans1_10517_2 = 440;
	int SplitLineTrans2_10517_2 = 441;
	int SplitLine_10517_3 = 442;
	int SplitLineTrans1_10517_3 = 443;
	int SplitLineTrans2_10517_3 = 444;
	int SplitLine_10518_1 = 445;
	int SplitLineTrans1_10518_1 = 446;
	int SplitLineTrans2_10518_1 = 447;
	int SplitLine_10518_2 = 448;
	int SplitLineTrans1_10518_2 = 449;
	int SplitLineTrans2_10518_2 = 450;
	int SplitLine_10518_3 = 451;
	int SplitLineTrans1_10518_3 = 452;
	int SplitLineTrans2_10518_3 = 453;
	int SplitLine_10518_4 = 454;
	int SplitLineTrans1_10518_4 = 455;
	int SplitLineTrans2_10518_4 = 456;
	int SplitLine_10518_5 = 457;
	int SplitLineTrans1_10518_5 = 458;
	int SplitLineTrans2_10518_5 = 459;
	int SplitLine_10519_1 = 460;
	int SplitLineTrans1_10519_1 = 461;
	int SplitLineTrans2_10519_1 = 462;
	int SplitLine_10519_2 = 463;
	int SplitLineTrans1_10519_2 = 464;
	int SplitLineTrans2_10519_2 = 465;
	int SplitLine_10519_3 = 466;
	int SplitLineTrans1_10519_3 = 467;
	int SplitLineTrans2_10519_3 = 468;
	int SplitLine_10519_4 = 469;
	int SplitLineTrans1_10519_4 = 470;
	int SplitLineTrans2_10519_4 = 471;
	int SplitLine_10519_5 = 472;
	int SplitLineTrans1_10519_5 = 473;
	int SplitLineTrans2_10519_5 = 474;
	int SplitLine_10530 = 475;
	int SplitLineTrans1_10530 = 476;
	int SplitLineTrans2_10530 = 477;
	int SplitLine_10540 = 478;
	int SplitLineTrans1_10540 = 479;
	int SplitLineTrans2_10540 = 480;
	int SplitLine_10550 = 481;
	int SplitLineTrans1_10550 = 482;
	int SplitLineTrans2_10550 = 483;
	int SplitLine_10560 = 484;
	int SplitLineTrans1_10560 = 485;
	int SplitLineTrans2_10560 = 486;
	int SplitLine_10570 = 487;
	int SplitLineTrans1_10570 = 488;
	int SplitLineTrans2_10570 = 489;
	int SplitLine_10580 = 490;
	int SplitLineTrans1_10580 = 491;
	int SplitLineTrans2_10580 = 492;
	int SplitLine_10590 = 493;
	int SplitLineTrans1_10590 = 494;
	int SplitLineTrans2_10590 = 495;
	int SplitLine_10600 = 496;
	int SplitLineTrans1_10600 = 497;
	int SplitLineTrans2_10600 = 498;
	int SplitLine_1060a = 499;
	int SplitLineTrans1_1060a = 500;
	int SplitLineTrans2_1060a = 501;
	int SplitLine_1060b = 502;
	int SplitLineTrans1_1060b = 503;
	int SplitLineTrans2_1060b = 504;
	int SplitLine_10610 = 505;
	int SplitLineTrans1_10610 = 506;
	int SplitLineTrans2_10610 = 507;
	int SplitLine_10620 = 508;
	int SplitLineTrans1_10620 = 509;
	int SplitLineTrans2_10620 = 510;
	int SplitLine_10630 = 511;
	int SplitLineTrans1_10630 = 512;
	int SplitLineTrans2_10630 = 513;
	int SplitLine_10631 = 514;
	int SplitLineTrans1_10631 = 515;
	int SplitLineTrans2_10631 = 516;
	int SplitLine_10640 = 517;
	int SplitLineTrans1_10640 = 518;
	int SplitLineTrans2_10640 = 519;
	int SplitLine_10650 = 520;
	int SplitLineTrans1_10650 = 521;
	int SplitLineTrans2_10650 = 522;
	int SplitLine_10660 = 523;
	int SplitLineTrans1_10660 = 524;
	int SplitLineTrans2_10660 = 525;
	int SplitLine_10670 = 526;
	int SplitLineTrans1_10670 = 527;
	int SplitLineTrans2_10670 = 528;
	int SplitLine_10680 = 529;
	int SplitLineTrans1_10680 = 530;
	int SplitLineTrans2_10680 = 531;
	int SplitLine_10690 = 532;
	int SplitLineTrans1_10690 = 533;
	int SplitLineTrans2_10690 = 534;
	int SplitLine_1070 = 535;
	int SplitLineTrans1_1070 = 536;
	int SplitLineTrans2_1070 = 537;
	int SplitLine_10710 = 538;
	int SplitLineTrans1_10710 = 539;
	int SplitLineTrans2_10710 = 540;
	int SplitLine_10720 = 541;
	int SplitLineTrans1_10720 = 542;
	int SplitLineTrans2_10720 = 543;
	int SplitLine_10730 = 544;
	int SplitLineTrans1_10730 = 545;
	int SplitLineTrans2_10730 = 546;
	int SplitLine_10740 = 547;
	int SplitLineTrans1_10740 = 548;
	int SplitLineTrans2_10740 = 549;
	int SplitLine_10750 = 550;
	int SplitLineTrans1_10750 = 551;
	int SplitLineTrans2_10750 = 552;
	int SplitLine_10760 = 553;
	int SplitLineTrans1_10760 = 554;
	int SplitLineTrans2_10760 = 555;
	int SplitLine_10770 = 556;
	int SplitLineTrans1_10770 = 557;
	int SplitLineTrans2_10770 = 558;
	int SplitLine_10771 = 559;
	int SplitLineTrans1_10771 = 560;
	int SplitLineTrans2_10771 = 561;
	int SplitLine_10780 = 562;
	int SplitLineTrans1_10780 = 563;
	int SplitLineTrans2_10780 = 564;
	int SplitLine_10790 = 565;
	int SplitLineTrans1_10790 = 566;
	int SplitLineTrans2_10790 = 567;
	int SplitLine_10791 = 568;
	int SplitLineTrans1_10791 = 569;
	int SplitLineTrans2_10791 = 570;
	int SplitLine_10792 = 571;
	int SplitLineTrans1_10792 = 572;
	int SplitLineTrans2_10792 = 573;
	int SplitLine_10800 = 574;
	int SplitLineTrans1_10800 = 575;
	int SplitLineTrans2_10800 = 576;
	int SplitLine_10810 = 577;
	int SplitLineTrans1_10810 = 578;
	int SplitLineTrans2_10810 = 579;
	int SplitLine_10820 = 580;
	int SplitLineTrans1_10820 = 581;
	int SplitLineTrans2_10820 = 582;
	int SplitLine_10830 = 583;
	int SplitLineTrans1_10830 = 584;
	int SplitLineTrans2_10830 = 585;
	int SplitLine_10840 = 586;
	int SplitLineTrans1_10840 = 587;
	int SplitLineTrans2_10840 = 588;
	int SplitLine_10841_1 = 589;
	int SplitLineTrans1_10841_1 = 590;
	int SplitLineTrans2_10841_1 = 591;
	int SplitLine_10841_2 = 592;
	int SplitLineTrans1_10841_2 = 593;
	int SplitLineTrans2_10841_2 = 594;
	int SplitLine_10841_3 = 595;
	int SplitLineTrans1_10841_3 = 596;
	int SplitLineTrans2_10841_3 = 597;
	int SplitLine_10841_4 = 598;
	int SplitLineTrans1_10841_4 = 599;
	int SplitLineTrans2_10841_4 = 600;
	int SplitLine_10841_5 = 601;
	int SplitLineTrans1_10841_5 = 602;
	int SplitLineTrans2_10841_5 = 603;
	int SplitLine_10850 = 604;
	int SplitLineTrans1_10850 = 605;
	int SplitLineTrans2_10850 = 606;
	int SplitLine_10860 = 607;
	int SplitLineTrans1_10860 = 608;
	int SplitLineTrans2_10860 = 609;
	int SplitLine_10870 = 610;
	int SplitLineTrans1_10870 = 611;
	int SplitLineTrans2_10870 = 612;
	int SplitLine_10871 = 613;
	int SplitLineTrans1_10871 = 614;
	int SplitLineTrans2_10871 = 615;
	int SplitLine_10872 = 616;
	int SplitLineTrans1_10872 = 617;
	int SplitLineTrans2_10872 = 618;
	int SplitLine_10873 = 619;
	int SplitLineTrans1_10873 = 620;
	int SplitLineTrans2_10873 = 621;
	int SplitLine_10880 = 622;
	int SplitLineTrans1_10880 = 623;
	int SplitLineTrans2_10880 = 624;
	int SplitLine_10881 = 625;
	int SplitLineTrans1_10881 = 626;
	int SplitLineTrans2_10881 = 627;
	int SplitLine_10890 = 628;
	int SplitLineTrans1_10890 = 629;
	int SplitLineTrans2_10890 = 630;
	int SplitLine_10900 = 631;
	int SplitLineTrans1_10900 = 632;
	int SplitLineTrans2_10900 = 633;
	int SplitLine_10910 = 634;
	int SplitLineTrans1_10910 = 635;
	int SplitLineTrans2_10910 = 636;
	int SplitLine_10911_1 = 637;
	int SplitLineTrans1_10911_1 = 638;
	int SplitLineTrans2_10911_1 = 639;
	int SplitLine_10911_2 = 640;
	int SplitLineTrans1_10911_2 = 641;
	int SplitLineTrans2_10911_2 = 642;
	int SplitLine_10911_3 = 643;
	int SplitLineTrans1_10911_3 = 644;
	int SplitLineTrans2_10911_3 = 645;
	int SplitLine_10920 = 646;
	int SplitLineTrans1_10920 = 647;
	int SplitLineTrans2_10920 = 648;
	int SplitLine_10930 = 649;
	int SplitLineTrans1_10930 = 650;
	int SplitLineTrans2_10930 = 651;
	int SplitLine_10940_1 = 652;
	int SplitLineTrans1_10940_1 = 653;
	int SplitLineTrans2_10940_1 = 654;
	int SplitLine_10940_2 = 655;
	int SplitLineTrans1_10940_2 = 656;
	int SplitLineTrans2_10940_2 = 657;
	int SplitLine_10950 = 658;
	int SplitLineTrans1_10950 = 659;
	int SplitLineTrans2_10950 = 660;
	int SplitLine_10960 = 661;
	int SplitLineTrans1_10960 = 662;
	int SplitLineTrans2_10960 = 663;
	int SplitLine_10970 = 664;
	int SplitLineTrans1_10970 = 665;
	int SplitLineTrans2_10970 = 666;
	int SplitLine_10980 = 667;
	int SplitLineTrans1_10980 = 668;
	int SplitLineTrans2_10980 = 669;
	int SplitLine_10990 = 670;
	int SplitLineTrans1_10990 = 671;
	int SplitLineTrans2_10990 = 672;
	int SplitLine_11000 = 673;
	int SplitLineTrans1_11000 = 674;
	int SplitLineTrans2_11000 = 675;
	int SplitLine_11010 = 676;
	int SplitLineTrans1_11010 = 677;
	int SplitLineTrans2_11010 = 678;
	int SplitLine_11020 = 679;
	int SplitLineTrans1_11020 = 680;
	int SplitLineTrans2_11020 = 681;
	int SplitLine_11030 = 682;
	int SplitLineTrans1_11030 = 683;
	int SplitLineTrans2_11030 = 684;
	int SplitLine_11040 = 685;
	int SplitLineTrans1_11040 = 686;
	int SplitLineTrans2_11040 = 687;
	int SplitLine_11041_1 = 688;
	int SplitLineTrans1_11041_1 = 689;
	int SplitLineTrans2_11041_1 = 690;
	int SplitLine_11041_2 = 691;
	int SplitLineTrans1_11041_2 = 692;
	int SplitLineTrans2_11041_2 = 693;
	int SplitLine_11041_3 = 694;
	int SplitLineTrans1_11041_3 = 695;
	int SplitLineTrans2_11041_3 = 696;
	int SplitLine_11041_4 = 697;
	int SplitLineTrans1_11041_4 = 698;
	int SplitLineTrans2_11041_4 = 699;
	int SplitLine_11041_5 = 700;
	int SplitLineTrans1_11041_5 = 701;
	int SplitLineTrans2_11041_5 = 702;
	int SplitLine_11041_6 = 703;
	int SplitLineTrans1_11041_6 = 704;
	int SplitLineTrans2_11041_6 = 705;
	int SplitLine_11041_7 = 706;
	int SplitLineTrans1_11041_7 = 707;
	int SplitLineTrans2_11041_7 = 708;
	int SplitLine_11050 = 709;
	int SplitLineTrans1_11050 = 710;
	int SplitLineTrans2_11050 = 711;
	int SplitLine_11060 = 712;
	int SplitLineTrans1_11060 = 713;
	int SplitLineTrans2_11060 = 714;
	int SplitLine_11070 = 715;
	int SplitLineTrans1_11070 = 716;
	int SplitLineTrans2_11070 = 717;
	int SplitLine_11080 = 718;
	int SplitLineTrans1_11080 = 719;
	int SplitLineTrans2_11080 = 720;
	int SplitLine_11090_1 = 721;
	int SplitLineTrans1_11090_1 = 722;
	int SplitLineTrans2_11090_1 = 723;
	int SplitLine_11090_2 = 724;
	int SplitLineTrans1_11090_2 = 725;
	int SplitLineTrans2_11090_2 = 726;
	int SplitLine_11091 = 727;
	int SplitLineTrans1_11091 = 728;
	int SplitLineTrans2_11091 = 729;
	int SplitLine_11100 = 730;
	int SplitLineTrans1_11100 = 731;
	int SplitLineTrans2_11100 = 732;
	int SplitLine_11110 = 733;
	int SplitLineTrans1_11110 = 734;
	int SplitLineTrans2_11110 = 735;
	int SplitLine_11111 = 736;
	int SplitLineTrans1_11111 = 737;
	int SplitLineTrans2_11111 = 738;
	int SplitLine_11120 = 739;
	int SplitLineTrans1_11120 = 740;
	int SplitLineTrans2_11120 = 741;
	int SplitLine_11121 = 742;
	int SplitLineTrans1_11121 = 743;
	int SplitLineTrans2_11121 = 744;
	int SplitLine_11122 = 745;
	int SplitLineTrans1_11122 = 746;
	int SplitLineTrans2_11122 = 747;
	int SplitLine_11130 = 748;
	int SplitLineTrans1_11130 = 749;
	int SplitLineTrans2_11130 = 750;
	int SplitLine_11140 = 751;
	int SplitLineTrans1_11140 = 752;
	int SplitLineTrans2_11140 = 753;
	int SplitLine_11150 = 754;
	int SplitLineTrans1_11150 = 755;
	int SplitLineTrans2_11150 = 756;
	int SplitLine_11151 = 757;
	int SplitLineTrans1_11151 = 758;
	int SplitLineTrans2_11151 = 759;
	int SplitLine_11151_1 = 760;
	int SplitLineTrans1_11151_1 = 761;
	int SplitLineTrans2_11151_1 = 762;
	int SplitLine_11160 = 763;
	int SplitLineTrans1_11160 = 764;
	int SplitLineTrans2_11160 = 765;
	int SplitLine_11170 = 766;
	int SplitLineTrans1_11170 = 767;
	int SplitLineTrans2_11170 = 768;
	int SplitLine_11180 = 769;
	int SplitLineTrans1_11180 = 770;
	int SplitLineTrans2_11180 = 771;
	int SplitLine_11190 = 772;
	int SplitLineTrans1_11190 = 773;
	int SplitLineTrans2_11190 = 774;
	int SplitLine_11200 = 775;
	int SplitLineTrans1_11200 = 776;
	int SplitLineTrans2_11200 = 777;
	int SplitLine_11210 = 778;
	int SplitLineTrans1_11210 = 779;
	int SplitLineTrans2_11210 = 780;
	int SplitLine_11211 = 781;
	int SplitLineTrans1_11211 = 782;
	int SplitLineTrans2_11211 = 783;
	int SplitLine_11212 = 784;
	int SplitLineTrans1_11212 = 785;
	int SplitLineTrans2_11212 = 786;
	int SplitLine_11220 = 787;
	int SplitLineTrans1_11220 = 788;
	int SplitLineTrans2_11220 = 789;
	int SplitLine_11230 = 790;
	int SplitLineTrans1_11230 = 791;
	int SplitLineTrans2_11230 = 792;
	int SplitLine_11240 = 793;
	int SplitLineTrans1_11240 = 794;
	int SplitLineTrans2_11240 = 795;
	int SplitLine_11250 = 796;
	int SplitLineTrans1_11250 = 797;
	int SplitLineTrans2_11250 = 798;
	int SplitLine_11260 = 799;
	int SplitLineTrans1_11260 = 800;
	int SplitLineTrans2_11260 = 801;
	int SplitLine_11270 = 802;
	int SplitLineTrans1_11270 = 803;
	int SplitLineTrans2_11270 = 804;
	int SplitLine_11280 = 805;
	int SplitLineTrans1_11280 = 806;
	int SplitLineTrans2_11280 = 807;
	int SplitLine_11290 = 808;
	int SplitLineTrans1_11290 = 809;
	int SplitLineTrans2_11290 = 810;
	int SplitLine_11300 = 811;
	int SplitLineTrans1_11300 = 812;
	int SplitLineTrans2_11300 = 813;
	int SplitLine_11310 = 814;
	int SplitLineTrans1_11310 = 815;
	int SplitLineTrans2_11310 = 816;
	int SplitLine_11320 = 817;
	int SplitLineTrans1_11320 = 818;
	int SplitLineTrans2_11320 = 819;
	int SplitLine_11321 = 820;
	int SplitLineTrans1_11321 = 821;
	int SplitLineTrans2_11321 = 822;
	int SplitLine_11330 = 823;
	int SplitLineTrans1_11330 = 824;
	int SplitLineTrans2_11330 = 825;
	int SplitLine_11331 = 826;
	int SplitLineTrans1_11331 = 827;
	int SplitLineTrans2_11331 = 828;
	int SplitLine_11332 = 829;
	int SplitLineTrans1_11332 = 830;
	int SplitLineTrans2_11332 = 831;
	int SplitLine_11340 = 832;
	int SplitLineTrans1_11340 = 833;
	int SplitLineTrans2_11340 = 834;
	int SplitLine_11350 = 835;
	int SplitLineTrans1_11350 = 836;
	int SplitLineTrans2_11350 = 837;
	int SplitLine_11360 = 838;
	int SplitLineTrans1_11360 = 839;
	int SplitLineTrans2_11360 = 840;
	int SplitLine_2 = 841;
	int SplitLineTrans1_2 = 842;
	int SplitLineTrans2_2 = 843;
	int SplitLine_2010 = 844;
	int SplitLineTrans1_2010 = 845;
	int SplitLineTrans2_2010 = 846;
	int SplitLine_2020 = 847;
	int SplitLineTrans1_2020 = 848;
	int SplitLineTrans2_2020 = 849;
	int SplitLine_2030 = 850;
	int SplitLineTrans1_2030 = 851;
	int SplitLineTrans2_2030 = 852;
	int SplitLine_2040a = 853;
	int SplitLineTrans1_2040a = 854;
	int SplitLineTrans2_2040a = 855;
	int SplitLine_2040b = 856;
	int SplitLineTrans1_2040b = 857;
	int SplitLineTrans2_2040b = 858;
	int SplitLine_2050 = 859;
	int SplitLineTrans1_2050 = 860;
	int SplitLineTrans2_2050 = 861;
	int SplitLine_3 = 862;
	int SplitLineTrans1_3 = 863;
	int SplitLineTrans2_3 = 864;
	int SplitLine_3010 = 865;
	int SplitLineTrans1_3010 = 866;
	int SplitLineTrans2_3010 = 867;
	int SplitLine_3020 = 868;
	int SplitLineTrans1_3020 = 869;
	int SplitLineTrans2_3020 = 870;
	int SplitLine_3030 = 871;
	int SplitLineTrans1_3030 = 872;
	int SplitLineTrans2_3030 = 873;
	int SplitLine_3040 = 874;
	int SplitLineTrans1_3040 = 875;
	int SplitLineTrans2_3040 = 876;
	int SplitLine_3050 = 877;
	int SplitLineTrans1_3050 = 878;
	int SplitLineTrans2_3050 = 879;
	int SplitLine_4 = 880;
	int SplitLineTrans1_4 = 881;
	int SplitLineTrans2_4 = 882;
	int SplitLine_4010 = 883;
	int SplitLineTrans1_4010 = 884;
	int SplitLineTrans2_4010 = 885;
	int SplitLine_4020 = 886;
	int SplitLineTrans1_4020 = 887;
	int SplitLineTrans2_4020 = 888;
	int SplitLine_4030 = 889;
	int SplitLineTrans1_4030 = 890;
	int SplitLineTrans2_4030 = 891;
	int SplitLine_4040 = 892;
	int SplitLineTrans1_4040 = 893;
	int SplitLineTrans2_4040 = 894;
	int SplitLine_4050 = 895;
	int SplitLineTrans1_4050 = 896;
	int SplitLineTrans2_4050 = 897;
	int SplitLine_5 = 898;
	int SplitLineTrans1_5 = 899;
	int SplitLineTrans2_5 = 900;
	int SplitLine_6 = 901;
	int SplitLineTrans1_6 = 902;
	int SplitLineTrans2_6 = 903;
	int SplitLine_7 = 904;
	int SplitLineTrans1_7 = 905;
	int SplitLineTrans2_7 = 906;
	int SplitLine_8 = 907;
	int SplitLineTrans1_8 = 908;
	int SplitLineTrans2_8 = 909;
	int SplitLine_9 = 910;
	int SplitLineTrans1_9 = 911;
	int SplitLineTrans2_9 = 912;
}Sprites;

auto skins = defineSkins<class Sprites>({
	{SkinSpriteName.StageCover, Sprites.Stage},
	{SkinSpriteName.JudgmentLine, Sprites.Judgeline},
	{SkinSpriteName.NoteHeadRed, Sprites.NormalNote},
	{"Sirius Note Red Left", Sprites.NormalNoteLeft},
	{"Sirius Note Red Middle", Sprites.NormalNoteMiddle},
	{"Sirius Note Red Right", Sprites.NormalNoteRight},
	{SkinSpriteName.NoteHeadYellow, Sprites.CriticalNote},
	{"Sirius Note Yellow Left", Sprites.CriticalNoteLeft},
	{"Sirius Note Yellow Middle", Sprites.CriticalNoteMiddle},
	{"Sirius Note Yellow Right", Sprites.CriticalNoteRight},
	{SkinSpriteName.NoteHeadBlue, Sprites.HoldNote},
	{"Sirius Note Blue Left", Sprites.HoldNoteLeft},
	{"Sirius Note Blue Middle", Sprites.HoldNoteMiddle},
	{"Sirius Note Blue Right", Sprites.HoldNoteRight},
	{SkinSpriteName.NoteHeadPurple, Sprites.ScratchNote},
	{"Sirius Note Purple Left", Sprites.ScratchNoteLeft},
	{"Sirius Note Purple Middle", Sprites.ScratchNoteMiddle},
	{"Sirius Note Purple Right", Sprites.ScratchNoteRight},
	{SkinSpriteName.DirectionalMarkerPurple, Sprites.ScratchArrow},
	{SkinSpriteName.NoteConnectionBlue, Sprites.Hold},
	{SkinSpriteName.NoteConnectionPurple, Sprites.Scratch},
	{SkinSpriteName.StageBottomBorder, Sprites.StageBackground},
	{SkinSpriteName.StageMiddle, Sprites.TouchFeedback},
	{SkinSpriteName.NoteTickBlue, Sprites.TouchTick},
	{SkinSpriteName.NoteTickPurple, Sprites.TouchScratchTick},
	{SkinSpriteName.SimultaneousConnectionNeutral, Sprites.SyncLine},
	{"Sirius Hidden Line", Sprites.HiddenLine},
	{"Sirius Judgment Perfect+", Sprites.JudgePerfectPlus},
	{"Sirius Judgment Perfect", Sprites.JudgePerfect},
	{"Sirius Judgment Great", Sprites.JudgeGreat},
	{"Sirius Judgment Good", Sprites.JudgeGood},
	{"Sirius Judgment Bad", Sprites.JudgeBad},
	{"Sirius Judgment Miss", Sprites.JudgeMiss},
	{"Sirius Judgment Auto", Sprites.JudgeAuto},
	{"Sirius Judgment Fast", Sprites.JudgeFast},
	{"Sirius Judgment Slow", Sprites.JudgeSlow},
	{"Sirius Combo Normal", Sprites.ComboNormalText},
	{"Sirius Combo Normal 0", Sprites.ComboNormal0},
	{"Sirius Combo Normal 1", Sprites.ComboNormal1},
	{"Sirius Combo Normal 2", Sprites.ComboNormal2},
	{"Sirius Combo Normal 3", Sprites.ComboNormal3},
	{"Sirius Combo Normal 4", Sprites.ComboNormal4},
	{"Sirius Combo Normal 5", Sprites.ComboNormal5},
	{"Sirius Combo Normal 6", Sprites.ComboNormal6},
	{"Sirius Combo Normal 7", Sprites.ComboNormal7},
	{"Sirius Combo Normal 8", Sprites.ComboNormal8},
	{"Sirius Combo Normal 9", Sprites.ComboNormal9},
	{"Sirius Combo Normal Point", Sprites.ComboNormalPoint},
	{"Sirius Combo Normal Percent", Sprites.ComboNormalPercent},
	{"Sirius Combo FC", Sprites.ComboFCText},
	{"Sirius Combo FC 0", Sprites.ComboFC0},
	{"Sirius Combo FC 1", Sprites.ComboFC1},
	{"Sirius Combo FC 2", Sprites.ComboFC2},
	{"Sirius Combo FC 3", Sprites.ComboFC3},
	{"Sirius Combo FC 4", Sprites.ComboFC4},
	{"Sirius Combo FC 5", Sprites.ComboFC5},
	{"Sirius Combo FC 6", Sprites.ComboFC6},
	{"Sirius Combo FC 7", Sprites.ComboFC7},
	{"Sirius Combo FC 8", Sprites.ComboFC8},
	{"Sirius Combo FC 9", Sprites.ComboFC9},
	{"Sirius Combo FC Point", Sprites.ComboFCPoint},
	{"Sirius Combo FC Percent", Sprites.ComboFCPercent},
	{"Sirius Combo AP", Sprites.ComboAPText},
	{"Sirius Combo AP 0", Sprites.ComboAP0},
	{"Sirius Combo AP 1", Sprites.ComboAP1},
	{"Sirius Combo AP 2", Sprites.ComboAP2},
	{"Sirius Combo AP 3", Sprites.ComboAP3},
	{"Sirius Combo AP 4", Sprites.ComboAP4},
	{"Sirius Combo AP 5", Sprites.ComboAP5},
	{"Sirius Combo AP 6", Sprites.ComboAP6},
	{"Sirius Combo AP 7", Sprites.ComboAP7},
	{"Sirius Combo AP 8", Sprites.ComboAP8},
	{"Sirius Combo AP 9", Sprites.ComboAP9},
	{"Sirius Combo AP Point", Sprites.ComboAPPoint},
	{"Sirius Combo AP Percent", Sprites.ComboAPPercent},
	{SkinSpriteName.GridYellow, Sprites.GridYellow},
	{"Sirius Split Line #1", Sprites.SplitLine_1},
	{"Sirius Split Line Transform 1 #1", Sprites.SplitLineTrans1_1},
	{"Sirius Split Line Transform 2 #1", Sprites.SplitLineTrans2_1},
	{"Sirius Split Line #10010", Sprites.SplitLine_10010},
	{"Sirius Split Line Transform 1 #10010", Sprites.SplitLineTrans1_10010},
	{"Sirius Split Line Transform 2 #10010", Sprites.SplitLineTrans2_10010},
	{"Sirius Split Line #10020", Sprites.SplitLine_10020},
	{"Sirius Split Line Transform 1 #10020", Sprites.SplitLineTrans1_10020},
	{"Sirius Split Line Transform 2 #10020", Sprites.SplitLineTrans2_10020},
	{"Sirius Split Line #10030", Sprites.SplitLine_10030},
	{"Sirius Split Line Transform 1 #10030", Sprites.SplitLineTrans1_10030},
	{"Sirius Split Line Transform 2 #10030", Sprites.SplitLineTrans2_10030},
	{"Sirius Split Line #10040", Sprites.SplitLine_10040},
	{"Sirius Split Line Transform 1 #10040", Sprites.SplitLineTrans1_10040},
	{"Sirius Split Line Transform 2 #10040", Sprites.SplitLineTrans2_10040},
	{"Sirius Split Line #10050", Sprites.SplitLine_10050},
	{"Sirius Split Line Transform 1 #10050", Sprites.SplitLineTrans1_10050},
	{"Sirius Split Line Transform 2 #10050", Sprites.SplitLineTrans2_10050},
	{"Sirius Split Line #10060", Sprites.SplitLine_10060},
	{"Sirius Split Line Transform 1 #10060", Sprites.SplitLineTrans1_10060},
	{"Sirius Split Line Transform 2 #10060", Sprites.SplitLineTrans2_10060},
	{"Sirius Split Line #10070", Sprites.SplitLine_10070},
	{"Sirius Split Line Transform 1 #10070", Sprites.SplitLineTrans1_10070},
	{"Sirius Split Line Transform 2 #10070", Sprites.SplitLineTrans2_10070},
	{"Sirius Split Line #1010", Sprites.SplitLine_1010},
	{"Sirius Split Line Transform 1 #1010", Sprites.SplitLineTrans1_1010},
	{"Sirius Split Line Transform 2 #1010", Sprites.SplitLineTrans2_1010},
	{"Sirius Split Line #10100", Sprites.SplitLine_10100},
	{"Sirius Split Line Transform 1 #10100", Sprites.SplitLineTrans1_10100},
	{"Sirius Split Line Transform 2 #10100", Sprites.SplitLineTrans2_10100},
	{"Sirius Split Line #10110", Sprites.SplitLine_10110},
	{"Sirius Split Line Transform 1 #10110", Sprites.SplitLineTrans1_10110},
	{"Sirius Split Line Transform 2 #10110", Sprites.SplitLineTrans2_10110},
	{"Sirius Split Line #10120", Sprites.SplitLine_10120},
	{"Sirius Split Line Transform 1 #10120", Sprites.SplitLineTrans1_10120},
	{"Sirius Split Line Transform 2 #10120", Sprites.SplitLineTrans2_10120},
	{"Sirius Split Line #10130", Sprites.SplitLine_10130},
	{"Sirius Split Line Transform 1 #10130", Sprites.SplitLineTrans1_10130},
	{"Sirius Split Line Transform 2 #10130", Sprites.SplitLineTrans2_10130},
	{"Sirius Split Line #10140", Sprites.SplitLine_10140},
	{"Sirius Split Line Transform 1 #10140", Sprites.SplitLineTrans1_10140},
	{"Sirius Split Line Transform 2 #10140", Sprites.SplitLineTrans2_10140},
	{"Sirius Split Line #10150", Sprites.SplitLine_10150},
	{"Sirius Split Line Transform 1 #10150", Sprites.SplitLineTrans1_10150},
	{"Sirius Split Line Transform 2 #10150", Sprites.SplitLineTrans2_10150},
	{"Sirius Split Line #10160", Sprites.SplitLine_10160},
	{"Sirius Split Line Transform 1 #10160", Sprites.SplitLineTrans1_10160},
	{"Sirius Split Line Transform 2 #10160", Sprites.SplitLineTrans2_10160},
	{"Sirius Split Line #10161", Sprites.SplitLine_10161},
	{"Sirius Split Line Transform 1 #10161", Sprites.SplitLineTrans1_10161},
	{"Sirius Split Line Transform 2 #10161", Sprites.SplitLineTrans2_10161},
	{"Sirius Split Line #10162", Sprites.SplitLine_10162},
	{"Sirius Split Line Transform 1 #10162", Sprites.SplitLineTrans1_10162},
	{"Sirius Split Line Transform 2 #10162", Sprites.SplitLineTrans2_10162},
	{"Sirius Split Line #10170", Sprites.SplitLine_10170},
	{"Sirius Split Line Transform 1 #10170", Sprites.SplitLineTrans1_10170},
	{"Sirius Split Line Transform 2 #10170", Sprites.SplitLineTrans2_10170},
	{"Sirius Split Line #10180", Sprites.SplitLine_10180},
	{"Sirius Split Line Transform 1 #10180", Sprites.SplitLineTrans1_10180},
	{"Sirius Split Line Transform 2 #10180", Sprites.SplitLineTrans2_10180},
	{"Sirius Split Line #10190", Sprites.SplitLine_10190},
	{"Sirius Split Line Transform 1 #10190", Sprites.SplitLineTrans1_10190},
	{"Sirius Split Line Transform 2 #10190", Sprites.SplitLineTrans2_10190},
	{"Sirius Split Line #10191", Sprites.SplitLine_10191},
	{"Sirius Split Line Transform 1 #10191", Sprites.SplitLineTrans1_10191},
	{"Sirius Split Line Transform 2 #10191", Sprites.SplitLineTrans2_10191},
	{"Sirius Split Line #1020", Sprites.SplitLine_1020},
	{"Sirius Split Line Transform 1 #1020", Sprites.SplitLineTrans1_1020},
	{"Sirius Split Line Transform 2 #1020", Sprites.SplitLineTrans2_1020},
	{"Sirius Split Line #10200", Sprites.SplitLine_10200},
	{"Sirius Split Line Transform 1 #10200", Sprites.SplitLineTrans1_10200},
	{"Sirius Split Line Transform 2 #10200", Sprites.SplitLineTrans2_10200},
	{"Sirius Split Line #10220", Sprites.SplitLine_10220},
	{"Sirius Split Line Transform 1 #10220", Sprites.SplitLineTrans1_10220},
	{"Sirius Split Line Transform 2 #10220", Sprites.SplitLineTrans2_10220},
	{"Sirius Split Line #10230", Sprites.SplitLine_10230},
	{"Sirius Split Line Transform 1 #10230", Sprites.SplitLineTrans1_10230},
	{"Sirius Split Line Transform 2 #10230", Sprites.SplitLineTrans2_10230},
	{"Sirius Split Line #10240", Sprites.SplitLine_10240},
	{"Sirius Split Line Transform 1 #10240", Sprites.SplitLineTrans1_10240},
	{"Sirius Split Line Transform 2 #10240", Sprites.SplitLineTrans2_10240},
	{"Sirius Split Line #10250", Sprites.SplitLine_10250},
	{"Sirius Split Line Transform 1 #10250", Sprites.SplitLineTrans1_10250},
	{"Sirius Split Line Transform 2 #10250", Sprites.SplitLineTrans2_10250},
	{"Sirius Split Line #10260", Sprites.SplitLine_10260},
	{"Sirius Split Line Transform 1 #10260", Sprites.SplitLineTrans1_10260},
	{"Sirius Split Line Transform 2 #10260", Sprites.SplitLineTrans2_10260},
	{"Sirius Split Line #10270", Sprites.SplitLine_10270},
	{"Sirius Split Line Transform 1 #10270", Sprites.SplitLineTrans1_10270},
	{"Sirius Split Line Transform 2 #10270", Sprites.SplitLineTrans2_10270},
	{"Sirius Split Line #10280", Sprites.SplitLine_10280},
	{"Sirius Split Line Transform 1 #10280", Sprites.SplitLineTrans1_10280},
	{"Sirius Split Line Transform 2 #10280", Sprites.SplitLineTrans2_10280},
	{"Sirius Split Line #10290", Sprites.SplitLine_10290},
	{"Sirius Split Line Transform 1 #10290", Sprites.SplitLineTrans1_10290},
	{"Sirius Split Line Transform 2 #10290", Sprites.SplitLineTrans2_10290},
	{"Sirius Split Line #1030", Sprites.SplitLine_1030},
	{"Sirius Split Line Transform 1 #1030", Sprites.SplitLineTrans1_1030},
	{"Sirius Split Line Transform 2 #1030", Sprites.SplitLineTrans2_1030},
	{"Sirius Split Line #10300", Sprites.SplitLine_10300},
	{"Sirius Split Line Transform 1 #10300", Sprites.SplitLineTrans1_10300},
	{"Sirius Split Line Transform 2 #10300", Sprites.SplitLineTrans2_10300},
	{"Sirius Split Line #10310", Sprites.SplitLine_10310},
	{"Sirius Split Line Transform 1 #10310", Sprites.SplitLineTrans1_10310},
	{"Sirius Split Line Transform 2 #10310", Sprites.SplitLineTrans2_10310},
	{"Sirius Split Line #10320", Sprites.SplitLine_10320},
	{"Sirius Split Line Transform 1 #10320", Sprites.SplitLineTrans1_10320},
	{"Sirius Split Line Transform 2 #10320", Sprites.SplitLineTrans2_10320},
	{"Sirius Split Line #10321_1", Sprites.SplitLine_10321_1},
	{"Sirius Split Line Transform 1 #10321_1", Sprites.SplitLineTrans1_10321_1},
	{"Sirius Split Line Transform 2 #10321_1", Sprites.SplitLineTrans2_10321_1},
	{"Sirius Split Line #10321_2", Sprites.SplitLine_10321_2},
	{"Sirius Split Line Transform 1 #10321_2", Sprites.SplitLineTrans1_10321_2},
	{"Sirius Split Line Transform 2 #10321_2", Sprites.SplitLineTrans2_10321_2},
	{"Sirius Split Line #10321_3", Sprites.SplitLine_10321_3},
	{"Sirius Split Line Transform 1 #10321_3", Sprites.SplitLineTrans1_10321_3},
	{"Sirius Split Line Transform 2 #10321_3", Sprites.SplitLineTrans2_10321_3},
	{"Sirius Split Line #10321_4", Sprites.SplitLine_10321_4},
	{"Sirius Split Line Transform 1 #10321_4", Sprites.SplitLineTrans1_10321_4},
	{"Sirius Split Line Transform 2 #10321_4", Sprites.SplitLineTrans2_10321_4},
	{"Sirius Split Line #10321_5", Sprites.SplitLine_10321_5},
	{"Sirius Split Line Transform 1 #10321_5", Sprites.SplitLineTrans1_10321_5},
	{"Sirius Split Line Transform 2 #10321_5", Sprites.SplitLineTrans2_10321_5},
	{"Sirius Split Line #10322_1", Sprites.SplitLine_10322_1},
	{"Sirius Split Line Transform 1 #10322_1", Sprites.SplitLineTrans1_10322_1},
	{"Sirius Split Line Transform 2 #10322_1", Sprites.SplitLineTrans2_10322_1},
	{"Sirius Split Line #10322_2", Sprites.SplitLine_10322_2},
	{"Sirius Split Line Transform 1 #10322_2", Sprites.SplitLineTrans1_10322_2},
	{"Sirius Split Line Transform 2 #10322_2", Sprites.SplitLineTrans2_10322_2},
	{"Sirius Split Line #10322_3", Sprites.SplitLine_10322_3},
	{"Sirius Split Line Transform 1 #10322_3", Sprites.SplitLineTrans1_10322_3},
	{"Sirius Split Line Transform 2 #10322_3", Sprites.SplitLineTrans2_10322_3},
	{"Sirius Split Line #10322_4", Sprites.SplitLine_10322_4},
	{"Sirius Split Line Transform 1 #10322_4", Sprites.SplitLineTrans1_10322_4},
	{"Sirius Split Line Transform 2 #10322_4", Sprites.SplitLineTrans2_10322_4},
	{"Sirius Split Line #10322_5", Sprites.SplitLine_10322_5},
	{"Sirius Split Line Transform 1 #10322_5", Sprites.SplitLineTrans1_10322_5},
	{"Sirius Split Line Transform 2 #10322_5", Sprites.SplitLineTrans2_10322_5},
	{"Sirius Split Line #10323_1", Sprites.SplitLine_10323_1},
	{"Sirius Split Line Transform 1 #10323_1", Sprites.SplitLineTrans1_10323_1},
	{"Sirius Split Line Transform 2 #10323_1", Sprites.SplitLineTrans2_10323_1},
	{"Sirius Split Line #10323_2", Sprites.SplitLine_10323_2},
	{"Sirius Split Line Transform 1 #10323_2", Sprites.SplitLineTrans1_10323_2},
	{"Sirius Split Line Transform 2 #10323_2", Sprites.SplitLineTrans2_10323_2},
	{"Sirius Split Line #10323_3", Sprites.SplitLine_10323_3},
	{"Sirius Split Line Transform 1 #10323_3", Sprites.SplitLineTrans1_10323_3},
	{"Sirius Split Line Transform 2 #10323_3", Sprites.SplitLineTrans2_10323_3},
	{"Sirius Split Line #10323_4", Sprites.SplitLine_10323_4},
	{"Sirius Split Line Transform 1 #10323_4", Sprites.SplitLineTrans1_10323_4},
	{"Sirius Split Line Transform 2 #10323_4", Sprites.SplitLineTrans2_10323_4},
	{"Sirius Split Line #10323_5", Sprites.SplitLine_10323_5},
	{"Sirius Split Line Transform 1 #10323_5", Sprites.SplitLineTrans1_10323_5},
	{"Sirius Split Line Transform 2 #10323_5", Sprites.SplitLineTrans2_10323_5},
	{"Sirius Split Line #10324_1", Sprites.SplitLine_10324_1},
	{"Sirius Split Line Transform 1 #10324_1", Sprites.SplitLineTrans1_10324_1},
	{"Sirius Split Line Transform 2 #10324_1", Sprites.SplitLineTrans2_10324_1},
	{"Sirius Split Line #10324_2", Sprites.SplitLine_10324_2},
	{"Sirius Split Line Transform 1 #10324_2", Sprites.SplitLineTrans1_10324_2},
	{"Sirius Split Line Transform 2 #10324_2", Sprites.SplitLineTrans2_10324_2},
	{"Sirius Split Line #10324_3", Sprites.SplitLine_10324_3},
	{"Sirius Split Line Transform 1 #10324_3", Sprites.SplitLineTrans1_10324_3},
	{"Sirius Split Line Transform 2 #10324_3", Sprites.SplitLineTrans2_10324_3},
	{"Sirius Split Line #10325_1", Sprites.SplitLine_10325_1},
	{"Sirius Split Line Transform 1 #10325_1", Sprites.SplitLineTrans1_10325_1},
	{"Sirius Split Line Transform 2 #10325_1", Sprites.SplitLineTrans2_10325_1},
	{"Sirius Split Line #10325_2", Sprites.SplitLine_10325_2},
	{"Sirius Split Line Transform 1 #10325_2", Sprites.SplitLineTrans1_10325_2},
	{"Sirius Split Line Transform 2 #10325_2", Sprites.SplitLineTrans2_10325_2},
	{"Sirius Split Line #10325_3", Sprites.SplitLine_10325_3},
	{"Sirius Split Line Transform 1 #10325_3", Sprites.SplitLineTrans1_10325_3},
	{"Sirius Split Line Transform 2 #10325_3", Sprites.SplitLineTrans2_10325_3},
	{"Sirius Split Line #10325_4", Sprites.SplitLine_10325_4},
	{"Sirius Split Line Transform 1 #10325_4", Sprites.SplitLineTrans1_10325_4},
	{"Sirius Split Line Transform 2 #10325_4", Sprites.SplitLineTrans2_10325_4},
	{"Sirius Split Line #10326_1", Sprites.SplitLine_10326_1},
	{"Sirius Split Line Transform 1 #10326_1", Sprites.SplitLineTrans1_10326_1},
	{"Sirius Split Line Transform 2 #10326_1", Sprites.SplitLineTrans2_10326_1},
	{"Sirius Split Line #10326_2", Sprites.SplitLine_10326_2},
	{"Sirius Split Line Transform 1 #10326_2", Sprites.SplitLineTrans1_10326_2},
	{"Sirius Split Line Transform 2 #10326_2", Sprites.SplitLineTrans2_10326_2},
	{"Sirius Split Line #10326_3", Sprites.SplitLine_10326_3},
	{"Sirius Split Line Transform 1 #10326_3", Sprites.SplitLineTrans1_10326_3},
	{"Sirius Split Line Transform 2 #10326_3", Sprites.SplitLineTrans2_10326_3},
	{"Sirius Split Line #10326_4", Sprites.SplitLine_10326_4},
	{"Sirius Split Line Transform 1 #10326_4", Sprites.SplitLineTrans1_10326_4},
	{"Sirius Split Line Transform 2 #10326_4", Sprites.SplitLineTrans2_10326_4},
	{"Sirius Split Line #10326_5", Sprites.SplitLine_10326_5},
	{"Sirius Split Line Transform 1 #10326_5", Sprites.SplitLineTrans1_10326_5},
	{"Sirius Split Line Transform 2 #10326_5", Sprites.SplitLineTrans2_10326_5},
	{"Sirius Split Line #10327_1", Sprites.SplitLine_10327_1},
	{"Sirius Split Line Transform 1 #10327_1", Sprites.SplitLineTrans1_10327_1},
	{"Sirius Split Line Transform 2 #10327_1", Sprites.SplitLineTrans2_10327_1},
	{"Sirius Split Line #10327_2", Sprites.SplitLine_10327_2},
	{"Sirius Split Line Transform 1 #10327_2", Sprites.SplitLineTrans1_10327_2},
	{"Sirius Split Line Transform 2 #10327_2", Sprites.SplitLineTrans2_10327_2},
	{"Sirius Split Line #10327_3", Sprites.SplitLine_10327_3},
	{"Sirius Split Line Transform 1 #10327_3", Sprites.SplitLineTrans1_10327_3},
	{"Sirius Split Line Transform 2 #10327_3", Sprites.SplitLineTrans2_10327_3},
	{"Sirius Split Line #10327_4", Sprites.SplitLine_10327_4},
	{"Sirius Split Line Transform 1 #10327_4", Sprites.SplitLineTrans1_10327_4},
	{"Sirius Split Line Transform 2 #10327_4", Sprites.SplitLineTrans2_10327_4},
	{"Sirius Split Line #10328_1", Sprites.SplitLine_10328_1},
	{"Sirius Split Line Transform 1 #10328_1", Sprites.SplitLineTrans1_10328_1},
	{"Sirius Split Line Transform 2 #10328_1", Sprites.SplitLineTrans2_10328_1},
	{"Sirius Split Line #10328_2", Sprites.SplitLine_10328_2},
	{"Sirius Split Line Transform 1 #10328_2", Sprites.SplitLineTrans1_10328_2},
	{"Sirius Split Line Transform 2 #10328_2", Sprites.SplitLineTrans2_10328_2},
	{"Sirius Split Line #10328_3", Sprites.SplitLine_10328_3},
	{"Sirius Split Line Transform 1 #10328_3", Sprites.SplitLineTrans1_10328_3},
	{"Sirius Split Line Transform 2 #10328_3", Sprites.SplitLineTrans2_10328_3},
	{"Sirius Split Line #10328_4", Sprites.SplitLine_10328_4},
	{"Sirius Split Line Transform 1 #10328_4", Sprites.SplitLineTrans1_10328_4},
	{"Sirius Split Line Transform 2 #10328_4", Sprites.SplitLineTrans2_10328_4},
	{"Sirius Split Line #10328_5", Sprites.SplitLine_10328_5},
	{"Sirius Split Line Transform 1 #10328_5", Sprites.SplitLineTrans1_10328_5},
	{"Sirius Split Line Transform 2 #10328_5", Sprites.SplitLineTrans2_10328_5},
	{"Sirius Split Line #10330", Sprites.SplitLine_10330},
	{"Sirius Split Line Transform 1 #10330", Sprites.SplitLineTrans1_10330},
	{"Sirius Split Line Transform 2 #10330", Sprites.SplitLineTrans2_10330},
	{"Sirius Split Line #10340", Sprites.SplitLine_10340},
	{"Sirius Split Line Transform 1 #10340", Sprites.SplitLineTrans1_10340},
	{"Sirius Split Line Transform 2 #10340", Sprites.SplitLineTrans2_10340},
	{"Sirius Split Line #10350", Sprites.SplitLine_10350},
	{"Sirius Split Line Transform 1 #10350", Sprites.SplitLineTrans1_10350},
	{"Sirius Split Line Transform 2 #10350", Sprites.SplitLineTrans2_10350},
	{"Sirius Split Line #10360", Sprites.SplitLine_10360},
	{"Sirius Split Line Transform 1 #10360", Sprites.SplitLineTrans1_10360},
	{"Sirius Split Line Transform 2 #10360", Sprites.SplitLineTrans2_10360},
	{"Sirius Split Line #10361", Sprites.SplitLine_10361},
	{"Sirius Split Line Transform 1 #10361", Sprites.SplitLineTrans1_10361},
	{"Sirius Split Line Transform 2 #10361", Sprites.SplitLineTrans2_10361},
	{"Sirius Split Line #10370", Sprites.SplitLine_10370},
	{"Sirius Split Line Transform 1 #10370", Sprites.SplitLineTrans1_10370},
	{"Sirius Split Line Transform 2 #10370", Sprites.SplitLineTrans2_10370},
	{"Sirius Split Line #10380", Sprites.SplitLine_10380},
	{"Sirius Split Line Transform 1 #10380", Sprites.SplitLineTrans1_10380},
	{"Sirius Split Line Transform 2 #10380", Sprites.SplitLineTrans2_10380},
	{"Sirius Split Line #10390", Sprites.SplitLine_10390},
	{"Sirius Split Line Transform 1 #10390", Sprites.SplitLineTrans1_10390},
	{"Sirius Split Line Transform 2 #10390", Sprites.SplitLineTrans2_10390},
	{"Sirius Split Line #10391", Sprites.SplitLine_10391},
	{"Sirius Split Line Transform 1 #10391", Sprites.SplitLineTrans1_10391},
	{"Sirius Split Line Transform 2 #10391", Sprites.SplitLineTrans2_10391},
	{"Sirius Split Line #10392", Sprites.SplitLine_10392},
	{"Sirius Split Line Transform 1 #10392", Sprites.SplitLineTrans1_10392},
	{"Sirius Split Line Transform 2 #10392", Sprites.SplitLineTrans2_10392},
	{"Sirius Split Line #10393", Sprites.SplitLine_10393},
	{"Sirius Split Line Transform 1 #10393", Sprites.SplitLineTrans1_10393},
	{"Sirius Split Line Transform 2 #10393", Sprites.SplitLineTrans2_10393},
	{"Sirius Split Line #1040", Sprites.SplitLine_1040},
	{"Sirius Split Line Transform 1 #1040", Sprites.SplitLineTrans1_1040},
	{"Sirius Split Line Transform 2 #1040", Sprites.SplitLineTrans2_1040},
	{"Sirius Split Line #10400", Sprites.SplitLine_10400},
	{"Sirius Split Line Transform 1 #10400", Sprites.SplitLineTrans1_10400},
	{"Sirius Split Line Transform 2 #10400", Sprites.SplitLineTrans2_10400},
	{"Sirius Split Line #10410", Sprites.SplitLine_10410},
	{"Sirius Split Line Transform 1 #10410", Sprites.SplitLineTrans1_10410},
	{"Sirius Split Line Transform 2 #10410", Sprites.SplitLineTrans2_10410},
	{"Sirius Split Line #10420", Sprites.SplitLine_10420},
	{"Sirius Split Line Transform 1 #10420", Sprites.SplitLineTrans1_10420},
	{"Sirius Split Line Transform 2 #10420", Sprites.SplitLineTrans2_10420},
	{"Sirius Split Line #10430", Sprites.SplitLine_10430},
	{"Sirius Split Line Transform 1 #10430", Sprites.SplitLineTrans1_10430},
	{"Sirius Split Line Transform 2 #10430", Sprites.SplitLineTrans2_10430},
	{"Sirius Split Line #10440", Sprites.SplitLine_10440},
	{"Sirius Split Line Transform 1 #10440", Sprites.SplitLineTrans1_10440},
	{"Sirius Split Line Transform 2 #10440", Sprites.SplitLineTrans2_10440},
	{"Sirius Split Line #10450", Sprites.SplitLine_10450},
	{"Sirius Split Line Transform 1 #10450", Sprites.SplitLineTrans1_10450},
	{"Sirius Split Line Transform 2 #10450", Sprites.SplitLineTrans2_10450},
	{"Sirius Split Line #10460", Sprites.SplitLine_10460},
	{"Sirius Split Line Transform 1 #10460", Sprites.SplitLineTrans1_10460},
	{"Sirius Split Line Transform 2 #10460", Sprites.SplitLineTrans2_10460},
	{"Sirius Split Line #10461", Sprites.SplitLine_10461},
	{"Sirius Split Line Transform 1 #10461", Sprites.SplitLineTrans1_10461},
	{"Sirius Split Line Transform 2 #10461", Sprites.SplitLineTrans2_10461},
	{"Sirius Split Line #10470", Sprites.SplitLine_10470},
	{"Sirius Split Line Transform 1 #10470", Sprites.SplitLineTrans1_10470},
	{"Sirius Split Line Transform 2 #10470", Sprites.SplitLineTrans2_10470},
	{"Sirius Split Line #10480", Sprites.SplitLine_10480},
	{"Sirius Split Line Transform 1 #10480", Sprites.SplitLineTrans1_10480},
	{"Sirius Split Line Transform 2 #10480", Sprites.SplitLineTrans2_10480},
	{"Sirius Split Line #10481_1", Sprites.SplitLine_10481_1},
	{"Sirius Split Line Transform 1 #10481_1", Sprites.SplitLineTrans1_10481_1},
	{"Sirius Split Line Transform 2 #10481_1", Sprites.SplitLineTrans2_10481_1},
	{"Sirius Split Line #10481_2", Sprites.SplitLine_10481_2},
	{"Sirius Split Line Transform 1 #10481_2", Sprites.SplitLineTrans1_10481_2},
	{"Sirius Split Line Transform 2 #10481_2", Sprites.SplitLineTrans2_10481_2},
	{"Sirius Split Line #10481_3", Sprites.SplitLine_10481_3},
	{"Sirius Split Line Transform 1 #10481_3", Sprites.SplitLineTrans1_10481_3},
	{"Sirius Split Line Transform 2 #10481_3", Sprites.SplitLineTrans2_10481_3},
	{"Sirius Split Line #10482", Sprites.SplitLine_10482},
	{"Sirius Split Line Transform 1 #10482", Sprites.SplitLineTrans1_10482},
	{"Sirius Split Line Transform 2 #10482", Sprites.SplitLineTrans2_10482},
	{"Sirius Split Line #10490", Sprites.SplitLine_10490},
	{"Sirius Split Line Transform 1 #10490", Sprites.SplitLineTrans1_10490},
	{"Sirius Split Line Transform 2 #10490", Sprites.SplitLineTrans2_10490},
	{"Sirius Split Line #1050", Sprites.SplitLine_1050},
	{"Sirius Split Line Transform 1 #1050", Sprites.SplitLineTrans1_1050},
	{"Sirius Split Line Transform 2 #1050", Sprites.SplitLineTrans2_1050},
	{"Sirius Split Line #10500", Sprites.SplitLine_10500},
	{"Sirius Split Line Transform 1 #10500", Sprites.SplitLineTrans1_10500},
	{"Sirius Split Line Transform 2 #10500", Sprites.SplitLineTrans2_10500},
	{"Sirius Split Line #10510_1", Sprites.SplitLine_10510_1},
	{"Sirius Split Line Transform 1 #10510_1", Sprites.SplitLineTrans1_10510_1},
	{"Sirius Split Line Transform 2 #10510_1", Sprites.SplitLineTrans2_10510_1},
	{"Sirius Split Line #10510_2", Sprites.SplitLine_10510_2},
	{"Sirius Split Line Transform 1 #10510_2", Sprites.SplitLineTrans1_10510_2},
	{"Sirius Split Line Transform 2 #10510_2", Sprites.SplitLineTrans2_10510_2},
	{"Sirius Split Line #10510_3", Sprites.SplitLine_10510_3},
	{"Sirius Split Line Transform 1 #10510_3", Sprites.SplitLineTrans1_10510_3},
	{"Sirius Split Line Transform 2 #10510_3", Sprites.SplitLineTrans2_10510_3},
	{"Sirius Split Line #10511_1", Sprites.SplitLine_10511_1},
	{"Sirius Split Line Transform 1 #10511_1", Sprites.SplitLineTrans1_10511_1},
	{"Sirius Split Line Transform 2 #10511_1", Sprites.SplitLineTrans2_10511_1},
	{"Sirius Split Line #10511_2", Sprites.SplitLine_10511_2},
	{"Sirius Split Line Transform 1 #10511_2", Sprites.SplitLineTrans1_10511_2},
	{"Sirius Split Line Transform 2 #10511_2", Sprites.SplitLineTrans2_10511_2},
	{"Sirius Split Line #10511_3", Sprites.SplitLine_10511_3},
	{"Sirius Split Line Transform 1 #10511_3", Sprites.SplitLineTrans1_10511_3},
	{"Sirius Split Line Transform 2 #10511_3", Sprites.SplitLineTrans2_10511_3},
	{"Sirius Split Line #10512_1", Sprites.SplitLine_10512_1},
	{"Sirius Split Line Transform 1 #10512_1", Sprites.SplitLineTrans1_10512_1},
	{"Sirius Split Line Transform 2 #10512_1", Sprites.SplitLineTrans2_10512_1},
	{"Sirius Split Line #10512_2", Sprites.SplitLine_10512_2},
	{"Sirius Split Line Transform 1 #10512_2", Sprites.SplitLineTrans1_10512_2},
	{"Sirius Split Line Transform 2 #10512_2", Sprites.SplitLineTrans2_10512_2},
	{"Sirius Split Line #10513_1", Sprites.SplitLine_10513_1},
	{"Sirius Split Line Transform 1 #10513_1", Sprites.SplitLineTrans1_10513_1},
	{"Sirius Split Line Transform 2 #10513_1", Sprites.SplitLineTrans2_10513_1},
	{"Sirius Split Line #10513_2", Sprites.SplitLine_10513_2},
	{"Sirius Split Line Transform 1 #10513_2", Sprites.SplitLineTrans1_10513_2},
	{"Sirius Split Line Transform 2 #10513_2", Sprites.SplitLineTrans2_10513_2},
	{"Sirius Split Line #10514_1", Sprites.SplitLine_10514_1},
	{"Sirius Split Line Transform 1 #10514_1", Sprites.SplitLineTrans1_10514_1},
	{"Sirius Split Line Transform 2 #10514_1", Sprites.SplitLineTrans2_10514_1},
	{"Sirius Split Line #10514_2", Sprites.SplitLine_10514_2},
	{"Sirius Split Line Transform 1 #10514_2", Sprites.SplitLineTrans1_10514_2},
	{"Sirius Split Line Transform 2 #10514_2", Sprites.SplitLineTrans2_10514_2},
	{"Sirius Split Line #10514_3", Sprites.SplitLine_10514_3},
	{"Sirius Split Line Transform 1 #10514_3", Sprites.SplitLineTrans1_10514_3},
	{"Sirius Split Line Transform 2 #10514_3", Sprites.SplitLineTrans2_10514_3},
	{"Sirius Split Line #10515_1", Sprites.SplitLine_10515_1},
	{"Sirius Split Line Transform 1 #10515_1", Sprites.SplitLineTrans1_10515_1},
	{"Sirius Split Line Transform 2 #10515_1", Sprites.SplitLineTrans2_10515_1},
	{"Sirius Split Line #10515_2", Sprites.SplitLine_10515_2},
	{"Sirius Split Line Transform 1 #10515_2", Sprites.SplitLineTrans1_10515_2},
	{"Sirius Split Line Transform 2 #10515_2", Sprites.SplitLineTrans2_10515_2},
	{"Sirius Split Line #10515_3", Sprites.SplitLine_10515_3},
	{"Sirius Split Line Transform 1 #10515_3", Sprites.SplitLineTrans1_10515_3},
	{"Sirius Split Line Transform 2 #10515_3", Sprites.SplitLineTrans2_10515_3},
	{"Sirius Split Line #10516_1", Sprites.SplitLine_10516_1},
	{"Sirius Split Line Transform 1 #10516_1", Sprites.SplitLineTrans1_10516_1},
	{"Sirius Split Line Transform 2 #10516_1", Sprites.SplitLineTrans2_10516_1},
	{"Sirius Split Line #10516_2", Sprites.SplitLine_10516_2},
	{"Sirius Split Line Transform 1 #10516_2", Sprites.SplitLineTrans1_10516_2},
	{"Sirius Split Line Transform 2 #10516_2", Sprites.SplitLineTrans2_10516_2},
	{"Sirius Split Line #10516_3", Sprites.SplitLine_10516_3},
	{"Sirius Split Line Transform 1 #10516_3", Sprites.SplitLineTrans1_10516_3},
	{"Sirius Split Line Transform 2 #10516_3", Sprites.SplitLineTrans2_10516_3},
	{"Sirius Split Line #10517_1", Sprites.SplitLine_10517_1},
	{"Sirius Split Line Transform 1 #10517_1", Sprites.SplitLineTrans1_10517_1},
	{"Sirius Split Line Transform 2 #10517_1", Sprites.SplitLineTrans2_10517_1},
	{"Sirius Split Line #10517_2", Sprites.SplitLine_10517_2},
	{"Sirius Split Line Transform 1 #10517_2", Sprites.SplitLineTrans1_10517_2},
	{"Sirius Split Line Transform 2 #10517_2", Sprites.SplitLineTrans2_10517_2},
	{"Sirius Split Line #10517_3", Sprites.SplitLine_10517_3},
	{"Sirius Split Line Transform 1 #10517_3", Sprites.SplitLineTrans1_10517_3},
	{"Sirius Split Line Transform 2 #10517_3", Sprites.SplitLineTrans2_10517_3},
	{"Sirius Split Line #10518_1", Sprites.SplitLine_10518_1},
	{"Sirius Split Line Transform 1 #10518_1", Sprites.SplitLineTrans1_10518_1},
	{"Sirius Split Line Transform 2 #10518_1", Sprites.SplitLineTrans2_10518_1},
	{"Sirius Split Line #10518_2", Sprites.SplitLine_10518_2},
	{"Sirius Split Line Transform 1 #10518_2", Sprites.SplitLineTrans1_10518_2},
	{"Sirius Split Line Transform 2 #10518_2", Sprites.SplitLineTrans2_10518_2},
	{"Sirius Split Line #10518_3", Sprites.SplitLine_10518_3},
	{"Sirius Split Line Transform 1 #10518_3", Sprites.SplitLineTrans1_10518_3},
	{"Sirius Split Line Transform 2 #10518_3", Sprites.SplitLineTrans2_10518_3},
	{"Sirius Split Line #10518_4", Sprites.SplitLine_10518_4},
	{"Sirius Split Line Transform 1 #10518_4", Sprites.SplitLineTrans1_10518_4},
	{"Sirius Split Line Transform 2 #10518_4", Sprites.SplitLineTrans2_10518_4},
	{"Sirius Split Line #10518_5", Sprites.SplitLine_10518_5},
	{"Sirius Split Line Transform 1 #10518_5", Sprites.SplitLineTrans1_10518_5},
	{"Sirius Split Line Transform 2 #10518_5", Sprites.SplitLineTrans2_10518_5},
	{"Sirius Split Line #10519_1", Sprites.SplitLine_10519_1},
	{"Sirius Split Line Transform 1 #10519_1", Sprites.SplitLineTrans1_10519_1},
	{"Sirius Split Line Transform 2 #10519_1", Sprites.SplitLineTrans2_10519_1},
	{"Sirius Split Line #10519_2", Sprites.SplitLine_10519_2},
	{"Sirius Split Line Transform 1 #10519_2", Sprites.SplitLineTrans1_10519_2},
	{"Sirius Split Line Transform 2 #10519_2", Sprites.SplitLineTrans2_10519_2},
	{"Sirius Split Line #10519_3", Sprites.SplitLine_10519_3},
	{"Sirius Split Line Transform 1 #10519_3", Sprites.SplitLineTrans1_10519_3},
	{"Sirius Split Line Transform 2 #10519_3", Sprites.SplitLineTrans2_10519_3},
	{"Sirius Split Line #10519_4", Sprites.SplitLine_10519_4},
	{"Sirius Split Line Transform 1 #10519_4", Sprites.SplitLineTrans1_10519_4},
	{"Sirius Split Line Transform 2 #10519_4", Sprites.SplitLineTrans2_10519_4},
	{"Sirius Split Line #10519_5", Sprites.SplitLine_10519_5},
	{"Sirius Split Line Transform 1 #10519_5", Sprites.SplitLineTrans1_10519_5},
	{"Sirius Split Line Transform 2 #10519_5", Sprites.SplitLineTrans2_10519_5},
	{"Sirius Split Line #10530", Sprites.SplitLine_10530},
	{"Sirius Split Line Transform 1 #10530", Sprites.SplitLineTrans1_10530},
	{"Sirius Split Line Transform 2 #10530", Sprites.SplitLineTrans2_10530},
	{"Sirius Split Line #10540", Sprites.SplitLine_10540},
	{"Sirius Split Line Transform 1 #10540", Sprites.SplitLineTrans1_10540},
	{"Sirius Split Line Transform 2 #10540", Sprites.SplitLineTrans2_10540},
	{"Sirius Split Line #10550", Sprites.SplitLine_10550},
	{"Sirius Split Line Transform 1 #10550", Sprites.SplitLineTrans1_10550},
	{"Sirius Split Line Transform 2 #10550", Sprites.SplitLineTrans2_10550},
	{"Sirius Split Line #10560", Sprites.SplitLine_10560},
	{"Sirius Split Line Transform 1 #10560", Sprites.SplitLineTrans1_10560},
	{"Sirius Split Line Transform 2 #10560", Sprites.SplitLineTrans2_10560},
	{"Sirius Split Line #10570", Sprites.SplitLine_10570},
	{"Sirius Split Line Transform 1 #10570", Sprites.SplitLineTrans1_10570},
	{"Sirius Split Line Transform 2 #10570", Sprites.SplitLineTrans2_10570},
	{"Sirius Split Line #10580", Sprites.SplitLine_10580},
	{"Sirius Split Line Transform 1 #10580", Sprites.SplitLineTrans1_10580},
	{"Sirius Split Line Transform 2 #10580", Sprites.SplitLineTrans2_10580},
	{"Sirius Split Line #10590", Sprites.SplitLine_10590},
	{"Sirius Split Line Transform 1 #10590", Sprites.SplitLineTrans1_10590},
	{"Sirius Split Line Transform 2 #10590", Sprites.SplitLineTrans2_10590},
	{"Sirius Split Line #10600", Sprites.SplitLine_10600},
	{"Sirius Split Line Transform 1 #10600", Sprites.SplitLineTrans1_10600},
	{"Sirius Split Line Transform 2 #10600", Sprites.SplitLineTrans2_10600},
	{"Sirius Split Line #1060a", Sprites.SplitLine_1060a},
	{"Sirius Split Line Transform 1 #1060a", Sprites.SplitLineTrans1_1060a},
	{"Sirius Split Line Transform 2 #1060a", Sprites.SplitLineTrans2_1060a},
	{"Sirius Split Line #1060b", Sprites.SplitLine_1060b},
	{"Sirius Split Line Transform 1 #1060b", Sprites.SplitLineTrans1_1060b},
	{"Sirius Split Line Transform 2 #1060b", Sprites.SplitLineTrans2_1060b},
	{"Sirius Split Line #10610", Sprites.SplitLine_10610},
	{"Sirius Split Line Transform 1 #10610", Sprites.SplitLineTrans1_10610},
	{"Sirius Split Line Transform 2 #10610", Sprites.SplitLineTrans2_10610},
	{"Sirius Split Line #10620", Sprites.SplitLine_10620},
	{"Sirius Split Line Transform 1 #10620", Sprites.SplitLineTrans1_10620},
	{"Sirius Split Line Transform 2 #10620", Sprites.SplitLineTrans2_10620},
	{"Sirius Split Line #10630", Sprites.SplitLine_10630},
	{"Sirius Split Line Transform 1 #10630", Sprites.SplitLineTrans1_10630},
	{"Sirius Split Line Transform 2 #10630", Sprites.SplitLineTrans2_10630},
	{"Sirius Split Line #10631", Sprites.SplitLine_10631},
	{"Sirius Split Line Transform 1 #10631", Sprites.SplitLineTrans1_10631},
	{"Sirius Split Line Transform 2 #10631", Sprites.SplitLineTrans2_10631},
	{"Sirius Split Line #10640", Sprites.SplitLine_10640},
	{"Sirius Split Line Transform 1 #10640", Sprites.SplitLineTrans1_10640},
	{"Sirius Split Line Transform 2 #10640", Sprites.SplitLineTrans2_10640},
	{"Sirius Split Line #10650", Sprites.SplitLine_10650},
	{"Sirius Split Line Transform 1 #10650", Sprites.SplitLineTrans1_10650},
	{"Sirius Split Line Transform 2 #10650", Sprites.SplitLineTrans2_10650},
	{"Sirius Split Line #10660", Sprites.SplitLine_10660},
	{"Sirius Split Line Transform 1 #10660", Sprites.SplitLineTrans1_10660},
	{"Sirius Split Line Transform 2 #10660", Sprites.SplitLineTrans2_10660},
	{"Sirius Split Line #10670", Sprites.SplitLine_10670},
	{"Sirius Split Line Transform 1 #10670", Sprites.SplitLineTrans1_10670},
	{"Sirius Split Line Transform 2 #10670", Sprites.SplitLineTrans2_10670},
	{"Sirius Split Line #10680", Sprites.SplitLine_10680},
	{"Sirius Split Line Transform 1 #10680", Sprites.SplitLineTrans1_10680},
	{"Sirius Split Line Transform 2 #10680", Sprites.SplitLineTrans2_10680},
	{"Sirius Split Line #10690", Sprites.SplitLine_10690},
	{"Sirius Split Line Transform 1 #10690", Sprites.SplitLineTrans1_10690},
	{"Sirius Split Line Transform 2 #10690", Sprites.SplitLineTrans2_10690},
	{"Sirius Split Line #1070", Sprites.SplitLine_1070},
	{"Sirius Split Line Transform 1 #1070", Sprites.SplitLineTrans1_1070},
	{"Sirius Split Line Transform 2 #1070", Sprites.SplitLineTrans2_1070},
	{"Sirius Split Line #10710", Sprites.SplitLine_10710},
	{"Sirius Split Line Transform 1 #10710", Sprites.SplitLineTrans1_10710},
	{"Sirius Split Line Transform 2 #10710", Sprites.SplitLineTrans2_10710},
	{"Sirius Split Line #10720", Sprites.SplitLine_10720},
	{"Sirius Split Line Transform 1 #10720", Sprites.SplitLineTrans1_10720},
	{"Sirius Split Line Transform 2 #10720", Sprites.SplitLineTrans2_10720},
	{"Sirius Split Line #10730", Sprites.SplitLine_10730},
	{"Sirius Split Line Transform 1 #10730", Sprites.SplitLineTrans1_10730},
	{"Sirius Split Line Transform 2 #10730", Sprites.SplitLineTrans2_10730},
	{"Sirius Split Line #10740", Sprites.SplitLine_10740},
	{"Sirius Split Line Transform 1 #10740", Sprites.SplitLineTrans1_10740},
	{"Sirius Split Line Transform 2 #10740", Sprites.SplitLineTrans2_10740},
	{"Sirius Split Line #10750", Sprites.SplitLine_10750},
	{"Sirius Split Line Transform 1 #10750", Sprites.SplitLineTrans1_10750},
	{"Sirius Split Line Transform 2 #10750", Sprites.SplitLineTrans2_10750},
	{"Sirius Split Line #10760", Sprites.SplitLine_10760},
	{"Sirius Split Line Transform 1 #10760", Sprites.SplitLineTrans1_10760},
	{"Sirius Split Line Transform 2 #10760", Sprites.SplitLineTrans2_10760},
	{"Sirius Split Line #10770", Sprites.SplitLine_10770},
	{"Sirius Split Line Transform 1 #10770", Sprites.SplitLineTrans1_10770},
	{"Sirius Split Line Transform 2 #10770", Sprites.SplitLineTrans2_10770},
	{"Sirius Split Line #10771", Sprites.SplitLine_10771},
	{"Sirius Split Line Transform 1 #10771", Sprites.SplitLineTrans1_10771},
	{"Sirius Split Line Transform 2 #10771", Sprites.SplitLineTrans2_10771},
	{"Sirius Split Line #10780", Sprites.SplitLine_10780},
	{"Sirius Split Line Transform 1 #10780", Sprites.SplitLineTrans1_10780},
	{"Sirius Split Line Transform 2 #10780", Sprites.SplitLineTrans2_10780},
	{"Sirius Split Line #10790", Sprites.SplitLine_10790},
	{"Sirius Split Line Transform 1 #10790", Sprites.SplitLineTrans1_10790},
	{"Sirius Split Line Transform 2 #10790", Sprites.SplitLineTrans2_10790},
	{"Sirius Split Line #10791", Sprites.SplitLine_10791},
	{"Sirius Split Line Transform 1 #10791", Sprites.SplitLineTrans1_10791},
	{"Sirius Split Line Transform 2 #10791", Sprites.SplitLineTrans2_10791},
	{"Sirius Split Line #10792", Sprites.SplitLine_10792},
	{"Sirius Split Line Transform 1 #10792", Sprites.SplitLineTrans1_10792},
	{"Sirius Split Line Transform 2 #10792", Sprites.SplitLineTrans2_10792},
	{"Sirius Split Line #10800", Sprites.SplitLine_10800},
	{"Sirius Split Line Transform 1 #10800", Sprites.SplitLineTrans1_10800},
	{"Sirius Split Line Transform 2 #10800", Sprites.SplitLineTrans2_10800},
	{"Sirius Split Line #10810", Sprites.SplitLine_10810},
	{"Sirius Split Line Transform 1 #10810", Sprites.SplitLineTrans1_10810},
	{"Sirius Split Line Transform 2 #10810", Sprites.SplitLineTrans2_10810},
	{"Sirius Split Line #10820", Sprites.SplitLine_10820},
	{"Sirius Split Line Transform 1 #10820", Sprites.SplitLineTrans1_10820},
	{"Sirius Split Line Transform 2 #10820", Sprites.SplitLineTrans2_10820},
	{"Sirius Split Line #10830", Sprites.SplitLine_10830},
	{"Sirius Split Line Transform 1 #10830", Sprites.SplitLineTrans1_10830},
	{"Sirius Split Line Transform 2 #10830", Sprites.SplitLineTrans2_10830},
	{"Sirius Split Line #10840", Sprites.SplitLine_10840},
	{"Sirius Split Line Transform 1 #10840", Sprites.SplitLineTrans1_10840},
	{"Sirius Split Line Transform 2 #10840", Sprites.SplitLineTrans2_10840},
	{"Sirius Split Line #10841_1", Sprites.SplitLine_10841_1},
	{"Sirius Split Line Transform 1 #10841_1", Sprites.SplitLineTrans1_10841_1},
	{"Sirius Split Line Transform 2 #10841_1", Sprites.SplitLineTrans2_10841_1},
	{"Sirius Split Line #10841_2", Sprites.SplitLine_10841_2},
	{"Sirius Split Line Transform 1 #10841_2", Sprites.SplitLineTrans1_10841_2},
	{"Sirius Split Line Transform 2 #10841_2", Sprites.SplitLineTrans2_10841_2},
	{"Sirius Split Line #10841_3", Sprites.SplitLine_10841_3},
	{"Sirius Split Line Transform 1 #10841_3", Sprites.SplitLineTrans1_10841_3},
	{"Sirius Split Line Transform 2 #10841_3", Sprites.SplitLineTrans2_10841_3},
	{"Sirius Split Line #10841_4", Sprites.SplitLine_10841_4},
	{"Sirius Split Line Transform 1 #10841_4", Sprites.SplitLineTrans1_10841_4},
	{"Sirius Split Line Transform 2 #10841_4", Sprites.SplitLineTrans2_10841_4},
	{"Sirius Split Line #10841_5", Sprites.SplitLine_10841_5},
	{"Sirius Split Line Transform 1 #10841_5", Sprites.SplitLineTrans1_10841_5},
	{"Sirius Split Line Transform 2 #10841_5", Sprites.SplitLineTrans2_10841_5},
	{"Sirius Split Line #10850", Sprites.SplitLine_10850},
	{"Sirius Split Line Transform 1 #10850", Sprites.SplitLineTrans1_10850},
	{"Sirius Split Line Transform 2 #10850", Sprites.SplitLineTrans2_10850},
	{"Sirius Split Line #10860", Sprites.SplitLine_10860},
	{"Sirius Split Line Transform 1 #10860", Sprites.SplitLineTrans1_10860},
	{"Sirius Split Line Transform 2 #10860", Sprites.SplitLineTrans2_10860},
	{"Sirius Split Line #10870", Sprites.SplitLine_10870},
	{"Sirius Split Line Transform 1 #10870", Sprites.SplitLineTrans1_10870},
	{"Sirius Split Line Transform 2 #10870", Sprites.SplitLineTrans2_10870},
	{"Sirius Split Line #10871", Sprites.SplitLine_10871},
	{"Sirius Split Line Transform 1 #10871", Sprites.SplitLineTrans1_10871},
	{"Sirius Split Line Transform 2 #10871", Sprites.SplitLineTrans2_10871},
	{"Sirius Split Line #10872", Sprites.SplitLine_10872},
	{"Sirius Split Line Transform 1 #10872", Sprites.SplitLineTrans1_10872},
	{"Sirius Split Line Transform 2 #10872", Sprites.SplitLineTrans2_10872},
	{"Sirius Split Line #10873", Sprites.SplitLine_10873},
	{"Sirius Split Line Transform 1 #10873", Sprites.SplitLineTrans1_10873},
	{"Sirius Split Line Transform 2 #10873", Sprites.SplitLineTrans2_10873},
	{"Sirius Split Line #10880", Sprites.SplitLine_10880},
	{"Sirius Split Line Transform 1 #10880", Sprites.SplitLineTrans1_10880},
	{"Sirius Split Line Transform 2 #10880", Sprites.SplitLineTrans2_10880},
	{"Sirius Split Line #10881", Sprites.SplitLine_10881},
	{"Sirius Split Line Transform 1 #10881", Sprites.SplitLineTrans1_10881},
	{"Sirius Split Line Transform 2 #10881", Sprites.SplitLineTrans2_10881},
	{"Sirius Split Line #10890", Sprites.SplitLine_10890},
	{"Sirius Split Line Transform 1 #10890", Sprites.SplitLineTrans1_10890},
	{"Sirius Split Line Transform 2 #10890", Sprites.SplitLineTrans2_10890},
	{"Sirius Split Line #10900", Sprites.SplitLine_10900},
	{"Sirius Split Line Transform 1 #10900", Sprites.SplitLineTrans1_10900},
	{"Sirius Split Line Transform 2 #10900", Sprites.SplitLineTrans2_10900},
	{"Sirius Split Line #10910", Sprites.SplitLine_10910},
	{"Sirius Split Line Transform 1 #10910", Sprites.SplitLineTrans1_10910},
	{"Sirius Split Line Transform 2 #10910", Sprites.SplitLineTrans2_10910},
	{"Sirius Split Line #10911_1", Sprites.SplitLine_10911_1},
	{"Sirius Split Line Transform 1 #10911_1", Sprites.SplitLineTrans1_10911_1},
	{"Sirius Split Line Transform 2 #10911_1", Sprites.SplitLineTrans2_10911_1},
	{"Sirius Split Line #10911_2", Sprites.SplitLine_10911_2},
	{"Sirius Split Line Transform 1 #10911_2", Sprites.SplitLineTrans1_10911_2},
	{"Sirius Split Line Transform 2 #10911_2", Sprites.SplitLineTrans2_10911_2},
	{"Sirius Split Line #10911_3", Sprites.SplitLine_10911_3},
	{"Sirius Split Line Transform 1 #10911_3", Sprites.SplitLineTrans1_10911_3},
	{"Sirius Split Line Transform 2 #10911_3", Sprites.SplitLineTrans2_10911_3},
	{"Sirius Split Line #10920", Sprites.SplitLine_10920},
	{"Sirius Split Line Transform 1 #10920", Sprites.SplitLineTrans1_10920},
	{"Sirius Split Line Transform 2 #10920", Sprites.SplitLineTrans2_10920},
	{"Sirius Split Line #10930", Sprites.SplitLine_10930},
	{"Sirius Split Line Transform 1 #10930", Sprites.SplitLineTrans1_10930},
	{"Sirius Split Line Transform 2 #10930", Sprites.SplitLineTrans2_10930},
	{"Sirius Split Line #10940_1", Sprites.SplitLine_10940_1},
	{"Sirius Split Line Transform 1 #10940_1", Sprites.SplitLineTrans1_10940_1},
	{"Sirius Split Line Transform 2 #10940_1", Sprites.SplitLineTrans2_10940_1},
	{"Sirius Split Line #10940_2", Sprites.SplitLine_10940_2},
	{"Sirius Split Line Transform 1 #10940_2", Sprites.SplitLineTrans1_10940_2},
	{"Sirius Split Line Transform 2 #10940_2", Sprites.SplitLineTrans2_10940_2},
	{"Sirius Split Line #10950", Sprites.SplitLine_10950},
	{"Sirius Split Line Transform 1 #10950", Sprites.SplitLineTrans1_10950},
	{"Sirius Split Line Transform 2 #10950", Sprites.SplitLineTrans2_10950},
	{"Sirius Split Line #10960", Sprites.SplitLine_10960},
	{"Sirius Split Line Transform 1 #10960", Sprites.SplitLineTrans1_10960},
	{"Sirius Split Line Transform 2 #10960", Sprites.SplitLineTrans2_10960},
	{"Sirius Split Line #10970", Sprites.SplitLine_10970},
	{"Sirius Split Line Transform 1 #10970", Sprites.SplitLineTrans1_10970},
	{"Sirius Split Line Transform 2 #10970", Sprites.SplitLineTrans2_10970},
	{"Sirius Split Line #10980", Sprites.SplitLine_10980},
	{"Sirius Split Line Transform 1 #10980", Sprites.SplitLineTrans1_10980},
	{"Sirius Split Line Transform 2 #10980", Sprites.SplitLineTrans2_10980},
	{"Sirius Split Line #10990", Sprites.SplitLine_10990},
	{"Sirius Split Line Transform 1 #10990", Sprites.SplitLineTrans1_10990},
	{"Sirius Split Line Transform 2 #10990", Sprites.SplitLineTrans2_10990},
	{"Sirius Split Line #11000", Sprites.SplitLine_11000},
	{"Sirius Split Line Transform 1 #11000", Sprites.SplitLineTrans1_11000},
	{"Sirius Split Line Transform 2 #11000", Sprites.SplitLineTrans2_11000},
	{"Sirius Split Line #11010", Sprites.SplitLine_11010},
	{"Sirius Split Line Transform 1 #11010", Sprites.SplitLineTrans1_11010},
	{"Sirius Split Line Transform 2 #11010", Sprites.SplitLineTrans2_11010},
	{"Sirius Split Line #11020", Sprites.SplitLine_11020},
	{"Sirius Split Line Transform 1 #11020", Sprites.SplitLineTrans1_11020},
	{"Sirius Split Line Transform 2 #11020", Sprites.SplitLineTrans2_11020},
	{"Sirius Split Line #11030", Sprites.SplitLine_11030},
	{"Sirius Split Line Transform 1 #11030", Sprites.SplitLineTrans1_11030},
	{"Sirius Split Line Transform 2 #11030", Sprites.SplitLineTrans2_11030},
	{"Sirius Split Line #11040", Sprites.SplitLine_11040},
	{"Sirius Split Line Transform 1 #11040", Sprites.SplitLineTrans1_11040},
	{"Sirius Split Line Transform 2 #11040", Sprites.SplitLineTrans2_11040},
	{"Sirius Split Line #11041_1", Sprites.SplitLine_11041_1},
	{"Sirius Split Line Transform 1 #11041_1", Sprites.SplitLineTrans1_11041_1},
	{"Sirius Split Line Transform 2 #11041_1", Sprites.SplitLineTrans2_11041_1},
	{"Sirius Split Line #11041_2", Sprites.SplitLine_11041_2},
	{"Sirius Split Line Transform 1 #11041_2", Sprites.SplitLineTrans1_11041_2},
	{"Sirius Split Line Transform 2 #11041_2", Sprites.SplitLineTrans2_11041_2},
	{"Sirius Split Line #11041_3", Sprites.SplitLine_11041_3},
	{"Sirius Split Line Transform 1 #11041_3", Sprites.SplitLineTrans1_11041_3},
	{"Sirius Split Line Transform 2 #11041_3", Sprites.SplitLineTrans2_11041_3},
	{"Sirius Split Line #11041_4", Sprites.SplitLine_11041_4},
	{"Sirius Split Line Transform 1 #11041_4", Sprites.SplitLineTrans1_11041_4},
	{"Sirius Split Line Transform 2 #11041_4", Sprites.SplitLineTrans2_11041_4},
	{"Sirius Split Line #11041_5", Sprites.SplitLine_11041_5},
	{"Sirius Split Line Transform 1 #11041_5", Sprites.SplitLineTrans1_11041_5},
	{"Sirius Split Line Transform 2 #11041_5", Sprites.SplitLineTrans2_11041_5},
	{"Sirius Split Line #11041_6", Sprites.SplitLine_11041_6},
	{"Sirius Split Line Transform 1 #11041_6", Sprites.SplitLineTrans1_11041_6},
	{"Sirius Split Line Transform 2 #11041_6", Sprites.SplitLineTrans2_11041_6},
	{"Sirius Split Line #11041_7", Sprites.SplitLine_11041_7},
	{"Sirius Split Line Transform 1 #11041_7", Sprites.SplitLineTrans1_11041_7},
	{"Sirius Split Line Transform 2 #11041_7", Sprites.SplitLineTrans2_11041_7},
	{"Sirius Split Line #11050", Sprites.SplitLine_11050},
	{"Sirius Split Line Transform 1 #11050", Sprites.SplitLineTrans1_11050},
	{"Sirius Split Line Transform 2 #11050", Sprites.SplitLineTrans2_11050},
	{"Sirius Split Line #11060", Sprites.SplitLine_11060},
	{"Sirius Split Line Transform 1 #11060", Sprites.SplitLineTrans1_11060},
	{"Sirius Split Line Transform 2 #11060", Sprites.SplitLineTrans2_11060},
	{"Sirius Split Line #11070", Sprites.SplitLine_11070},
	{"Sirius Split Line Transform 1 #11070", Sprites.SplitLineTrans1_11070},
	{"Sirius Split Line Transform 2 #11070", Sprites.SplitLineTrans2_11070},
	{"Sirius Split Line #11080", Sprites.SplitLine_11080},
	{"Sirius Split Line Transform 1 #11080", Sprites.SplitLineTrans1_11080},
	{"Sirius Split Line Transform 2 #11080", Sprites.SplitLineTrans2_11080},
	{"Sirius Split Line #11090_1", Sprites.SplitLine_11090_1},
	{"Sirius Split Line Transform 1 #11090_1", Sprites.SplitLineTrans1_11090_1},
	{"Sirius Split Line Transform 2 #11090_1", Sprites.SplitLineTrans2_11090_1},
	{"Sirius Split Line #11090_2", Sprites.SplitLine_11090_2},
	{"Sirius Split Line Transform 1 #11090_2", Sprites.SplitLineTrans1_11090_2},
	{"Sirius Split Line Transform 2 #11090_2", Sprites.SplitLineTrans2_11090_2},
	{"Sirius Split Line #11091", Sprites.SplitLine_11091},
	{"Sirius Split Line Transform 1 #11091", Sprites.SplitLineTrans1_11091},
	{"Sirius Split Line Transform 2 #11091", Sprites.SplitLineTrans2_11091},
	{"Sirius Split Line #11100", Sprites.SplitLine_11100},
	{"Sirius Split Line Transform 1 #11100", Sprites.SplitLineTrans1_11100},
	{"Sirius Split Line Transform 2 #11100", Sprites.SplitLineTrans2_11100},
	{"Sirius Split Line #11110", Sprites.SplitLine_11110},
	{"Sirius Split Line Transform 1 #11110", Sprites.SplitLineTrans1_11110},
	{"Sirius Split Line Transform 2 #11110", Sprites.SplitLineTrans2_11110},
	{"Sirius Split Line #11111", Sprites.SplitLine_11111},
	{"Sirius Split Line Transform 1 #11111", Sprites.SplitLineTrans1_11111},
	{"Sirius Split Line Transform 2 #11111", Sprites.SplitLineTrans2_11111},
	{"Sirius Split Line #11120", Sprites.SplitLine_11120},
	{"Sirius Split Line Transform 1 #11120", Sprites.SplitLineTrans1_11120},
	{"Sirius Split Line Transform 2 #11120", Sprites.SplitLineTrans2_11120},
	{"Sirius Split Line #11121", Sprites.SplitLine_11121},
	{"Sirius Split Line Transform 1 #11121", Sprites.SplitLineTrans1_11121},
	{"Sirius Split Line Transform 2 #11121", Sprites.SplitLineTrans2_11121},
	{"Sirius Split Line #11122", Sprites.SplitLine_11122},
	{"Sirius Split Line Transform 1 #11122", Sprites.SplitLineTrans1_11122},
	{"Sirius Split Line Transform 2 #11122", Sprites.SplitLineTrans2_11122},
	{"Sirius Split Line #11130", Sprites.SplitLine_11130},
	{"Sirius Split Line Transform 1 #11130", Sprites.SplitLineTrans1_11130},
	{"Sirius Split Line Transform 2 #11130", Sprites.SplitLineTrans2_11130},
	{"Sirius Split Line #11140", Sprites.SplitLine_11140},
	{"Sirius Split Line Transform 1 #11140", Sprites.SplitLineTrans1_11140},
	{"Sirius Split Line Transform 2 #11140", Sprites.SplitLineTrans2_11140},
	{"Sirius Split Line #11150", Sprites.SplitLine_11150},
	{"Sirius Split Line Transform 1 #11150", Sprites.SplitLineTrans1_11150},
	{"Sirius Split Line Transform 2 #11150", Sprites.SplitLineTrans2_11150},
	{"Sirius Split Line #11151", Sprites.SplitLine_11151},
	{"Sirius Split Line Transform 1 #11151", Sprites.SplitLineTrans1_11151},
	{"Sirius Split Line Transform 2 #11151", Sprites.SplitLineTrans2_11151},
	{"Sirius Split Line #11151_1", Sprites.SplitLine_11151_1},
	{"Sirius Split Line Transform 1 #11151_1", Sprites.SplitLineTrans1_11151_1},
	{"Sirius Split Line Transform 2 #11151_1", Sprites.SplitLineTrans2_11151_1},
	{"Sirius Split Line #11160", Sprites.SplitLine_11160},
	{"Sirius Split Line Transform 1 #11160", Sprites.SplitLineTrans1_11160},
	{"Sirius Split Line Transform 2 #11160", Sprites.SplitLineTrans2_11160},
	{"Sirius Split Line #11170", Sprites.SplitLine_11170},
	{"Sirius Split Line Transform 1 #11170", Sprites.SplitLineTrans1_11170},
	{"Sirius Split Line Transform 2 #11170", Sprites.SplitLineTrans2_11170},
	{"Sirius Split Line #11180", Sprites.SplitLine_11180},
	{"Sirius Split Line Transform 1 #11180", Sprites.SplitLineTrans1_11180},
	{"Sirius Split Line Transform 2 #11180", Sprites.SplitLineTrans2_11180},
	{"Sirius Split Line #11190", Sprites.SplitLine_11190},
	{"Sirius Split Line Transform 1 #11190", Sprites.SplitLineTrans1_11190},
	{"Sirius Split Line Transform 2 #11190", Sprites.SplitLineTrans2_11190},
	{"Sirius Split Line #11200", Sprites.SplitLine_11200},
	{"Sirius Split Line Transform 1 #11200", Sprites.SplitLineTrans1_11200},
	{"Sirius Split Line Transform 2 #11200", Sprites.SplitLineTrans2_11200},
	{"Sirius Split Line #11210", Sprites.SplitLine_11210},
	{"Sirius Split Line Transform 1 #11210", Sprites.SplitLineTrans1_11210},
	{"Sirius Split Line Transform 2 #11210", Sprites.SplitLineTrans2_11210},
	{"Sirius Split Line #11211", Sprites.SplitLine_11211},
	{"Sirius Split Line Transform 1 #11211", Sprites.SplitLineTrans1_11211},
	{"Sirius Split Line Transform 2 #11211", Sprites.SplitLineTrans2_11211},
	{"Sirius Split Line #11212", Sprites.SplitLine_11212},
	{"Sirius Split Line Transform 1 #11212", Sprites.SplitLineTrans1_11212},
	{"Sirius Split Line Transform 2 #11212", Sprites.SplitLineTrans2_11212},
	{"Sirius Split Line #11220", Sprites.SplitLine_11220},
	{"Sirius Split Line Transform 1 #11220", Sprites.SplitLineTrans1_11220},
	{"Sirius Split Line Transform 2 #11220", Sprites.SplitLineTrans2_11220},
	{"Sirius Split Line #11230", Sprites.SplitLine_11230},
	{"Sirius Split Line Transform 1 #11230", Sprites.SplitLineTrans1_11230},
	{"Sirius Split Line Transform 2 #11230", Sprites.SplitLineTrans2_11230},
	{"Sirius Split Line #11240", Sprites.SplitLine_11240},
	{"Sirius Split Line Transform 1 #11240", Sprites.SplitLineTrans1_11240},
	{"Sirius Split Line Transform 2 #11240", Sprites.SplitLineTrans2_11240},
	{"Sirius Split Line #11250", Sprites.SplitLine_11250},
	{"Sirius Split Line Transform 1 #11250", Sprites.SplitLineTrans1_11250},
	{"Sirius Split Line Transform 2 #11250", Sprites.SplitLineTrans2_11250},
	{"Sirius Split Line #11260", Sprites.SplitLine_11260},
	{"Sirius Split Line Transform 1 #11260", Sprites.SplitLineTrans1_11260},
	{"Sirius Split Line Transform 2 #11260", Sprites.SplitLineTrans2_11260},
	{"Sirius Split Line #11270", Sprites.SplitLine_11270},
	{"Sirius Split Line Transform 1 #11270", Sprites.SplitLineTrans1_11270},
	{"Sirius Split Line Transform 2 #11270", Sprites.SplitLineTrans2_11270},
	{"Sirius Split Line #11280", Sprites.SplitLine_11280},
	{"Sirius Split Line Transform 1 #11280", Sprites.SplitLineTrans1_11280},
	{"Sirius Split Line Transform 2 #11280", Sprites.SplitLineTrans2_11280},
	{"Sirius Split Line #11290", Sprites.SplitLine_11290},
	{"Sirius Split Line Transform 1 #11290", Sprites.SplitLineTrans1_11290},
	{"Sirius Split Line Transform 2 #11290", Sprites.SplitLineTrans2_11290},
	{"Sirius Split Line #11300", Sprites.SplitLine_11300},
	{"Sirius Split Line Transform 1 #11300", Sprites.SplitLineTrans1_11300},
	{"Sirius Split Line Transform 2 #11300", Sprites.SplitLineTrans2_11300},
	{"Sirius Split Line #11310", Sprites.SplitLine_11310},
	{"Sirius Split Line Transform 1 #11310", Sprites.SplitLineTrans1_11310},
	{"Sirius Split Line Transform 2 #11310", Sprites.SplitLineTrans2_11310},
	{"Sirius Split Line #11320", Sprites.SplitLine_11320},
	{"Sirius Split Line Transform 1 #11320", Sprites.SplitLineTrans1_11320},
	{"Sirius Split Line Transform 2 #11320", Sprites.SplitLineTrans2_11320},
	{"Sirius Split Line #11321", Sprites.SplitLine_11321},
	{"Sirius Split Line Transform 1 #11321", Sprites.SplitLineTrans1_11321},
	{"Sirius Split Line Transform 2 #11321", Sprites.SplitLineTrans2_11321},
	{"Sirius Split Line #11330", Sprites.SplitLine_11330},
	{"Sirius Split Line Transform 1 #11330", Sprites.SplitLineTrans1_11330},
	{"Sirius Split Line Transform 2 #11330", Sprites.SplitLineTrans2_11330},
	{"Sirius Split Line #11331", Sprites.SplitLine_11331},
	{"Sirius Split Line Transform 1 #11331", Sprites.SplitLineTrans1_11331},
	{"Sirius Split Line Transform 2 #11331", Sprites.SplitLineTrans2_11331},
	{"Sirius Split Line #11332", Sprites.SplitLine_11332},
	{"Sirius Split Line Transform 1 #11332", Sprites.SplitLineTrans1_11332},
	{"Sirius Split Line Transform 2 #11332", Sprites.SplitLineTrans2_11332},
	{"Sirius Split Line #11340", Sprites.SplitLine_11340},
	{"Sirius Split Line Transform 1 #11340", Sprites.SplitLineTrans1_11340},
	{"Sirius Split Line Transform 2 #11340", Sprites.SplitLineTrans2_11340},
	{"Sirius Split Line #11350", Sprites.SplitLine_11350},
	{"Sirius Split Line Transform 1 #11350", Sprites.SplitLineTrans1_11350},
	{"Sirius Split Line Transform 2 #11350", Sprites.SplitLineTrans2_11350},
	{"Sirius Split Line #11360", Sprites.SplitLine_11360},
	{"Sirius Split Line Transform 1 #11360", Sprites.SplitLineTrans1_11360},
	{"Sirius Split Line Transform 2 #11360", Sprites.SplitLineTrans2_11360},
	{"Sirius Split Line #2", Sprites.SplitLine_2},
	{"Sirius Split Line Transform 1 #2", Sprites.SplitLineTrans1_2},
	{"Sirius Split Line Transform 2 #2", Sprites.SplitLineTrans2_2},
	{"Sirius Split Line #2010", Sprites.SplitLine_2010},
	{"Sirius Split Line Transform 1 #2010", Sprites.SplitLineTrans1_2010},
	{"Sirius Split Line Transform 2 #2010", Sprites.SplitLineTrans2_2010},
	{"Sirius Split Line #2020", Sprites.SplitLine_2020},
	{"Sirius Split Line Transform 1 #2020", Sprites.SplitLineTrans1_2020},
	{"Sirius Split Line Transform 2 #2020", Sprites.SplitLineTrans2_2020},
	{"Sirius Split Line #2030", Sprites.SplitLine_2030},
	{"Sirius Split Line Transform 1 #2030", Sprites.SplitLineTrans1_2030},
	{"Sirius Split Line Transform 2 #2030", Sprites.SplitLineTrans2_2030},
	{"Sirius Split Line #2040a", Sprites.SplitLine_2040a},
	{"Sirius Split Line Transform 1 #2040a", Sprites.SplitLineTrans1_2040a},
	{"Sirius Split Line Transform 2 #2040a", Sprites.SplitLineTrans2_2040a},
	{"Sirius Split Line #2040b", Sprites.SplitLine_2040b},
	{"Sirius Split Line Transform 1 #2040b", Sprites.SplitLineTrans1_2040b},
	{"Sirius Split Line Transform 2 #2040b", Sprites.SplitLineTrans2_2040b},
	{"Sirius Split Line #2050", Sprites.SplitLine_2050},
	{"Sirius Split Line Transform 1 #2050", Sprites.SplitLineTrans1_2050},
	{"Sirius Split Line Transform 2 #2050", Sprites.SplitLineTrans2_2050},
	{"Sirius Split Line #3", Sprites.SplitLine_3},
	{"Sirius Split Line Transform 1 #3", Sprites.SplitLineTrans1_3},
	{"Sirius Split Line Transform 2 #3", Sprites.SplitLineTrans2_3},
	{"Sirius Split Line #3010", Sprites.SplitLine_3010},
	{"Sirius Split Line Transform 1 #3010", Sprites.SplitLineTrans1_3010},
	{"Sirius Split Line Transform 2 #3010", Sprites.SplitLineTrans2_3010},
	{"Sirius Split Line #3020", Sprites.SplitLine_3020},
	{"Sirius Split Line Transform 1 #3020", Sprites.SplitLineTrans1_3020},
	{"Sirius Split Line Transform 2 #3020", Sprites.SplitLineTrans2_3020},
	{"Sirius Split Line #3030", Sprites.SplitLine_3030},
	{"Sirius Split Line Transform 1 #3030", Sprites.SplitLineTrans1_3030},
	{"Sirius Split Line Transform 2 #3030", Sprites.SplitLineTrans2_3030},
	{"Sirius Split Line #3040", Sprites.SplitLine_3040},
	{"Sirius Split Line Transform 1 #3040", Sprites.SplitLineTrans1_3040},
	{"Sirius Split Line Transform 2 #3040", Sprites.SplitLineTrans2_3040},
	{"Sirius Split Line #3050", Sprites.SplitLine_3050},
	{"Sirius Split Line Transform 1 #3050", Sprites.SplitLineTrans1_3050},
	{"Sirius Split Line Transform 2 #3050", Sprites.SplitLineTrans2_3050},
	{"Sirius Split Line #4", Sprites.SplitLine_4},
	{"Sirius Split Line Transform 1 #4", Sprites.SplitLineTrans1_4},
	{"Sirius Split Line Transform 2 #4", Sprites.SplitLineTrans2_4},
	{"Sirius Split Line #4010", Sprites.SplitLine_4010},
	{"Sirius Split Line Transform 1 #4010", Sprites.SplitLineTrans1_4010},
	{"Sirius Split Line Transform 2 #4010", Sprites.SplitLineTrans2_4010},
	{"Sirius Split Line #4020", Sprites.SplitLine_4020},
	{"Sirius Split Line Transform 1 #4020", Sprites.SplitLineTrans1_4020},
	{"Sirius Split Line Transform 2 #4020", Sprites.SplitLineTrans2_4020},
	{"Sirius Split Line #4030", Sprites.SplitLine_4030},
	{"Sirius Split Line Transform 1 #4030", Sprites.SplitLineTrans1_4030},
	{"Sirius Split Line Transform 2 #4030", Sprites.SplitLineTrans2_4030},
	{"Sirius Split Line #4040", Sprites.SplitLine_4040},
	{"Sirius Split Line Transform 1 #4040", Sprites.SplitLineTrans1_4040},
	{"Sirius Split Line Transform 2 #4040", Sprites.SplitLineTrans2_4040},
	{"Sirius Split Line #4050", Sprites.SplitLine_4050},
	{"Sirius Split Line Transform 1 #4050", Sprites.SplitLineTrans1_4050},
	{"Sirius Split Line Transform 2 #4050", Sprites.SplitLineTrans2_4050},
	{"Sirius Split Line #5", Sprites.SplitLine_5},
	{"Sirius Split Line Transform 1 #5", Sprites.SplitLineTrans1_5},
	{"Sirius Split Line Transform 2 #5", Sprites.SplitLineTrans2_5},
	{"Sirius Split Line #6", Sprites.SplitLine_6},
	{"Sirius Split Line Transform 1 #6", Sprites.SplitLineTrans1_6},
	{"Sirius Split Line Transform 2 #6", Sprites.SplitLineTrans2_6},
	{"Sirius Split Line #7", Sprites.SplitLine_7},
	{"Sirius Split Line Transform 1 #7", Sprites.SplitLineTrans1_7},
	{"Sirius Split Line Transform 2 #7", Sprites.SplitLineTrans2_7},
	{"Sirius Split Line #8", Sprites.SplitLine_8},
	{"Sirius Split Line Transform 1 #8", Sprites.SplitLineTrans1_8},
	{"Sirius Split Line Transform 2 #8", Sprites.SplitLineTrans2_8},
	{"Sirius Split Line #9", Sprites.SplitLine_9},
	{"Sirius Split Line Transform 1 #9", Sprites.SplitLineTrans1_9},
	{"Sirius Split Line Transform 2 #9", Sprites.SplitLineTrans2_9},
});
