/* -*- tab-width: 4; indent-tabs-mode: nil -*- */
#ifndef _PT1_DEV_H_
#define _PT1_DEV_H_


// BonDriverテーブル(pathは各自で変更すること)
// 衛星波
char * bsdev[] = {
	(char *)"/usr/local/lib/BonDriver/BonDriver_LinuxPT-S0.so",
	(char *)"/usr/local/lib/BonDriver/BonDriver_LinuxPT-S1.so",
	(char *)"/usr/local/lib/BonDriver/BonDriver_LinuxPT-S2.so",
	(char *)"/usr/local/lib/BonDriver/BonDriver_LinuxPT-S3.so"
};
// Proxy
char * bsdev_proxy[] = {
	(char *)"/usr/local/lib/BonDriver/BonDriver_ProxyS0.so",
	(char *)"/usr/local/lib/BonDriver/BonDriver_ProxyS1.so",
	(char *)"/usr/local/lib/BonDriver/BonDriver_ProxyS2.so",
	(char *)"/usr/local/lib/BonDriver/BonDriver_ProxyS3.so"
};

// 地上波
char * isdb_t_dev[] = {
	(char *)"/usr/local/lib/BonDriver/BonDriver_LinuxPT-T0.so",
	(char *)"/usr/local/lib/BonDriver/BonDriver_LinuxPT-T1.so",
	(char *)"/usr/local/lib/BonDriver/BonDriver_LinuxPT-T2.so",
	(char *)"/usr/local/lib/BonDriver/BonDriver_LinuxPT-T3.so"
};
// Proxy
char * isdb_t_dev_proxy[] = {
	(char *)"/usr/local/lib/BonDriver/BonDriver_ProxyT0.so",
	(char *)"/usr/local/lib/BonDriver/BonDriver_ProxyT1.so",
	(char *)"/usr/local/lib/BonDriver/BonDriver_ProxyT2.so",
	(char *)"/usr/local/lib/BonDriver/BonDriver_ProxyT3.so"
};

#define NUM_BSDEV				(sizeof(bsdev)/sizeof(char *))
#define NUM_BSDEV_PROXY			(sizeof(bsdev_proxy)/sizeof(char *))
#define NUM_ISDB_T_DEV			(sizeof(isdb_t_dev)/sizeof(char *))
#define NUM_ISDB_T_DEV_PROXY	(sizeof(isdb_t_dev_proxy)/sizeof(char *))


// 変換テーブル(衛星波専用・ISDB-Tは演算)
// BSの局編成変更がない限りいじらないように

const ISDB_T_FREQ_CONV_TABLE	isdb_t_conv_table[] = {
	{  0, CHTYPE_SATELLITE, 0, (char *)"151"},	// BS朝日
	{  0, CHTYPE_SATELLITE, 1, (char *)"161"},	// BS-TBS
	{  1, CHTYPE_SATELLITE, 0, (char *)"191"},	// WOWOWプライム
	{  1, CHTYPE_SATELLITE, 1, (char *)"171"},	// BSジャパン
	{  2, CHTYPE_SATELLITE, 0, (char *)"192"},	// WOWOWライブ
	{  2, CHTYPE_SATELLITE, 1, (char *)"193"},	// WOWOWシネマ
	{  3, CHTYPE_SATELLITE, 0, (char *)"201"},	// スターチャンネル2
	{  3, CHTYPE_SATELLITE, 0, (char *)"202"},	// スターチャンネル3
	{  3, CHTYPE_SATELLITE, 1, (char *)"236"},	// BSアニマックス
	{  3, CHTYPE_SATELLITE, 2, (char *)"256"},	// ディズニーチャンネル
	{  4, CHTYPE_SATELLITE, 0, (char *)"211"},	// BS11
	{  4, CHTYPE_SATELLITE, 1, (char *)"200"},	// スターチャンネル1
	{  4, CHTYPE_SATELLITE, 2, (char *)"222"},	// TwellV
	{  5, CHTYPE_SATELLITE, 0, (char *)"238"},	// FOX bs238
	{  5, CHTYPE_SATELLITE, 1, (char *)"241"},	// BSスカパー！
	{  5, CHTYPE_SATELLITE, 2, (char *)"231"},	// 放送大学BS1
	{  5, CHTYPE_SATELLITE, 2, (char *)"232"},	// 放送大学BS2
	{  5, CHTYPE_SATELLITE, 2, (char *)"233"},	// 放送大学BS3
	{  6, CHTYPE_SATELLITE, 0, (char *)"141"},	// BS日テレ
	{  6, CHTYPE_SATELLITE, 1, (char *)"181"},	// BSフジ
	{  7, CHTYPE_SATELLITE, 0, (char *)"101"},	// NHK-BS1
	{  7, CHTYPE_SATELLITE, 1, (char *)"103"},	// NHK-BSプレミアム
	{  8, CHTYPE_SATELLITE, 1, (char *)"294"},	// 難視聴(日テレ)
	{  8, CHTYPE_SATELLITE, 1, (char *)"295"},	// 難視聴(テレ朝)
	{  8, CHTYPE_SATELLITE, 1, (char *)"296"},	// 難視聴(TBS)
	{  8, CHTYPE_SATELLITE, 1, (char *)"297"},	// 難視聴(テレ東)
	{  8, CHTYPE_SATELLITE, 2, (char *)"291"},	// 難視聴(NHK総合)
	{  8, CHTYPE_SATELLITE, 2, (char *)"292"},	// 難視聴(NHKEテレ)
	{  8, CHTYPE_SATELLITE, 2, (char *)"298"},	// 難視聴(フジ)
	{  9, CHTYPE_SATELLITE, 0, (char *)"234"},	// グリーンチャンネル
	{  9, CHTYPE_SATELLITE, 1, (char *)"242"},	// J Sports 1
	{  9, CHTYPE_SATELLITE, 2, (char *)"243"},	// J Sports 2
	{ 10, CHTYPE_SATELLITE, 0, (char *)"252"},	// IMAGICA BS
	{ 10, CHTYPE_SATELLITE, 1, (char *)"244"},	// J Sports 3
	{ 10, CHTYPE_SATELLITE, 2, (char *)"245"},	// J Sports 4
	{ 11, CHTYPE_SATELLITE, 0, (char *)"251"},	// BS釣りビジョン
	{ 11, CHTYPE_SATELLITE, 1, (char *)"255"},	// BS日本映画専門チャンネル
	{ 11, CHTYPE_SATELLITE, 2, (char *)"258"},	// D-Life
	{ 12, CHTYPE_SATELLITE, 0, (char *)"CS2"},
	{ 13, CHTYPE_SATELLITE, 0, (char *)"CS4"},
	{ 14, CHTYPE_SATELLITE, 0, (char *)"CS6"},
	{ 15, CHTYPE_SATELLITE, 0, (char *)"CS8"},
	{ 16, CHTYPE_SATELLITE, 0, (char *)"CS10"},
	{ 17, CHTYPE_SATELLITE, 0, (char *)"CS12"},
	{ 18, CHTYPE_SATELLITE, 0, (char *)"CS14"},
	{ 19, CHTYPE_SATELLITE, 0, (char *)"CS16"},
	{ 20, CHTYPE_SATELLITE, 0, (char *)"CS18"},
	{ 21, CHTYPE_SATELLITE, 0, (char *)"CS20"},
	{ 22, CHTYPE_SATELLITE, 0, (char *)"CS22"},
	{ 23, CHTYPE_SATELLITE, 0, (char *)"CS24"},
#if 0
	{	0, CHTYPE_GROUND, 0,   (char *)"1"}, {	 1, CHTYPE_GROUND, 0,	(char *)"2"},
	{	2, CHTYPE_GROUND, 0,   (char *)"3"}, {	 3, CHTYPE_GROUND, 0, (char *)"C13"},
	{	4, CHTYPE_GROUND, 0, (char *)"C14"}, {	 5, CHTYPE_GROUND, 0, (char *)"C15"},
	{	6, CHTYPE_GROUND, 0, (char *)"C16"}, {	 7, CHTYPE_GROUND, 0, (char *)"C17"},
	{	8, CHTYPE_GROUND, 0, (char *)"C18"}, {	 9, CHTYPE_GROUND, 0, (char *)"C19"},
	{  10, CHTYPE_GROUND, 0, (char *)"C20"}, {	11, CHTYPE_GROUND, 0, (char *)"C21"},
	{  12, CHTYPE_GROUND, 0, (char *)"C22"}, {	13, CHTYPE_GROUND, 0,	(char *)"4"},
	{  14, CHTYPE_GROUND, 0,   (char *)"5"}, {	15, CHTYPE_GROUND, 0,	(char *)"6"},
	{  16, CHTYPE_GROUND, 0,   (char *)"7"}, {	17, CHTYPE_GROUND, 0,	(char *)"8"},
	{  18, CHTYPE_GROUND, 0,   (char *)"9"}, {	19, CHTYPE_GROUND, 0,  (char *)"10"},
	{  20, CHTYPE_GROUND, 0,  (char *)"11"}, {	21, CHTYPE_GROUND, 0,  (char *)"12"},
	{  22, CHTYPE_GROUND, 0, (char *)"C23"}, {	23, CHTYPE_GROUND, 0, (char *)"C24"},
	{  24, CHTYPE_GROUND, 0, (char *)"C25"}, {	25, CHTYPE_GROUND, 0, (char *)"C26"},
	{  26, CHTYPE_GROUND, 0, (char *)"C27"}, {	27, CHTYPE_GROUND, 0, (char *)"C28"},
	{  28, CHTYPE_GROUND, 0, (char *)"C29"}, {	29, CHTYPE_GROUND, 0, (char *)"C30"},
	{  30, CHTYPE_GROUND, 0, (char *)"C31"}, {	31, CHTYPE_GROUND, 0, (char *)"C32"},
	{  32, CHTYPE_GROUND, 0, (char *)"C33"}, {	33, CHTYPE_GROUND, 0, (char *)"C34"},
	{  34, CHTYPE_GROUND, 0, (char *)"C35"}, {	35, CHTYPE_GROUND, 0, (char *)"C36"},
	{  36, CHTYPE_GROUND, 0, (char *)"C37"}, {	37, CHTYPE_GROUND, 0, (char *)"C38"},
	{  38, CHTYPE_GROUND, 0, (char *)"C39"}, {	39, CHTYPE_GROUND, 0, (char *)"C40"},
	{  40, CHTYPE_GROUND, 0, (char *)"C41"}, {	41, CHTYPE_GROUND, 0, (char *)"C42"},
	{  42, CHTYPE_GROUND, 0, (char *)"C43"}, {	43, CHTYPE_GROUND, 0, (char *)"C44"},
	{  44, CHTYPE_GROUND, 0, (char *)"C45"}, {	45, CHTYPE_GROUND, 0, (char *)"C46"},
	{  46, CHTYPE_GROUND, 0, (char *)"C47"}, {	47, CHTYPE_GROUND, 0, (char *)"C48"},
	{  48, CHTYPE_GROUND, 0, (char *)"C49"}, {	49, CHTYPE_GROUND, 0, (char *)"C50"},
	{  50, CHTYPE_GROUND, 0, (char *)"C51"}, {	51, CHTYPE_GROUND, 0, (char *)"C52"},
	{  52, CHTYPE_GROUND, 0, (char *)"C53"}, {	53, CHTYPE_GROUND, 0, (char *)"C54"},
	{  54, CHTYPE_GROUND, 0, (char *)"C55"}, {	55, CHTYPE_GROUND, 0, (char *)"C56"},
	{  56, CHTYPE_GROUND, 0, (char *)"C57"}, {	57, CHTYPE_GROUND, 0, (char *)"C58"},
	{  58, CHTYPE_GROUND, 0, (char *)"C59"}, {	59, CHTYPE_GROUND, 0, (char *)"C60"},
	{  60, CHTYPE_GROUND, 0, (char *)"C61"}, {	61, CHTYPE_GROUND, 0, (char *)"C62"},
	{  62, CHTYPE_GROUND, 0, (char *)"C63"}, {	63, CHTYPE_GROUND, 0,  (char *)"13"},
	{  64, CHTYPE_GROUND, 0,  (char *)"14"}, {	65, CHTYPE_GROUND, 0,  (char *)"15"},
	{  66, CHTYPE_GROUND, 0,  (char *)"16"}, {	67, CHTYPE_GROUND, 0,  (char *)"17"},
	{  68, CHTYPE_GROUND, 0,  (char *)"18"}, {	69, CHTYPE_GROUND, 0,  (char *)"19"},
	{  70, CHTYPE_GROUND, 0,  (char *)"20"}, {	71, CHTYPE_GROUND, 0,  (char *)"21"},
	{  72, CHTYPE_GROUND, 0,  (char *)"22"}, {	73, CHTYPE_GROUND, 0,  (char *)"23"},
	{  74, CHTYPE_GROUND, 0,  (char *)"24"}, {	75, CHTYPE_GROUND, 0,  (char *)"25"},
	{  76, CHTYPE_GROUND, 0,  (char *)"26"}, {	77, CHTYPE_GROUND, 0,  (char *)"27"},
	{  78, CHTYPE_GROUND, 0,  (char *)"28"}, {	79, CHTYPE_GROUND, 0,  (char *)"29"},
	{  80, CHTYPE_GROUND, 0,  (char *)"30"}, {	81, CHTYPE_GROUND, 0,  (char *)"31"},
	{  82, CHTYPE_GROUND, 0,  (char *)"32"}, {	83, CHTYPE_GROUND, 0,  (char *)"33"},
	{  84, CHTYPE_GROUND, 0,  (char *)"34"}, {	85, CHTYPE_GROUND, 0,  (char *)"35"},
	{  86, CHTYPE_GROUND, 0,  (char *)"36"}, {	87, CHTYPE_GROUND, 0,  (char *)"37"},
	{  88, CHTYPE_GROUND, 0,  (char *)"38"}, {	89, CHTYPE_GROUND, 0,  (char *)"39"},
	{  90, CHTYPE_GROUND, 0,  (char *)"40"}, {	91, CHTYPE_GROUND, 0,  (char *)"41"},
	{  92, CHTYPE_GROUND, 0,  (char *)"42"}, {	93, CHTYPE_GROUND, 0,  (char *)"43"},
	{  94, CHTYPE_GROUND, 0,  (char *)"44"}, {	95, CHTYPE_GROUND, 0,  (char *)"45"},
	{  96, CHTYPE_GROUND, 0,  (char *)"46"}, {	97, CHTYPE_GROUND, 0,  (char *)"47"},
	{  98, CHTYPE_GROUND, 0,  (char *)"48"}, {	99, CHTYPE_GROUND, 0,  (char *)"49"},
	{ 100, CHTYPE_GROUND, 0,  (char *)"50"}, { 101, CHTYPE_GROUND, 0,  (char *)"51"},
	{ 102, CHTYPE_GROUND, 0,  (char *)"52"}, { 103, CHTYPE_GROUND, 0,  (char *)"53"},
	{ 104, CHTYPE_GROUND, 0,  (char *)"54"}, { 105, CHTYPE_GROUND, 0,  (char *)"55"},
	{ 106, CHTYPE_GROUND, 0,  (char *)"56"}, { 107, CHTYPE_GROUND, 0,  (char *)"57"},
	{ 108, CHTYPE_GROUND, 0,  (char *)"58"}, { 109, CHTYPE_GROUND, 0,  (char *)"59"},
	{ 110, CHTYPE_GROUND, 0,  (char *)"60"}, { 111, CHTYPE_GROUND, 0,  (char *)"61"},
	{ 112, CHTYPE_GROUND, 0,  (char *)"62"}, { 113, CHTYPE_GROUND, 0,  (char *)"63"},
#endif
	{ 0, 0, 0, NULL} /* terminate */
};
#endif
