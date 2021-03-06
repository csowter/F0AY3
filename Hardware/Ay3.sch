EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 2 3
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Connection ~ 2950 1250
Wire Wire Line
	2600 1250 2950 1250
Wire Wire Line
	2600 1300 2600 1250
$Comp
L power:+5VA #PWR?
U 1 1 60EE2A28
P 2950 1250
F 0 "#PWR?" H 2950 1100 50  0001 C CNN
F 1 "+5VA" H 2965 1423 50  0000 C CNN
F 2 "" H 2950 1250 50  0001 C CNN
F 3 "" H 2950 1250 50  0001 C CNN
	1    2950 1250
	1    0    0    -1  
$EndComp
$Comp
L power:GNDA #PWR?
U 1 1 60EE1A44
P 2950 4500
F 0 "#PWR?" H 2950 4250 50  0001 C CNN
F 1 "GNDA" H 2955 4327 50  0000 C CNN
F 2 "" H 2950 4500 50  0001 C CNN
F 3 "" H 2950 4500 50  0001 C CNN
	1    2950 4500
	1    0    0    -1  
$EndComp
NoConn ~ 2350 4150
NoConn ~ 2350 4050
NoConn ~ 2350 3950
NoConn ~ 2350 3850
NoConn ~ 2350 3650
NoConn ~ 2350 3550
NoConn ~ 2350 3450
NoConn ~ 2350 3350
NoConn ~ 2350 3250
NoConn ~ 2350 3150
NoConn ~ 2350 3050
NoConn ~ 2350 2950
NoConn ~ 2350 2750
NoConn ~ 2350 2650
NoConn ~ 2350 2550
NoConn ~ 2350 2450
NoConn ~ 2350 2350
NoConn ~ 2350 2250
NoConn ~ 2350 2150
NoConn ~ 2350 2050
$Comp
L AY3:AY3-8190 U?
U 1 1 60EDE897
P 3100 3150
F 0 "U?" H 3200 4500 60  0000 C CNN
F 1 "AY3-8190" H 3350 4400 60  0000 C CNN
F 2 "" H 3100 3150 60  0001 C CNN
F 3 "" H 3100 3150 60  0001 C CNN
	1    3100 3150
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 60EE329C
P 2600 1450
F 0 "C?" H 2485 1404 50  0000 R CNN
F 1 "100n" H 2485 1495 50  0000 R CNN
F 2 "" H 2638 1300 50  0001 C CNN
F 3 "~" H 2600 1450 50  0001 C CNN
	1    2600 1450
	-1   0    0    1   
$EndComp
$Comp
L power:GNDA #PWR?
U 1 1 60EE4809
P 2600 1600
F 0 "#PWR?" H 2600 1350 50  0001 C CNN
F 1 "GNDA" H 2605 1427 50  0000 C CNN
F 2 "" H 2600 1600 50  0001 C CNN
F 3 "" H 2600 1600 50  0001 C CNN
	1    2600 1600
	1    0    0    -1  
$EndComp
Wire Wire Line
	2950 1250 2950 1750
Wire Wire Line
	2950 4450 2950 4500
$Comp
L power:GNDA #PWR?
U 1 1 60EF9ADD
P 4550 3500
F 0 "#PWR?" H 4550 3250 50  0001 C CNN
F 1 "GNDA" H 4555 3327 50  0000 C CNN
F 2 "" H 4550 3500 50  0001 C CNN
F 3 "" H 4550 3500 50  0001 C CNN
	1    4550 3500
	1    0    0    -1  
$EndComp
Wire Wire Line
	3800 3400 4050 3400
$Comp
L power:+5VA #PWR?
U 1 1 60EFA2E1
P 4050 3400
F 0 "#PWR?" H 4050 3250 50  0001 C CNN
F 1 "+5VA" H 4065 3573 50  0000 C CNN
F 2 "" H 4050 3400 50  0001 C CNN
F 3 "" H 4050 3400 50  0001 C CNN
	1    4050 3400
	1    0    0    -1  
$EndComp
$Comp
L power:+5VA #PWR?
U 1 1 60EFB21A
P 4400 2950
F 0 "#PWR?" H 4400 2800 50  0001 C CNN
F 1 "+5VA" H 4415 3123 50  0000 C CNN
F 2 "" H 4400 2950 50  0001 C CNN
F 3 "" H 4400 2950 50  0001 C CNN
	1    4400 2950
	1    0    0    -1  
$EndComp
Wire Wire Line
	3800 3950 4000 3950
Wire Wire Line
	4000 4150 3800 4150
Wire Wire Line
	4000 3950 4000 4050
Wire Wire Line
	3800 4050 4000 4050
Connection ~ 4000 4050
Wire Wire Line
	4000 4050 4000 4150
$Comp
L Device:R R?
U 1 1 60EFC58D
P 4000 4300
F 0 "R?" H 4070 4346 50  0000 L CNN
F 1 "1k" H 4070 4255 50  0000 L CNN
F 2 "" V 3930 4300 50  0001 C CNN
F 3 "~" H 4000 4300 50  0001 C CNN
	1    4000 4300
	1    0    0    -1  
$EndComp
Connection ~ 4000 4150
$Comp
L power:GNDA #PWR?
U 1 1 60EFCBE6
P 4000 4500
F 0 "#PWR?" H 4000 4250 50  0001 C CNN
F 1 "GNDA" H 4005 4327 50  0000 C CNN
F 2 "" H 4000 4500 50  0001 C CNN
F 3 "" H 4000 4500 50  0001 C CNN
	1    4000 4500
	1    0    0    -1  
$EndComp
Wire Wire Line
	4000 4450 4000 4500
$Comp
L Device:R R?
U 1 1 60EFD131
P 4350 4050
F 0 "R?" V 4143 4050 50  0000 C CNN
F 1 "10k" V 4234 4050 50  0000 C CNN
F 2 "" V 4280 4050 50  0001 C CNN
F 3 "~" H 4350 4050 50  0001 C CNN
	1    4350 4050
	0    1    1    0   
$EndComp
Wire Wire Line
	4200 4050 4000 4050
$Comp
L Device:C C?
U 1 1 60EFDBC5
P 4750 4050
F 0 "C?" V 4498 4050 50  0000 C CNN
F 1 "100n c0g" V 4589 4050 50  0000 C CNN
F 2 "" H 4788 3900 50  0001 C CNN
F 3 "~" H 4750 4050 50  0001 C CNN
	1    4750 4050
	0    1    1    0   
$EndComp
Wire Wire Line
	4600 4050 4500 4050
Wire Wire Line
	3800 3600 3900 3600
Text HLabel 3900 3600 2    50   Input ~ 0
AY3_Reset
Wire Wire Line
	3800 3500 4550 3500
Wire Wire Line
	3800 3700 3900 3700
Text HLabel 3900 3700 2    50   Input ~ 0
AY3_Clock
Text HLabel 3800 2050 2    50   BiDi ~ 0
AY3_D0
Text HLabel 3800 2150 2    50   BiDi ~ 0
AY3_D1
Text HLabel 3800 2250 2    50   BiDi ~ 0
AY3_D2
Text HLabel 3800 2350 2    50   BiDi ~ 0
AY3_D3
Text HLabel 3800 2450 2    50   BiDi ~ 0
AY3_D4
Text HLabel 3800 2550 2    50   BiDi ~ 0
AY3_D5
Text HLabel 3800 2650 2    50   BiDi ~ 0
AY3_D6
Text HLabel 3800 2750 2    50   BiDi ~ 0
AY3_D7
Wire Wire Line
	3800 2950 4400 2950
Text HLabel 3800 3050 2    50   Input ~ 0
AY3_BC1
Text HLabel 3800 3150 2    50   Input ~ 0
AY3_BDIR
$Comp
L Device:R R?
U 1 1 60F00F0B
P 5700 3800
F 0 "R?" H 5770 3846 50  0000 L CNN
F 1 "330k" H 5770 3755 50  0000 L CNN
F 2 "" V 5630 3800 50  0001 C CNN
F 3 "~" H 5700 3800 50  0001 C CNN
	1    5700 3800
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 60F014AF
P 5700 4300
F 0 "R?" H 5770 4346 50  0000 L CNN
F 1 "470k" H 5770 4255 50  0000 L CNN
F 2 "" V 5630 4300 50  0001 C CNN
F 3 "~" H 5700 4300 50  0001 C CNN
	1    5700 4300
	1    0    0    -1  
$EndComp
$Comp
L power:GNDA #PWR?
U 1 1 60F01E99
P 5700 4550
F 0 "#PWR?" H 5700 4300 50  0001 C CNN
F 1 "GNDA" H 5705 4377 50  0000 C CNN
F 2 "" H 5700 4550 50  0001 C CNN
F 3 "" H 5700 4550 50  0001 C CNN
	1    5700 4550
	1    0    0    -1  
$EndComp
$Comp
L power:+5VA #PWR?
U 1 1 60F0248E
P 5700 3550
F 0 "#PWR?" H 5700 3400 50  0001 C CNN
F 1 "+5VA" H 5715 3723 50  0000 C CNN
F 2 "" H 5700 3550 50  0001 C CNN
F 3 "" H 5700 3550 50  0001 C CNN
	1    5700 3550
	1    0    0    -1  
$EndComp
Wire Wire Line
	5700 3550 5700 3650
$Comp
L Transistor_BJT:BC850 Q?
U 1 1 60F09DE0
P 6600 4050
F 0 "Q?" H 6791 4096 50  0000 L CNN
F 1 "BC850" H 6791 4005 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 6800 3975 50  0001 L CIN
F 3 "http://www.infineon.com/dgdl/Infineon-BC847SERIES_BC848SERIES_BC849SERIES_BC850SERIES-DS-v01_01-en.pdf?fileId=db3a304314dca389011541d4630a1657" H 6600 4050 50  0001 L CNN
	1    6600 4050
	1    0    0    -1  
$EndComp
$Comp
L Transistor_BJT:BC860 Q?
U 1 1 60F0A638
P 7150 3850
F 0 "Q?" H 7341 3804 50  0000 L CNN
F 1 "BC860" H 7341 3895 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 7350 3775 50  0001 L CIN
F 3 "http://www.infineon.com/dgdl/Infineon-BC857SERIES_BC858SERIES_BC859SERIES_BC860SERIES-DS-v01_01-en.pdf?fileId=db3a304314dca389011541da0e3a1661" H 7150 3850 50  0001 L CNN
	1    7150 3850
	1    0    0    1   
$EndComp
Wire Wire Line
	6700 3850 6950 3850
Wire Wire Line
	7250 3650 7250 3350
Wire Wire Line
	7250 3350 7000 3350
Wire Wire Line
	6700 3350 6700 3500
Wire Wire Line
	6700 3800 6700 3850
Connection ~ 6700 3850
Wire Wire Line
	6700 4250 6700 4350
Wire Wire Line
	7250 4350 7250 4050
$Comp
L power:+5VA #PWR?
U 1 1 60F0F0C1
P 7000 3350
F 0 "#PWR?" H 7000 3200 50  0001 C CNN
F 1 "+5VA" H 7015 3523 50  0000 C CNN
F 2 "" H 7000 3350 50  0001 C CNN
F 3 "" H 7000 3350 50  0001 C CNN
	1    7000 3350
	1    0    0    -1  
$EndComp
Connection ~ 7000 3350
$Comp
L power:GNDA #PWR?
U 1 1 60F101D2
P 6700 4650
F 0 "#PWR?" H 6700 4400 50  0001 C CNN
F 1 "GNDA" H 6705 4477 50  0000 C CNN
F 2 "" H 6700 4650 50  0001 C CNN
F 3 "" H 6700 4650 50  0001 C CNN
	1    6700 4650
	1    0    0    -1  
$EndComp
$Comp
L Device:CP C?
U 1 1 60F10FA9
P 7500 4350
F 0 "C?" V 7755 4350 50  0000 C CNN
F 1 "220u" V 7664 4350 50  0000 C CNN
F 2 "" H 7538 4200 50  0001 C CNN
F 3 "~" H 7500 4350 50  0001 C CNN
	1    7500 4350
	0    -1   -1   0   
$EndComp
Wire Wire Line
	7350 4350 7250 4350
Connection ~ 7250 4350
Wire Wire Line
	7650 4350 7800 4350
$Comp
L Device:R R?
U 1 1 60F12C6E
P 7800 4500
F 0 "R?" H 7870 4546 50  0000 L CNN
F 1 "10k" H 7870 4455 50  0000 L CNN
F 2 "" V 7730 4500 50  0001 C CNN
F 3 "~" H 7800 4500 50  0001 C CNN
	1    7800 4500
	1    0    0    -1  
$EndComp
$Comp
L power:GNDA #PWR?
U 1 1 60F12F63
P 7800 4750
F 0 "#PWR?" H 7800 4500 50  0001 C CNN
F 1 "GNDA" H 7805 4577 50  0000 C CNN
F 2 "" H 7800 4750 50  0001 C CNN
F 3 "" H 7800 4750 50  0001 C CNN
	1    7800 4750
	1    0    0    -1  
$EndComp
Wire Wire Line
	7800 4750 7800 4650
Connection ~ 7800 4350
Wire Wire Line
	7800 4350 8350 4350
$Comp
L Device:R R?
U 1 1 60F17CA2
P 6700 4500
F 0 "R?" H 6770 4546 50  0000 L CNN
F 1 "470" H 6770 4455 50  0000 L CNN
F 2 "" V 6630 4500 50  0001 C CNN
F 3 "~" H 6700 4500 50  0001 C CNN
	1    6700 4500
	1    0    0    -1  
$EndComp
Connection ~ 6700 4350
$Comp
L Device:R R?
U 1 1 60F1912F
P 6700 3650
F 0 "R?" H 6770 3696 50  0000 L CNN
F 1 "470" H 6770 3605 50  0000 L CNN
F 2 "" V 6630 3650 50  0001 C CNN
F 3 "~" H 6700 3650 50  0001 C CNN
	1    6700 3650
	1    0    0    -1  
$EndComp
Wire Wire Line
	6700 3350 7000 3350
Wire Wire Line
	6700 4350 7250 4350
Wire Wire Line
	4900 4050 5700 4050
Wire Wire Line
	5700 4450 5700 4550
Wire Wire Line
	5700 3950 5700 4050
Connection ~ 5700 4050
Wire Wire Line
	5700 4050 6400 4050
Wire Wire Line
	5700 4050 5700 4150
Text HLabel 8350 4350 2    50   Output ~ 0
AudioOut
$Comp
L power:+5V #PWR?
U 1 1 60F3B083
P 1050 1250
F 0 "#PWR?" H 1050 1100 50  0001 C CNN
F 1 "+5V" H 1065 1423 50  0000 C CNN
F 2 "" H 1050 1250 50  0001 C CNN
F 3 "" H 1050 1250 50  0001 C CNN
	1    1050 1250
	1    0    0    -1  
$EndComp
$Comp
L power:+5VA #PWR?
U 1 1 60F3B5D0
P 1500 1250
F 0 "#PWR?" H 1500 1100 50  0001 C CNN
F 1 "+5VA" H 1515 1423 50  0000 C CNN
F 2 "" H 1500 1250 50  0001 C CNN
F 3 "" H 1500 1250 50  0001 C CNN
	1    1500 1250
	1    0    0    -1  
$EndComp
Wire Wire Line
	1500 1250 1050 1250
$Comp
L power:GND #PWR?
U 1 1 60F3C5A0
P 1050 1450
F 0 "#PWR?" H 1050 1200 50  0001 C CNN
F 1 "GND" H 1055 1277 50  0000 C CNN
F 2 "" H 1050 1450 50  0001 C CNN
F 3 "" H 1050 1450 50  0001 C CNN
	1    1050 1450
	1    0    0    -1  
$EndComp
$Comp
L power:GNDA #PWR?
U 1 1 60F3CA67
P 1500 1450
F 0 "#PWR?" H 1500 1200 50  0001 C CNN
F 1 "GNDA" H 1505 1277 50  0000 C CNN
F 2 "" H 1500 1450 50  0001 C CNN
F 3 "" H 1500 1450 50  0001 C CNN
	1    1500 1450
	1    0    0    -1  
$EndComp
Wire Wire Line
	1500 1450 1050 1450
$EndSCHEMATC
