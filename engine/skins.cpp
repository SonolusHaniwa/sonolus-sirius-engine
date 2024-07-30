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
	int ComboFCText = 47;
	int ComboFC0 = 48;
	int ComboFC1 = 49;
	int ComboFC2 = 50;
	int ComboFC3 = 51;
	int ComboFC4 = 52;
	int ComboFC5 = 53;
	int ComboFC6 = 54;
	int ComboFC7 = 55;
	int ComboFC8 = 56;
	int ComboFC9 = 57;
	int ComboAPText = 58;
	int ComboAP0 = 59;
	int ComboAP1 = 60;
	int ComboAP2 = 61;
	int ComboAP3 = 62;
	int ComboAP4 = 63;
	int ComboAP5 = 64;
	int ComboAP6 = 65;
	int ComboAP7 = 66;
	int ComboAP8 = 67;
	int ComboAP9 = 68;
	int GridYellow = 69;
	int SplitLine_1 = 70;
	int SplitLineTrans1_1 = 71;
	int SplitLineTrans2_1 = 72;
	int SplitLine_10010 = 73;
	int SplitLineTrans1_10010 = 74;
	int SplitLineTrans2_10010 = 75;
	int SplitLine_10020 = 76;
	int SplitLineTrans1_10020 = 77;
	int SplitLineTrans2_10020 = 78;
	int SplitLine_10030 = 79;
	int SplitLineTrans1_10030 = 80;
	int SplitLineTrans2_10030 = 81;
	int SplitLine_10040 = 82;
	int SplitLineTrans1_10040 = 83;
	int SplitLineTrans2_10040 = 84;
	int SplitLine_10050 = 85;
	int SplitLineTrans1_10050 = 86;
	int SplitLineTrans2_10050 = 87;
	int SplitLine_10060 = 88;
	int SplitLineTrans1_10060 = 89;
	int SplitLineTrans2_10060 = 90;
	int SplitLine_10070 = 91;
	int SplitLineTrans1_10070 = 92;
	int SplitLineTrans2_10070 = 93;
	int SplitLine_1010 = 94;
	int SplitLineTrans1_1010 = 95;
	int SplitLineTrans2_1010 = 96;
	int SplitLine_10100 = 97;
	int SplitLineTrans1_10100 = 98;
	int SplitLineTrans2_10100 = 99;
	int SplitLine_10110 = 100;
	int SplitLineTrans1_10110 = 101;
	int SplitLineTrans2_10110 = 102;
	int SplitLine_10120 = 103;
	int SplitLineTrans1_10120 = 104;
	int SplitLineTrans2_10120 = 105;
	int SplitLine_10130 = 106;
	int SplitLineTrans1_10130 = 107;
	int SplitLineTrans2_10130 = 108;
	int SplitLine_10140 = 109;
	int SplitLineTrans1_10140 = 110;
	int SplitLineTrans2_10140 = 111;
	int SplitLine_10150 = 112;
	int SplitLineTrans1_10150 = 113;
	int SplitLineTrans2_10150 = 114;
	int SplitLine_10160 = 115;
	int SplitLineTrans1_10160 = 116;
	int SplitLineTrans2_10160 = 117;
	int SplitLine_10161 = 118;
	int SplitLineTrans1_10161 = 119;
	int SplitLineTrans2_10161 = 120;
	int SplitLine_10162 = 121;
	int SplitLineTrans1_10162 = 122;
	int SplitLineTrans2_10162 = 123;
	int SplitLine_10170 = 124;
	int SplitLineTrans1_10170 = 125;
	int SplitLineTrans2_10170 = 126;
	int SplitLine_10180 = 127;
	int SplitLineTrans1_10180 = 128;
	int SplitLineTrans2_10180 = 129;
	int SplitLine_10190 = 130;
	int SplitLineTrans1_10190 = 131;
	int SplitLineTrans2_10190 = 132;
	int SplitLine_10191 = 133;
	int SplitLineTrans1_10191 = 134;
	int SplitLineTrans2_10191 = 135;
	int SplitLine_1020 = 136;
	int SplitLineTrans1_1020 = 137;
	int SplitLineTrans2_1020 = 138;
	int SplitLine_10200 = 139;
	int SplitLineTrans1_10200 = 140;
	int SplitLineTrans2_10200 = 141;
	int SplitLine_10220 = 142;
	int SplitLineTrans1_10220 = 143;
	int SplitLineTrans2_10220 = 144;
	int SplitLine_10230 = 145;
	int SplitLineTrans1_10230 = 146;
	int SplitLineTrans2_10230 = 147;
	int SplitLine_10240 = 148;
	int SplitLineTrans1_10240 = 149;
	int SplitLineTrans2_10240 = 150;
	int SplitLine_10250 = 151;
	int SplitLineTrans1_10250 = 152;
	int SplitLineTrans2_10250 = 153;
	int SplitLine_10260 = 154;
	int SplitLineTrans1_10260 = 155;
	int SplitLineTrans2_10260 = 156;
	int SplitLine_10270 = 157;
	int SplitLineTrans1_10270 = 158;
	int SplitLineTrans2_10270 = 159;
	int SplitLine_10280 = 160;
	int SplitLineTrans1_10280 = 161;
	int SplitLineTrans2_10280 = 162;
	int SplitLine_10290 = 163;
	int SplitLineTrans1_10290 = 164;
	int SplitLineTrans2_10290 = 165;
	int SplitLine_1030 = 166;
	int SplitLineTrans1_1030 = 167;
	int SplitLineTrans2_1030 = 168;
	int SplitLine_10300 = 169;
	int SplitLineTrans1_10300 = 170;
	int SplitLineTrans2_10300 = 171;
	int SplitLine_10310 = 172;
	int SplitLineTrans1_10310 = 173;
	int SplitLineTrans2_10310 = 174;
	int SplitLine_10320 = 175;
	int SplitLineTrans1_10320 = 176;
	int SplitLineTrans2_10320 = 177;
	int SplitLine_10321_1 = 178;
	int SplitLineTrans1_10321_1 = 179;
	int SplitLineTrans2_10321_1 = 180;
	int SplitLine_10321_2 = 181;
	int SplitLineTrans1_10321_2 = 182;
	int SplitLineTrans2_10321_2 = 183;
	int SplitLine_10321_3 = 184;
	int SplitLineTrans1_10321_3 = 185;
	int SplitLineTrans2_10321_3 = 186;
	int SplitLine_10321_4 = 187;
	int SplitLineTrans1_10321_4 = 188;
	int SplitLineTrans2_10321_4 = 189;
	int SplitLine_10321_5 = 190;
	int SplitLineTrans1_10321_5 = 191;
	int SplitLineTrans2_10321_5 = 192;
	int SplitLine_10322_1 = 193;
	int SplitLineTrans1_10322_1 = 194;
	int SplitLineTrans2_10322_1 = 195;
	int SplitLine_10322_2 = 196;
	int SplitLineTrans1_10322_2 = 197;
	int SplitLineTrans2_10322_2 = 198;
	int SplitLine_10322_3 = 199;
	int SplitLineTrans1_10322_3 = 200;
	int SplitLineTrans2_10322_3 = 201;
	int SplitLine_10322_4 = 202;
	int SplitLineTrans1_10322_4 = 203;
	int SplitLineTrans2_10322_4 = 204;
	int SplitLine_10322_5 = 205;
	int SplitLineTrans1_10322_5 = 206;
	int SplitLineTrans2_10322_5 = 207;
	int SplitLine_10323_1 = 208;
	int SplitLineTrans1_10323_1 = 209;
	int SplitLineTrans2_10323_1 = 210;
	int SplitLine_10323_2 = 211;
	int SplitLineTrans1_10323_2 = 212;
	int SplitLineTrans2_10323_2 = 213;
	int SplitLine_10323_3 = 214;
	int SplitLineTrans1_10323_3 = 215;
	int SplitLineTrans2_10323_3 = 216;
	int SplitLine_10323_4 = 217;
	int SplitLineTrans1_10323_4 = 218;
	int SplitLineTrans2_10323_4 = 219;
	int SplitLine_10323_5 = 220;
	int SplitLineTrans1_10323_5 = 221;
	int SplitLineTrans2_10323_5 = 222;
	int SplitLine_10324_1 = 223;
	int SplitLineTrans1_10324_1 = 224;
	int SplitLineTrans2_10324_1 = 225;
	int SplitLine_10324_2 = 226;
	int SplitLineTrans1_10324_2 = 227;
	int SplitLineTrans2_10324_2 = 228;
	int SplitLine_10324_3 = 229;
	int SplitLineTrans1_10324_3 = 230;
	int SplitLineTrans2_10324_3 = 231;
	int SplitLine_10325_1 = 232;
	int SplitLineTrans1_10325_1 = 233;
	int SplitLineTrans2_10325_1 = 234;
	int SplitLine_10325_2 = 235;
	int SplitLineTrans1_10325_2 = 236;
	int SplitLineTrans2_10325_2 = 237;
	int SplitLine_10325_3 = 238;
	int SplitLineTrans1_10325_3 = 239;
	int SplitLineTrans2_10325_3 = 240;
	int SplitLine_10325_4 = 241;
	int SplitLineTrans1_10325_4 = 242;
	int SplitLineTrans2_10325_4 = 243;
	int SplitLine_10326_1 = 244;
	int SplitLineTrans1_10326_1 = 245;
	int SplitLineTrans2_10326_1 = 246;
	int SplitLine_10326_2 = 247;
	int SplitLineTrans1_10326_2 = 248;
	int SplitLineTrans2_10326_2 = 249;
	int SplitLine_10326_3 = 250;
	int SplitLineTrans1_10326_3 = 251;
	int SplitLineTrans2_10326_3 = 252;
	int SplitLine_10326_4 = 253;
	int SplitLineTrans1_10326_4 = 254;
	int SplitLineTrans2_10326_4 = 255;
	int SplitLine_10326_5 = 256;
	int SplitLineTrans1_10326_5 = 257;
	int SplitLineTrans2_10326_5 = 258;
	int SplitLine_10327_1 = 259;
	int SplitLineTrans1_10327_1 = 260;
	int SplitLineTrans2_10327_1 = 261;
	int SplitLine_10327_2 = 262;
	int SplitLineTrans1_10327_2 = 263;
	int SplitLineTrans2_10327_2 = 264;
	int SplitLine_10327_3 = 265;
	int SplitLineTrans1_10327_3 = 266;
	int SplitLineTrans2_10327_3 = 267;
	int SplitLine_10327_4 = 268;
	int SplitLineTrans1_10327_4 = 269;
	int SplitLineTrans2_10327_4 = 270;
	int SplitLine_10328_1 = 271;
	int SplitLineTrans1_10328_1 = 272;
	int SplitLineTrans2_10328_1 = 273;
	int SplitLine_10328_2 = 274;
	int SplitLineTrans1_10328_2 = 275;
	int SplitLineTrans2_10328_2 = 276;
	int SplitLine_10328_3 = 277;
	int SplitLineTrans1_10328_3 = 278;
	int SplitLineTrans2_10328_3 = 279;
	int SplitLine_10328_4 = 280;
	int SplitLineTrans1_10328_4 = 281;
	int SplitLineTrans2_10328_4 = 282;
	int SplitLine_10328_5 = 283;
	int SplitLineTrans1_10328_5 = 284;
	int SplitLineTrans2_10328_5 = 285;
	int SplitLine_10330 = 286;
	int SplitLineTrans1_10330 = 287;
	int SplitLineTrans2_10330 = 288;
	int SplitLine_10340 = 289;
	int SplitLineTrans1_10340 = 290;
	int SplitLineTrans2_10340 = 291;
	int SplitLine_10350 = 292;
	int SplitLineTrans1_10350 = 293;
	int SplitLineTrans2_10350 = 294;
	int SplitLine_10360 = 295;
	int SplitLineTrans1_10360 = 296;
	int SplitLineTrans2_10360 = 297;
	int SplitLine_10361 = 298;
	int SplitLineTrans1_10361 = 299;
	int SplitLineTrans2_10361 = 300;
	int SplitLine_10370 = 301;
	int SplitLineTrans1_10370 = 302;
	int SplitLineTrans2_10370 = 303;
	int SplitLine_10380 = 304;
	int SplitLineTrans1_10380 = 305;
	int SplitLineTrans2_10380 = 306;
	int SplitLine_10390 = 307;
	int SplitLineTrans1_10390 = 308;
	int SplitLineTrans2_10390 = 309;
	int SplitLine_10391 = 310;
	int SplitLineTrans1_10391 = 311;
	int SplitLineTrans2_10391 = 312;
	int SplitLine_10392 = 313;
	int SplitLineTrans1_10392 = 314;
	int SplitLineTrans2_10392 = 315;
	int SplitLine_10393 = 316;
	int SplitLineTrans1_10393 = 317;
	int SplitLineTrans2_10393 = 318;
	int SplitLine_1040 = 319;
	int SplitLineTrans1_1040 = 320;
	int SplitLineTrans2_1040 = 321;
	int SplitLine_10400 = 322;
	int SplitLineTrans1_10400 = 323;
	int SplitLineTrans2_10400 = 324;
	int SplitLine_10410 = 325;
	int SplitLineTrans1_10410 = 326;
	int SplitLineTrans2_10410 = 327;
	int SplitLine_10420 = 328;
	int SplitLineTrans1_10420 = 329;
	int SplitLineTrans2_10420 = 330;
	int SplitLine_10430 = 331;
	int SplitLineTrans1_10430 = 332;
	int SplitLineTrans2_10430 = 333;
	int SplitLine_10440 = 334;
	int SplitLineTrans1_10440 = 335;
	int SplitLineTrans2_10440 = 336;
	int SplitLine_10450 = 337;
	int SplitLineTrans1_10450 = 338;
	int SplitLineTrans2_10450 = 339;
	int SplitLine_10460 = 340;
	int SplitLineTrans1_10460 = 341;
	int SplitLineTrans2_10460 = 342;
	int SplitLine_10461 = 343;
	int SplitLineTrans1_10461 = 344;
	int SplitLineTrans2_10461 = 345;
	int SplitLine_10470 = 346;
	int SplitLineTrans1_10470 = 347;
	int SplitLineTrans2_10470 = 348;
	int SplitLine_10480 = 349;
	int SplitLineTrans1_10480 = 350;
	int SplitLineTrans2_10480 = 351;
	int SplitLine_10481_1 = 352;
	int SplitLineTrans1_10481_1 = 353;
	int SplitLineTrans2_10481_1 = 354;
	int SplitLine_10481_2 = 355;
	int SplitLineTrans1_10481_2 = 356;
	int SplitLineTrans2_10481_2 = 357;
	int SplitLine_10481_3 = 358;
	int SplitLineTrans1_10481_3 = 359;
	int SplitLineTrans2_10481_3 = 360;
	int SplitLine_10482 = 361;
	int SplitLineTrans1_10482 = 362;
	int SplitLineTrans2_10482 = 363;
	int SplitLine_10490 = 364;
	int SplitLineTrans1_10490 = 365;
	int SplitLineTrans2_10490 = 366;
	int SplitLine_1050 = 367;
	int SplitLineTrans1_1050 = 368;
	int SplitLineTrans2_1050 = 369;
	int SplitLine_10500 = 370;
	int SplitLineTrans1_10500 = 371;
	int SplitLineTrans2_10500 = 372;
	int SplitLine_10510_1 = 373;
	int SplitLineTrans1_10510_1 = 374;
	int SplitLineTrans2_10510_1 = 375;
	int SplitLine_10510_2 = 376;
	int SplitLineTrans1_10510_2 = 377;
	int SplitLineTrans2_10510_2 = 378;
	int SplitLine_10510_3 = 379;
	int SplitLineTrans1_10510_3 = 380;
	int SplitLineTrans2_10510_3 = 381;
	int SplitLine_10511_1 = 382;
	int SplitLineTrans1_10511_1 = 383;
	int SplitLineTrans2_10511_1 = 384;
	int SplitLine_10511_2 = 385;
	int SplitLineTrans1_10511_2 = 386;
	int SplitLineTrans2_10511_2 = 387;
	int SplitLine_10511_3 = 388;
	int SplitLineTrans1_10511_3 = 389;
	int SplitLineTrans2_10511_3 = 390;
	int SplitLine_10512_1 = 391;
	int SplitLineTrans1_10512_1 = 392;
	int SplitLineTrans2_10512_1 = 393;
	int SplitLine_10512_2 = 394;
	int SplitLineTrans1_10512_2 = 395;
	int SplitLineTrans2_10512_2 = 396;
	int SplitLine_10513_1 = 397;
	int SplitLineTrans1_10513_1 = 398;
	int SplitLineTrans2_10513_1 = 399;
	int SplitLine_10513_2 = 400;
	int SplitLineTrans1_10513_2 = 401;
	int SplitLineTrans2_10513_2 = 402;
	int SplitLine_10514_1 = 403;
	int SplitLineTrans1_10514_1 = 404;
	int SplitLineTrans2_10514_1 = 405;
	int SplitLine_10514_2 = 406;
	int SplitLineTrans1_10514_2 = 407;
	int SplitLineTrans2_10514_2 = 408;
	int SplitLine_10514_3 = 409;
	int SplitLineTrans1_10514_3 = 410;
	int SplitLineTrans2_10514_3 = 411;
	int SplitLine_10515_1 = 412;
	int SplitLineTrans1_10515_1 = 413;
	int SplitLineTrans2_10515_1 = 414;
	int SplitLine_10515_2 = 415;
	int SplitLineTrans1_10515_2 = 416;
	int SplitLineTrans2_10515_2 = 417;
	int SplitLine_10515_3 = 418;
	int SplitLineTrans1_10515_3 = 419;
	int SplitLineTrans2_10515_3 = 420;
	int SplitLine_10516_1 = 421;
	int SplitLineTrans1_10516_1 = 422;
	int SplitLineTrans2_10516_1 = 423;
	int SplitLine_10516_2 = 424;
	int SplitLineTrans1_10516_2 = 425;
	int SplitLineTrans2_10516_2 = 426;
	int SplitLine_10516_3 = 427;
	int SplitLineTrans1_10516_3 = 428;
	int SplitLineTrans2_10516_3 = 429;
	int SplitLine_10517_1 = 430;
	int SplitLineTrans1_10517_1 = 431;
	int SplitLineTrans2_10517_1 = 432;
	int SplitLine_10517_2 = 433;
	int SplitLineTrans1_10517_2 = 434;
	int SplitLineTrans2_10517_2 = 435;
	int SplitLine_10517_3 = 436;
	int SplitLineTrans1_10517_3 = 437;
	int SplitLineTrans2_10517_3 = 438;
	int SplitLine_10518_1 = 439;
	int SplitLineTrans1_10518_1 = 440;
	int SplitLineTrans2_10518_1 = 441;
	int SplitLine_10518_2 = 442;
	int SplitLineTrans1_10518_2 = 443;
	int SplitLineTrans2_10518_2 = 444;
	int SplitLine_10518_3 = 445;
	int SplitLineTrans1_10518_3 = 446;
	int SplitLineTrans2_10518_3 = 447;
	int SplitLine_10518_4 = 448;
	int SplitLineTrans1_10518_4 = 449;
	int SplitLineTrans2_10518_4 = 450;
	int SplitLine_10518_5 = 451;
	int SplitLineTrans1_10518_5 = 452;
	int SplitLineTrans2_10518_5 = 453;
	int SplitLine_10519_1 = 454;
	int SplitLineTrans1_10519_1 = 455;
	int SplitLineTrans2_10519_1 = 456;
	int SplitLine_10519_2 = 457;
	int SplitLineTrans1_10519_2 = 458;
	int SplitLineTrans2_10519_2 = 459;
	int SplitLine_10519_3 = 460;
	int SplitLineTrans1_10519_3 = 461;
	int SplitLineTrans2_10519_3 = 462;
	int SplitLine_10519_4 = 463;
	int SplitLineTrans1_10519_4 = 464;
	int SplitLineTrans2_10519_4 = 465;
	int SplitLine_10519_5 = 466;
	int SplitLineTrans1_10519_5 = 467;
	int SplitLineTrans2_10519_5 = 468;
	int SplitLine_10530 = 469;
	int SplitLineTrans1_10530 = 470;
	int SplitLineTrans2_10530 = 471;
	int SplitLine_10540 = 472;
	int SplitLineTrans1_10540 = 473;
	int SplitLineTrans2_10540 = 474;
	int SplitLine_10550 = 475;
	int SplitLineTrans1_10550 = 476;
	int SplitLineTrans2_10550 = 477;
	int SplitLine_10560 = 478;
	int SplitLineTrans1_10560 = 479;
	int SplitLineTrans2_10560 = 480;
	int SplitLine_10570 = 481;
	int SplitLineTrans1_10570 = 482;
	int SplitLineTrans2_10570 = 483;
	int SplitLine_10580 = 484;
	int SplitLineTrans1_10580 = 485;
	int SplitLineTrans2_10580 = 486;
	int SplitLine_10590 = 487;
	int SplitLineTrans1_10590 = 488;
	int SplitLineTrans2_10590 = 489;
	int SplitLine_10600 = 490;
	int SplitLineTrans1_10600 = 491;
	int SplitLineTrans2_10600 = 492;
	int SplitLine_1060a = 493;
	int SplitLineTrans1_1060a = 494;
	int SplitLineTrans2_1060a = 495;
	int SplitLine_1060b = 496;
	int SplitLineTrans1_1060b = 497;
	int SplitLineTrans2_1060b = 498;
	int SplitLine_10610 = 499;
	int SplitLineTrans1_10610 = 500;
	int SplitLineTrans2_10610 = 501;
	int SplitLine_10620 = 502;
	int SplitLineTrans1_10620 = 503;
	int SplitLineTrans2_10620 = 504;
	int SplitLine_10630 = 505;
	int SplitLineTrans1_10630 = 506;
	int SplitLineTrans2_10630 = 507;
	int SplitLine_10631 = 508;
	int SplitLineTrans1_10631 = 509;
	int SplitLineTrans2_10631 = 510;
	int SplitLine_10640 = 511;
	int SplitLineTrans1_10640 = 512;
	int SplitLineTrans2_10640 = 513;
	int SplitLine_10650 = 514;
	int SplitLineTrans1_10650 = 515;
	int SplitLineTrans2_10650 = 516;
	int SplitLine_10660 = 517;
	int SplitLineTrans1_10660 = 518;
	int SplitLineTrans2_10660 = 519;
	int SplitLine_10670 = 520;
	int SplitLineTrans1_10670 = 521;
	int SplitLineTrans2_10670 = 522;
	int SplitLine_10680 = 523;
	int SplitLineTrans1_10680 = 524;
	int SplitLineTrans2_10680 = 525;
	int SplitLine_10690 = 526;
	int SplitLineTrans1_10690 = 527;
	int SplitLineTrans2_10690 = 528;
	int SplitLine_1070 = 529;
	int SplitLineTrans1_1070 = 530;
	int SplitLineTrans2_1070 = 531;
	int SplitLine_10710 = 532;
	int SplitLineTrans1_10710 = 533;
	int SplitLineTrans2_10710 = 534;
	int SplitLine_10720 = 535;
	int SplitLineTrans1_10720 = 536;
	int SplitLineTrans2_10720 = 537;
	int SplitLine_10770 = 538;
	int SplitLineTrans1_10770 = 539;
	int SplitLineTrans2_10770 = 540;
	int SplitLine_10771 = 541;
	int SplitLineTrans1_10771 = 542;
	int SplitLineTrans2_10771 = 543;
	int SplitLine_10780 = 544;
	int SplitLineTrans1_10780 = 545;
	int SplitLineTrans2_10780 = 546;
	int SplitLine_10790 = 547;
	int SplitLineTrans1_10790 = 548;
	int SplitLineTrans2_10790 = 549;
	int SplitLine_10791 = 550;
	int SplitLineTrans1_10791 = 551;
	int SplitLineTrans2_10791 = 552;
	int SplitLine_10792 = 553;
	int SplitLineTrans1_10792 = 554;
	int SplitLineTrans2_10792 = 555;
	int SplitLine_10800 = 556;
	int SplitLineTrans1_10800 = 557;
	int SplitLineTrans2_10800 = 558;
	int SplitLine_10810 = 559;
	int SplitLineTrans1_10810 = 560;
	int SplitLineTrans2_10810 = 561;
	int SplitLine_10820 = 562;
	int SplitLineTrans1_10820 = 563;
	int SplitLineTrans2_10820 = 564;
	int SplitLine_10830 = 565;
	int SplitLineTrans1_10830 = 566;
	int SplitLineTrans2_10830 = 567;
	int SplitLine_10840 = 568;
	int SplitLineTrans1_10840 = 569;
	int SplitLineTrans2_10840 = 570;
	int SplitLine_10841_1 = 571;
	int SplitLineTrans1_10841_1 = 572;
	int SplitLineTrans2_10841_1 = 573;
	int SplitLine_10841_2 = 574;
	int SplitLineTrans1_10841_2 = 575;
	int SplitLineTrans2_10841_2 = 576;
	int SplitLine_10841_3 = 577;
	int SplitLineTrans1_10841_3 = 578;
	int SplitLineTrans2_10841_3 = 579;
	int SplitLine_10841_4 = 580;
	int SplitLineTrans1_10841_4 = 581;
	int SplitLineTrans2_10841_4 = 582;
	int SplitLine_10841_5 = 583;
	int SplitLineTrans1_10841_5 = 584;
	int SplitLineTrans2_10841_5 = 585;
	int SplitLine_10850 = 586;
	int SplitLineTrans1_10850 = 587;
	int SplitLineTrans2_10850 = 588;
	int SplitLine_10860 = 589;
	int SplitLineTrans1_10860 = 590;
	int SplitLineTrans2_10860 = 591;
	int SplitLine_10920 = 592;
	int SplitLineTrans1_10920 = 593;
	int SplitLineTrans2_10920 = 594;
	int SplitLine_10930 = 595;
	int SplitLineTrans1_10930 = 596;
	int SplitLineTrans2_10930 = 597;
	int SplitLine_10940_1 = 598;
	int SplitLineTrans1_10940_1 = 599;
	int SplitLineTrans2_10940_1 = 600;
	int SplitLine_10940_2 = 601;
	int SplitLineTrans1_10940_2 = 602;
	int SplitLineTrans2_10940_2 = 603;
	int SplitLine_2 = 604;
	int SplitLineTrans1_2 = 605;
	int SplitLineTrans2_2 = 606;
	int SplitLine_2010 = 607;
	int SplitLineTrans1_2010 = 608;
	int SplitLineTrans2_2010 = 609;
	int SplitLine_2020 = 610;
	int SplitLineTrans1_2020 = 611;
	int SplitLineTrans2_2020 = 612;
	int SplitLine_2030 = 613;
	int SplitLineTrans1_2030 = 614;
	int SplitLineTrans2_2030 = 615;
	int SplitLine_2040a = 616;
	int SplitLineTrans1_2040a = 617;
	int SplitLineTrans2_2040a = 618;
	int SplitLine_2040b = 619;
	int SplitLineTrans1_2040b = 620;
	int SplitLineTrans2_2040b = 621;
	int SplitLine_2050 = 622;
	int SplitLineTrans1_2050 = 623;
	int SplitLineTrans2_2050 = 624;
	int SplitLine_3 = 625;
	int SplitLineTrans1_3 = 626;
	int SplitLineTrans2_3 = 627;
	int SplitLine_3010 = 628;
	int SplitLineTrans1_3010 = 629;
	int SplitLineTrans2_3010 = 630;
	int SplitLine_3020 = 631;
	int SplitLineTrans1_3020 = 632;
	int SplitLineTrans2_3020 = 633;
	int SplitLine_3030 = 634;
	int SplitLineTrans1_3030 = 635;
	int SplitLineTrans2_3030 = 636;
	int SplitLine_3040 = 637;
	int SplitLineTrans1_3040 = 638;
	int SplitLineTrans2_3040 = 639;
	int SplitLine_3050 = 640;
	int SplitLineTrans1_3050 = 641;
	int SplitLineTrans2_3050 = 642;
	int SplitLine_4 = 643;
	int SplitLineTrans1_4 = 644;
	int SplitLineTrans2_4 = 645;
	int SplitLine_4010 = 646;
	int SplitLineTrans1_4010 = 647;
	int SplitLineTrans2_4010 = 648;
	int SplitLine_4020 = 649;
	int SplitLineTrans1_4020 = 650;
	int SplitLineTrans2_4020 = 651;
	int SplitLine_4030 = 652;
	int SplitLineTrans1_4030 = 653;
	int SplitLineTrans2_4030 = 654;
	int SplitLine_4040 = 655;
	int SplitLineTrans1_4040 = 656;
	int SplitLineTrans2_4040 = 657;
	int SplitLine_4050 = 658;
	int SplitLineTrans1_4050 = 659;
	int SplitLineTrans2_4050 = 660;
	int SplitLine_5 = 661;
	int SplitLineTrans1_5 = 662;
	int SplitLineTrans2_5 = 663;
	int SplitLine_6 = 664;
	int SplitLineTrans1_6 = 665;
	int SplitLineTrans2_6 = 666;
	int SplitLine_7 = 667;
	int SplitLineTrans1_7 = 668;
	int SplitLineTrans2_7 = 669;
	int SplitLine_8 = 670;
	int SplitLineTrans1_8 = 671;
	int SplitLineTrans2_8 = 672;
	int SplitLine_9 = 673;
	int SplitLineTrans1_9 = 674;
	int SplitLineTrans2_9 = 675;
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
