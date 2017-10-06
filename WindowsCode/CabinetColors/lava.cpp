const uint32_t gFireData[62][46] =
{
  {0X930703,0X8F0804,0X8B0904,0X870904,0X820A04,0X7E0B05,0X790C06,0X750C06,0X700D06,0X6D0E06,0X6A0E07,0X670E07,0X660F07,0X650F07,0X650F07,0X670F07,0X690E07,0X6C0E06,0X700D06,0X750C06,0X7B0B05,0X820A04,0X8A0904,0X930804,0X9C0703,0XA60702,0XB00702,0XB90701,0XC40901,0XCE0A01,0XD70C01,0XDE0F00,0XE71300,0XEC1700,0XF11D00,0XF12200,0XF72800,0XFF2E00,0XF73500,0XF73B00,0XFF4000,0XF74700,0XFF4C00,0XF75200,0XF75600,0XF75800,},
  {0X9D0702,0X990703,0X950703,0X8F0904,0X8B0904,0X860A04,0X810A04,0X7C0B05,0X770C06,0X730C06,0X6F0D06,0X6C0E06,0X6A0E07,0X680E07,0X670E07,0X670E07,0X690E07,0X6B0E07,0X6F0E06,0X730C06,0X770C06,0X7E0A05,0X850A04,0X8D0904,0X950703,0X9F0702,0XA90702,0XB30702,0XBD0701,0XC40901,0XCE0A01,0XD70D01,0XE20F00,0XE21300,0XE71800,0XEC1D01,0XF72200,0XF12600,0XF12D00,0XF13200,0XF73900,0XF73D00,0XF74100,0XEC4700,0XF14A00,0XE74D01,},
  {0XA90602,0XA40702,0XA00702,0X9B0703,0X940803,0X8E0904,0X890904,0X840A04,0X7F0A05,0X7A0C06,0X750C06,0X710D06,0X6E0D06,0X6C0E06,0X6B0E07,0X6A0E07,0X6A0E07,0X6B0E07,0X6E0E06,0X710D06,0X750C06,0X7A0B05,0X810A04,0X880904,0X910804,0X990703,0XA20702,0XAB0702,0XB50701,0XBD0701,0XC40901,0XCB0B01,0XD70D01,0XDE1000,0XDE1300,0XE71701,0XE21B00,0XF12000,0XE22400,0XE72A00,0XE72F00,0XE73300,0XEC3700,0XEC3C00,0XE23F00,0XDB4101,},
  {0XB50601,0XB00602,0XAB0702,0XA40702,0X9F0702,0X980803,0X930903,0X8C0904,0X870A04,0X820A04,0X7C0B05,0X770C06,0X740C06,0X700D06,0X6E0D06,0X6D0E06,0X6C0E06,0X6C0E06,0X6F0E06,0X6F0D06,0X730C06,0X780C06,0X7D0A05,0X840A04,0X8C0904,0X930803,0X9B0803,0XA20702,0XAC0702,0XB30702,0XBD0901,0XC40B01,0XCB0C01,0XCE0E01,0XD71000,0XDB1401,0XD71700,0XDE1900,0XDE1F01,0XDE2301,0XDE2601,0XDE2A01,0XE22E01,0XDB3100,0XD73401,0XD13601,},
  {0XC20701,0XBB0701,0XB50701,0XB00702,0XA90702,0XA30702,0X9C0802,0X950803,0X8F0904,0X8A0904,0X840A04,0X7F0A05,0X7A0B05,0X760C06,0X730C06,0X710C06,0X700D06,0X6F0D06,0X700E06,0X710D06,0X750C06,0X770C05,0X7D0B05,0X810A05,0X880904,0X8D0904,0X930903,0X9D0903,0XA60902,0XAE0902,0XB50A02,0XBD0B01,0XC20C01,0XC20E01,0XCE1101,0XD11301,0XCE1401,0XD11901,0XD11A01,0XD11E00,0XD12101,0XD12201,0XD12501,0XCE2701,0XCE2A01,0XC92C01,},
  {0XCB0801,0XC60801,0XC20801,0XBB0701,0XB30701,0XAE0702,0XA60702,0XA00802,0X990803,0X930903,0X8C0904,0X870A04,0X820A05,0X7D0B05,0X7B0B05,0X770C06,0X750C06,0X730C06,0X730D06,0X750C06,0X770D06,0X790C05,0X7F0D06,0X830C04,0X860C04,0X8B0C04,0X930B04,0X980C03,0X9F0D02,0XA90E02,0XAC0E02,0XB30F02,0XB90F02,0XB71101,0XBF1201,0XC21401,0XC61601,0XC61801,0XC61A01,0XC61D01,0XC61E01,0XC61F01,0XC61F01,0XC42001,0XC42101,0XC42301,},
  {0XD70A00,0XD10A01,0XCB0901,0XC40901,0XBF0901,0XB90801,0XB20802,0XAB0802,0XA30802,0X9C0802,0X950903,0X8F0904,0X8B0904,0X860A04,0X820C05,0X7E0C05,0X7D0C05,0X7D0E06,0X7D0E05,0X7D0F05,0X7E0E04,0X810E05,0X820E05,0X860F04,0X8A0F04,0X8E1003,0X951104,0X9C1303,0XA01504,0XA81402,0XAC1602,0XB01702,0XB31702,0XB51702,0XBB1801,0XBB1902,0XBF1A01,0XBF1D01,0XBF1E01,0XBF1F01,0XBF1F01,0XBD1E02,0XBB1D01,0XBB1C01,0XBB1C01,0XBB1C01,},
  {0XDE0E00,0XDB0D00,0XD40C01,0XCE0B01,0XC90A01,0XC20A01,0XBB0901,0XB50901,0XAE0802,0XA60802,0XA00802,0X990803,0X940904,0X8F0904,0X8B0A04,0X890C04,0X870C04,0X870E04,0X8A0F04,0X881004,0X891004,0X8C1104,0X8E1404,0X8F1404,0X921404,0X971903,0X9B1A02,0XA01C02,0XA41E02,0XA91F02,0XAE2002,0XB02002,0XB22002,0XB51F01,0XB51F02,0XB92002,0XB72101,0XBB2202,0XBB2302,0XBB2301,0XBB2201,0XB72001,0XB51C01,0XB71A01,0XB71901,0XB51902,},
  {0XE71200,0XE21100,0XDE1000,0XD70E00,0XD40D01,0XCB0C01,0XC60A01,0XBF0A01,0XB70901,0XB20802,0XA90802,0XA30902,0X9F0903,0X9B0A03,0X970C03,0X940E04,0X950F04,0X951203,0X971203,0X9C1403,0X9C1603,0X9C1802,0X9F1A02,0XA21E02,0XA32002,0XA62302,0XA82602,0XAC2802,0XB02902,0XB52A02,0XB52A02,0XB52A02,0XB52901,0XB72801,0XB72702,0XB92702,0XBB2801,0XB92802,0XB92702,0XB92601,0XB72401,0XB52102,0XB31D01,0XB31902,0XB51702,0XB51602,},
  {0XEC1800,0XE71600,0XE21500,0XDE1200,0XDB1100,0XD40F01,0XCE0D01,0XC90C01,0XC20A01,0XBB0901,0XB50902,0XB00A01,0XAB0B02,0XA80C02,0XA60F02,0XA41103,0XA41402,0XA61802,0XAC1902,0XAE1C02,0XB21E02,0XB22202,0XB32402,0XB32902,0XB52C01,0XB52E02,0XB93101,0XB93202,0XBB3301,0XBB3401,0XBB3202,0XBB3202,0XB73001,0XB92F01,0XB92E01,0XB92C02,0XB92B02,0XB72A01,0XB92902,0XB72601,0XB52301,0XB52002,0XB31C02,0XB31801,0XB51601,0XB71502,},
  {0XF11F00,0XEC1D00,0XEC1A00,0XE71800,0XE21600,0XDE1300,0XD71100,0XD40E01,0XCE0C01,0XC90C01,0XC20B01,0XBB0D01,0XB70E01,0XB51101,0XB51401,0XB51802,0XB51C02,0XB71F01,0XBF2201,0XC42701,0XC22A01,0XC42E01,0XC43101,0XCB3401,0XC63701,0XC63901,0XC63A02,0XC63B01,0XC63A01,0XC43901,0XC23701,0XC23601,0XBD3401,0XBB3202,0XBB2F01,0XB92E02,0XB72B02,0XB72901,0XB72702,0XB52402,0XB32101,0XB31E02,0XB31A02,0XB71702,0XB91502,0XBD1401,},
  {0XF12700,0XF12400,0XEC2200,0XEC1F00,0XE71B00,0XE21800,0XDE1500,0XDB1200,0XD40F01,0XCE0F01,0XD10F01,0XC61101,0XC41401,0XC61702,0XC21E01,0XC92101,0XC62501,0XCB2A01,0XCE2E01,0XCE3201,0XD13501,0XD73A01,0XD43D01,0XD73F01,0XD44000,0XCE4101,0XD13F01,0XC93E01,0XC93D01,0XC93A01,0XC23801,0XC23502,0XBF3201,0XBB3101,0XB72E01,0XB72A01,0XB32901,0XB52601,0XB32302,0XB32002,0XB51D02,0XB51A01,0XB71702,0XB91402,0XBD1201,0XC41201,},
  {0XF13000,0XF12D00,0XF12A00,0XF12600,0XEC2200,0XEC1E00,0XE71A00,0XE21700,0XDE1500,0XD71300,0XD41401,0XD41801,0XD11C01,0XCE2001,0XD42700,0XD72C01,0XDB3101,0XD73400,0XDB3901,0XDE3C00,0XDB3F00,0XE24201,0XDB4400,0XDE4601,0XDB4500,0XD74401,0XD14101,0XCB3E01,0XC63C01,0XC43801,0XBD3501,0XBB3202,0XB52F01,0XB22D01,0XB32901,0XB22702,0XAE2402,0XB22102,0XAE1E02,0XB01A02,0XB31802,0XB51602,0XB91201,0XBF1102,0XC41001,0XCB0E00,},
  {0XF13A00,0XF13700,0XF13200,0XF12E00,0XF12A00,0XEC2600,0XEC2100,0XE71E00,0XE71B00,0XDE1A00,0XE21E00,0XDB1F01,0XDB2600,0XE22B01,0XDE3100,0XDE3601,0XE73A00,0XDE3E00,0XE24100,0XE24400,0XE74701,0XE24900,0XE24900,0XDE4700,0XDB4500,0XD74200,0XD13E01,0XC93A01,0XC23700,0XB93301,0XB72E01,0XB22C01,0XAE2902,0XAB2702,0XAC2302,0XA92102,0XA91E02,0XAE1B02,0XAC1702,0XAE1501,0XB31301,0XB91102,0XBD0E01,0XC40D01,0XCB0A01,0XCE0A01,},
  {0XF14400,0XF14100,0XF13C00,0XF13700,0XF13200,0XF12E00,0XF12900,0XEC2500,0XEC2500,0XE72300,0XE72600,0XE72A00,0XE73100,0XEC3600,0XE73C00,0XEC4000,0XEC4300,0XEC4600,0XEC4800,0XE74A00,0XE24C00,0XEC4C00,0XE74A01,0XE24700,0XD74301,0XD13E01,0XCE3A01,0XC23600,0XBB3101,0XB32C02,0XAB2702,0XA92503,0XA22102,0XA01F02,0XA31C02,0XA01902,0XA31902,0XA61402,0XAB1202,0XAB0F02,0XB00E02,0XB90C01,0XBB0A01,0XC40901,0XC90701,0XD10701,},
  {0XF14F00,0XF14A00,0XF14600,0XF14100,0XF13B00,0XF13700,0XF13200,0XF12E00,0XF12F00,0XF12F00,0XF13100,0XF13800,0XEC3C00,0XF74100,0XF14500,0XEC4800,0XF14900,0XEC4C00,0XEC4E00,0XF74E00,0XE74F00,0XE74C00,0XE24900,0XDE4400,0XD73F00,0XCE3901,0XC93401,0XB92F01,0XB22902,0XA62602,0XA02202,0X9D1E02,0X991A04,0X951902,0X971602,0X981403,0X9B1204,0X9C1103,0XA20E02,0XA30C02,0XA90A02,0XB30902,0XB90801,0XBF0601,0XC90601,0XC60601,},
  {0XF15900,0XF15400,0XF14F00,0XF14A00,0XF14600,0XF74100,0XF73E00,0XF73A00,0XF13900,0XF13A00,0XF13E00,0XF74100,0XF14600,0XF14A00,0XF74C00,0XF14E00,0XEC4F00,0XF75100,0XF15100,0XEC5000,0XEC4E00,0XE74B00,0XE74700,0XDE4100,0XD43A00,0XCB3401,0XC22E01,0XB72901,0XA92302,0XA21E03,0X991A03,0X941704,0X921403,0X8F1304,0X8D1204,0X8D0F04,0X910E04,0X940C04,0X980B03,0XA00903,0XA80802,0XA90702,0XB20702,0XB50601,0XBD0602,0XC40601,},
  {0XF16400,0XF15F00,0XF15A00,0XF15500,0XF74F00,0XF74C00,0XF74800,0XF74600,0XF74600,0XF74700,0XF14900,0XF74C00,0XF74F00,0XF75200,0XF75400,0XF75500,0XF75400,0XEC5500,0XF15400,0XEC5100,0XE74D00,0XF14800,0XE74200,0XDE3C01,0XD13601,0XCB2F01,0XC22901,0XB52401,0XA91D01,0XA31B02,0X971703,0X931403,0X8D1104,0X8B1004,0X8C0F04,0X8D0F04,0X8D0C04,0X940D03,0X950B04,0X970803,0X9D0802,0XA40802,0XA60702,0XAB0602,0XB20602,0XB20601,},
  {0XF17000,0XF16B00,0XF16500,0XF15F00,0XF75A00,0XF75700,0XF75400,0XF75200,0XF75300,0XF75400,0XF75600,0XF75600,0XF75800,0XF75A00,0XF75A00,0XF75A00,0XF15800,0XF75600,0XEC5300,0XF14E00,0XEC4900,0XE74500,0XE23E01,0XDE3900,0XD73301,0XCE2C01,0XC22601,0XB92101,0XB31D01,0XA81702,0XA01703,0X9B1303,0X971203,0X911004,0X8D0F04,0X910C04,0X8F0E04,0X8E0E03,0X920C04,0X940C04,0X980902,0X9B0A03,0XA30902,0XA60A02,0XA80902,0XAB0902,},
  {0XF17D00,0XF17600,0XF16F00,0XF16A00,0XF76300,0XF76200,0XF75F00,0XF75D00,0XF75E00,0XF75E00,0XF75F00,0XF75F00,0XF76100,0XF75F00,0XF75D00,0XF15D00,0XF75900,0XF15400,0XF15100,0XF14C00,0XEC4600,0XF14201,0XE73C00,0XDE3701,0XE23200,0XD72C01,0XCE2801,0XC62401,0XBF2001,0XB71C02,0XB51902,0XA91902,0XA41503,0X9F1303,0X9B1203,0X971102,0X971102,0X971003,0X980F03,0X990F02,0X9F0E02,0X9C0E03,0X9F0E03,0XA30D02,0XA20C02,0XA40C02,},
  {0XF18900,0XF18200,0XF17A00,0XF77400,0XF76D00,0XF76D00,0XF76B00,0XF76700,0XF76800,0XF76700,0XF76700,0XF76600,0XF76400,0XF16200,0XF76000,0XF15A00,0XF15700,0XF15300,0XF14E00,0XF14900,0XEC4400,0XF14200,0XE23C00,0XE73800,0XE23600,0XDE3301,0XDB2E00,0XDB2C01,0XD42901,0XD42501,0XC22301,0XBF1F02,0XB31C01,0XAE1A01,0XA91802,0XA41702,0XA41602,0XA21402,0XA01202,0XA01202,0XA01202,0XA31102,0XA01002,0XA21002,0XA01002,0XA01002,},
  {0XF19400,0XF18C00,0XF78400,0XF77F00,0XF77800,0XF77400,0XF77100,0XF77000,0XF76E00,0XF76B00,0XF76900,0XF76700,0XF16400,0XF16100,0XF15D00,0XF15800,0XF15400,0XF14F00,0XF14B00,0XF14700,0XF14400,0XF14100,0XEC4000,0XEC3C00,0XE73C00,0XE73900,0XE23600,0XE23401,0XE23201,0XD42E01,0XD42B02,0XC62701,0XBD2401,0XBB2101,0XB71F01,0XB01B02,0XAC1A02,0XAB1902,0XA81702,0XA61702,0XA31602,0XA41402,0XA21502,0XA01403,0X9F1403,0XA01403,},
  {0XF79F00,0XF79500,0XF78B00,0XF78400,0XF77D00,0XF77600,0XF77300,0XF76F00,0XF76D00,0XF76A00,0XF76700,0XF76400,0XF76100,0XF15D00,0XF75800,0XF15400,0XF15100,0XF14C00,0XF14900,0XEC4800,0XEC4400,0XE74200,0XE74100,0XDE3F00,0XE73F00,0XE23E00,0XDE3A01,0XD43B00,0XDB3901,0XD43401,0XCB3201,0XC42D01,0XC22801,0XBB2601,0XB52201,0XB01F01,0XAC1E01,0XA91C02,0XA91B02,0XA31902,0XA31902,0XA01902,0X9F1703,0X9D1703,0X9C1902,0X9B1703,},
  {0XF78B00,0XF78500,0XF77E00,0XF77C00,0XF17600,0XF17200,0XF16F00,0XF16B00,0XF16700,0XF76400,0XF16000,0XF15D00,0XF15A00,0XF15700,0XF15300,0XF14F00,0XEC4C00,0XEC4A00,0XEC4600,0XEC4300,0XE74200,0XE24000,0XDE3E00,0XE23D00,0XDE3D01,0XDE3A00,0XDB3A00,0XD43901,0XD13800,0XCB3401,0XC43102,0XBD2E01,0XB92901,0XB22601,0XAE2402,0XA82102,0XA41F02,0XA31E02,0XA31D03,0XA01C02,0X9F1B03,0X9C1B03,0X9C1B03,0X991A03,0X981A03,0X971B03,},
  {0XF78200,0XF77C00,0XF77700,0XF77500,0XF16F00,0XF76C00,0XF16700,0XF16400,0XF16200,0XF15D00,0XF15800,0XF15600,0XF75200,0XEC5000,0XEC4C00,0XEC4900,0XEC4700,0XE74200,0XE74100,0XE23F00,0XE73C01,0XDE3900,0XDE3800,0XDB3701,0XDB3701,0XD73501,0XD43401,0XD43401,0XCE3201,0XC23101,0XBD2F01,0XB92B02,0XB02702,0XAB2502,0XA42202,0XA02103,0XA01F02,0X9F1F03,0X9C1E03,0X9B1E03,0X9B1D03,0X991E03,0X971D03,0X971D03,0X981E03,0X951D04,},
  {0XF77700,0XF77200,0XF76F00,0XF76C00,0XF76800,0XF76400,0XF16100,0XF15D00,0XF15A00,0XF15400,0XEC5200,0XF14E00,0XEC4C00,0XEC4700,0XEC4400,0XE74100,0XE74000,0XE73C01,0XE73A00,0XE23701,0XDB3400,0XDE3200,0XD73001,0XD42F01,0XCE2E00,0XCB2E01,0XCB2D01,0XC42C01,0XBF2C01,0XBB2A01,0XB52902,0XB02702,0XA92602,0XA32202,0XA22102,0X9F2003,0X9C1F02,0X991F02,0X9B1F03,0X9B1E03,0X971F03,0X981E03,0X981E03,0X951E03,0X951E03,0X951E03,},
  {0XF76D00,0XF76900,0XF76700,0XF76400,0XF76100,0XF15E00,0XF15A00,0XF15800,0XF15300,0XEC5000,0XEC4C00,0XEC4800,0XE24400,0XE24000,0XEC3C00,0XEC3A00,0XDE3800,0XDE3401,0XDB3100,0XD72F00,0XD42C01,0XCB2901,0XC92701,0XC42601,0XC22601,0XBD2601,0XB72502,0XB52401,0XB22501,0XB02402,0XAC2202,0XA92301,0XA42202,0XA02102,0X9D1F02,0X9C1E03,0X9B1E03,0X991E03,0X971D03,0X981E03,0X981E03,0X971C03,0X971C03,0X971C03,0X971B02,0X951C03,},
  {0XFF6300,0XF75F00,0XF75F00,0XF75C00,0XF15900,0XF15800,0XF15600,0XF15200,0XF14F00,0XEC4A00,0XEC4700,0XE74300,0XE73D00,0XE23A00,0XE23600,0XDB3200,0XD73000,0XD42C01,0XCB2901,0XC92601,0XC22401,0XBB2101,0XB71F01,0XB01E02,0XAC1E02,0XA81C02,0XA41E02,0XA21E02,0XA21D03,0X9F1D03,0XA01E03,0X9F1E02,0X9D1D02,0X9C1D03,0X991C03,0X991C03,0X981B03,0X991B03,0X981C03,0X981B03,0X951B03,0X971A03,0X971A03,0X951903,0X951904,0X971804,},
  {0XFF5A00,0XF75600,0XF75600,0XF75400,0XF15100,0XF15200,0XF14F00,0XEC4F00,0XF14A00,0XEC4900,0XEC4400,0XE73F00,0XDE3900,0XD73600,0XD72F01,0XCB2C01,0XCB2901,0XC22402,0XBD2001,0XBB1E01,0XB21C02,0XAC1A02,0XA31801,0X9B1602,0X991602,0X931702,0X8F1604,0X8E1704,0X8D1803,0X8E1703,0X911904,0X921804,0X941803,0X941804,0X951703,0X951703,0X951803,0X971803,0X951703,0X971703,0X941703,0X951703,0X951703,0X951604,0X971404,0X971404,},
  {0XF75000,0XF74D00,0XF74D00,0XF14A00,0XF14900,0XF14A00,0XF14900,0XF14900,0XE74700,0XEC4600,0XEC4201,0XDE3C00,0XDB3700,0XD43100,0XCB2C01,0XC42701,0XBF2201,0XB71F01,0XAE1A02,0XA91902,0XA01603,0X991403,0X911303,0X8C1204,0X871104,0X821105,0X801204,0X7E1304,0X811304,0X831404,0X841304,0X881404,0X8C1404,0X8E1304,0X8E1304,0X911304,0X911204,0X921203,0X931404,0X941203,0X941204,0X941203,0X971103,0X991102,0X980F02,0X990F02,},
  {0XF74700,0XF14400,0XF74400,0XF14200,0XF14100,0XF14200,0XEC4200,0XE74200,0XE74201,0XE74201,0XE73E00,0XDB3C00,0XD73701,0XCE3101,0XC42A02,0XBB2201,0XB31E03,0XAC1A02,0XA01602,0X971304,0X8F1004,0X881105,0X831005,0X7D0F06,0X760F06,0X761006,0X741106,0X741007,0X751106,0X761006,0X7C1006,0X801106,0X861005,0X881004,0X8C0F04,0X8E0F04,0X8E0F04,0X910E03,0X930E03,0X940D04,0X980D02,0X9C0E03,0X9B0D02,0X9D0C03,0XA20B02,0XA30A02,},
  {0XF13E00,0XF13B00,0XF13A00,0XE73700,0XE73800,0XE73A00,0XE73801,0XE73C00,0XE23C00,0XE23E00,0XE23D00,0XD73901,0XD73601,0XCE3001,0XBF2901,0XB32301,0XA81B02,0X9D1703,0X911404,0X891104,0X830F04,0X7A0E06,0X750E06,0X710F06,0X700F06,0X6D0F07,0X6E0F07,0X6F0E06,0X700F06,0X750F06,0X790E05,0X800E05,0X840E05,0X8A0D04,0X8C0C04,0X910B04,0X950B04,0X970A03,0X9B0A03,0XA00A03,0XA30A03,0XA80902,0XAB0902,0XB00A02,0XB70802,0XB70801,},
  {0XEC3600,0XE73200,0XE73200,0XE22F00,0XDE2E00,0XE22F01,0XDB3001,0XDE3401,0XDB3600,0XDB3800,0XDB3A01,0XD73801,0XD43501,0XC93101,0XBB2901,0XAE2401,0XA41E03,0X931702,0X8B1405,0X821106,0X790F06,0X730F06,0X710F07,0X6F0E07,0X6B0F07,0X6B0E07,0X6C0F07,0X6E0E06,0X700E06,0X750E06,0X7B0C06,0X820E05,0X880C04,0X8E0C05,0X920A03,0X990B03,0X9D0904,0XA30902,0XAC0802,0XAE0902,0XB70702,0XBD0702,0XBF0602,0XBF0501,0XCB0502,0XC60501,},
  {0XE72D00,0XE22A00,0XDE2900,0XD72600,0XD42501,0XD12701,0XD12701,0XD12C01,0XD12F00,0XD43301,0XD43601,0XCE3601,0XCE3401,0XC93001,0XBB2B01,0XAC2502,0XA21E02,0X921903,0X851405,0X7C1206,0X730F06,0X6D0E07,0X6B0E07,0X6B0E07,0X6C0F07,0X6B0F07,0X6E0E06,0X700E06,0X750E06,0X790D05,0X800C05,0X870C04,0X8B0A04,0X930B03,0X9D0A03,0XA00902,0XA90902,0XB20802,0XB50701,0XBF0601,0XC60601,0XC90501,0XD10500,0XD40600,0XD70600,0XDE0401,},
  {0XDB2500,0XD72300,0XD72101,0XCE1F01,0XC91E01,0XC91F01,0XC21F01,0XC62202,0XC62701,0XC92D01,0XCB3200,0XCB3400,0XCB3401,0XC43101,0XB92B01,0XAC2603,0X9C2003,0X8E1A03,0X841505,0X781206,0X721107,0X6D1007,0X6B1007,0X6B0F07,0X6B0F07,0X6E0F06,0X700E06,0X750E06,0X790D06,0X800C05,0X850C04,0X8D0B04,0X940A03,0X9B0902,0XA30902,0XAC0802,0XB70901,0XBD0701,0XC90601,0XC90601,0XD40601,0XDE0600,0XE70600,0XEC0601,0XE20600,0XE20601,},
  {0XD11E01,0XCE1C01,0XCB1B01,0XC61801,0XBF1701,0XBB1801,0XBB1702,0XB71C02,0XB72101,0XBD2701,0XBF2D02,0XC43001,0XC63101,0XC22F02,0XB92C02,0XAC2802,0X9D2102,0X8F1D03,0X831804,0X791506,0X741306,0X6F1106,0X6D1106,0X6D0F07,0X6E0F06,0X710F06,0X750E06,0X790D06,0X7F0C05,0X850C04,0X8C0B04,0X940A03,0X9C0903,0XA30902,0XAC0802,0XB50701,0XBF0701,0XC90701,0XCE0701,0XDB0701,0XE20700,0XE70700,0XE70700,0XF10700,0XF10700,0XF10700,},
  {0XC61901,0XC21701,0XBD1601,0XB91401,0XB31302,0XAE1302,0XAB1402,0XAE1701,0XAC1C02,0XB32101,0XB92802,0XBB2D01,0XC42E02,0XBD2F01,0XB72C01,0XAC2902,0XA02302,0X931F04,0X861B04,0X7F1905,0X761606,0X731207,0X711207,0X711006,0X740F06,0X750F06,0X790E06,0X800C05,0X850C04,0X8C0B04,0X930A03,0X9C0902,0XA40902,0XAE0802,0XB70801,0XBF0801,0XC90701,0XD10801,0XD70801,0XE20800,0XE70900,0XEC0900,0XF10900,0XF10900,0XF70A00,0XF70A00,},
  {0XBB1401,0XB71201,0XB21102,0XAB1102,0XA80F02,0XA30F02,0X9D1003,0X9C1302,0XA01702,0XA61C02,0XAC2502,0XB32801,0XB92C01,0XB92D01,0XB72C02,0XAC2A02,0XA32702,0X972203,0X8D1E04,0X851B04,0X7B1705,0X771506,0X761306,0X771206,0X781106,0X7E0F06,0X820E05,0X860C04,0X8C0B04,0X940B03,0X9B0A02,0XA40902,0XAE0902,0XB70801,0XBF0801,0XC90801,0XD10901,0XD70901,0XDE0900,0XE70A00,0XEC0B00,0XF10C00,0XF70C00,0XF70D00,0XF70D00,0XF70E00,},
  {0XB01002,0XAB0F02,0XA60F02,0XA20E02,0X9D0E03,0X980D03,0X930E04,0X920F04,0X931403,0X981804,0X9F1F03,0XA82202,0XB02902,0XB32B01,0XB52C02,0XAE2A01,0XA42802,0X9D2403,0X932103,0X8A1E03,0X831B05,0X811804,0X7F1504,0X7F1304,0X801106,0X840F04,0X870E04,0X8E0C03,0X980C03,0X9C0A02,0XA30902,0XAE0902,0XB70901,0XBF0901,0XC90901,0XD10901,0XD70A01,0XDE0B00,0XE70C00,0XEC0D00,0XF10E00,0XF70F00,0XF71000,0XF71100,0XFF1200,0XFF1200,},
  {0XA30E02,0XA00D02,0X9C0D03,0X970C03,0X920C04,0X8C0D04,0X8A0D04,0X860F04,0X8A1104,0X8C1504,0X921A04,0X9B1E03,0XA62402,0XA92702,0XAC2802,0XAB2802,0XA82603,0XA02502,0X992202,0X921F03,0X8E1C04,0X8A1A04,0X881804,0X881604,0X8B1204,0X8E0F04,0X930F03,0X950C03,0X9D0C03,0XA60B02,0XAE0A02,0XB50A01,0XBF0901,0XCB0A01,0XD10A01,0XD70B01,0XDE0D00,0XE70E00,0XEC1000,0XF11100,0XF71200,0XF71400,0XFF1500,0XFF1600,0XFF1700,0XFF1700,},
  {0X980C03,0X940C03,0X910C04,0X8C0C04,0X880C04,0X840C04,0X800D04,0X7D0E05,0X7F0F05,0X811204,0X881704,0X911A03,0X971F03,0X9F2203,0XA42402,0XA42402,0XA32402,0XA22402,0X9C2202,0X982102,0X951F03,0X921C04,0X931A03,0X931603,0X931303,0X971103,0X9C0E02,0XA20D03,0XA80C02,0XB20A02,0XBB0B01,0XBF0A01,0XCB0A01,0XD10D01,0XDB0D00,0XE20E00,0XE70F00,0XEC1200,0XF11300,0XF71600,0XF71700,0XFF1A00,0XFF1B00,0XFF1D00,0XFF1E00,0XFF1E00,},
  {0X8D0B04,0X8A0C04,0X870C04,0X830C04,0X7F0C05,0X7B0C05,0X770D05,0X750D06,0X750F06,0X771005,0X7D1305,0X831605,0X8C1A04,0X921C04,0X991F03,0X9D1F03,0X9C1F03,0X9D2103,0X9C2102,0X9C2004,0X991E03,0X991C03,0X9B1903,0X991602,0X9D1402,0XA21202,0XA31102,0XAC0F01,0XB50E01,0XBB0D02,0XC40D01,0XCB0D01,0XD40F01,0XD70F01,0XDE1000,0XE71300,0XEC1400,0XF11700,0XF71900,0XF71C00,0XFF1E00,0XFF2000,0XFF2200,0XFF2400,0XFF2600,0XFF2600,},
  {0X840C04,0X810C05,0X7E0C05,0X7A0C05,0X760D06,0X730D06,0X710E06,0X6F0E06,0X6E0F06,0X6F0F07,0X731106,0X781305,0X811605,0X871704,0X8C1904,0X911B04,0X921C04,0X951D03,0X971C03,0X9B1D03,0X9B1B02,0X9C1903,0X9D1703,0XA01403,0XA61402,0XAC1202,0XB21201,0XB71101,0XBF1202,0XC91201,0XCE1201,0XD41200,0XDE1401,0XE21500,0XEC1600,0XEC1700,0XF71A00,0XF71C00,0XF71F00,0XFF2100,0XFF2400,0XFF2700,0XFF2A00,0XFF2C00,0XFF2E00,0XFF2F00,},
  {0X7A0C06,0X780C06,0X750D06,0X720D06,0X6F0E06,0X6C0E06,0X6B0E07,0X680F07,0X670F06,0X681007,0X6C1107,0X6E1206,0X761406,0X7C1406,0X821504,0X861704,0X891704,0X8E1904,0X911903,0X941A04,0X951903,0X991703,0X9F1602,0XA61503,0XAC1501,0XB71602,0XBB1602,0XC41701,0XCE1700,0XD41700,0XDE1700,0XDE1900,0XE71900,0XEC1A00,0XF11C00,0XF71E00,0XF72100,0XF72300,0XFF2600,0XFF2900,0XFF2C00,0XFF2F00,0XFF3200,0XFF3500,0XFF3600,0XFF3700,},
  {0X720D06,0X700E06,0X6E0E06,0X6B0E07,0X690F07,0X670F07,0X650F07,0X650F07,0X641007,0X631107,0X671107,0X691007,0X6E1106,0X741106,0X791205,0X7E1304,0X821205,0X881404,0X8B1604,0X8D1603,0X931603,0X981403,0XA01402,0XAB1502,0XB31602,0XBF1901,0XC61B01,0XD11C01,0XD41E01,0XDE1E00,0XE71F01,0XF12000,0XEC2200,0XEC2200,0XF72500,0XF72600,0XF72800,0XFF2A00,0XFF2E00,0XFF3100,0XFF3400,0XFF3700,0XFF3B00,0XFF3E00,0XFF3F00,0XFF4100,},
  {0X6B0E07,0X690E07,0X670F07,0X660F07,0X640F07,0X620F07,0X611007,0X601007,0X5F1007,0X601008,0X631107,0X641106,0X6A1107,0X6C1006,0X731006,0X771105,0X7C1105,0X821105,0X861204,0X8B1204,0X911204,0X981203,0XA31202,0XB01602,0XBD1901,0XC61C01,0XD11F01,0XD72101,0XDE2301,0XE72400,0XEC2500,0XEC2701,0XF72800,0XF72A00,0XF72C00,0XF72E00,0XFF3100,0XFF3200,0XFF3600,0XFF3900,0XFF3C00,0XFF4000,0XFF4400,0XFF4600,0XFF4900,0XFF4A00,},
  {0X650F07,0X640F07,0X620F07,0X621007,0X601007,0X5F1108,0X5E1108,0X5D1108,0X5D1108,0X5F1108,0X5F1108,0X621007,0X670F06,0X6B0F07,0X6F0E06,0X750F06,0X7A0E05,0X800F05,0X860E04,0X8A0F04,0X921003,0X991003,0XA41202,0XB31502,0XBD1A01,0XCB1E01,0XD72101,0XE22501,0XE22600,0XEC2800,0XEC2A00,0XF12D00,0XF12E00,0XFF3000,0XF73200,0XFF3500,0XFF3800,0XFF3A00,0XFF3E00,0XFF4100,0XFF4600,0XFF4900,0XFF4C00,0XFF4F00,0XFF5100,0XFF5300,},
  {0X601007,0X5F1008,0X5F1108,0X5D1108,0X5D1108,0X5C1108,0X5B1108,0X5B1108,0X5B1108,0X5D1108,0X5E1108,0X611007,0X650F07,0X6B0F06,0X6F0E06,0X750E06,0X7B0C05,0X810C04,0X860C04,0X8C0C03,0X920E03,0X9F0E02,0XA91102,0XB71402,0XC21902,0XCE1E01,0XDB2200,0XE72600,0XE72900,0XEC2C00,0XF72E00,0XF73100,0XF73200,0XF73600,0XFF3900,0XFF3A00,0XFF3E00,0XFF4100,0XFF4500,0XFF4900,0XFF4D00,0XFF5100,0XFF5500,0XFF5800,0XFF5B00,0XFF5D00,},
  {0X5D1108,0X5C1108,0X5B1108,0X5A1109,0X5A1109,0X5A1109,0X591209,0X5A1109,0X5A1109,0X5C1108,0X5E1108,0X621008,0X650F07,0X6A0E07,0X6F0E06,0X760C06,0X7D0C05,0X850B04,0X8C0A04,0X920A04,0X990B02,0XA20B02,0XAB0E02,0XB91202,0XC41601,0XD11A00,0XDB1F01,0XE22400,0XEC2700,0XF12B00,0XF72E00,0XFF3100,0XF73500,0XFF3900,0XFF3B00,0XFF4000,0XFF4300,0XFF4800,0XFF4C00,0XFF5000,0XFF5500,0XFF5A00,0XFF5E00,0XFF6200,0XFF6400,0XFF6700,},
  {0X5A1109,0X5A1109,0X591209,0X581209,0X581209,0X581209,0X581209,0X581209,0X5A1109,0X5B1108,0X5E1108,0X611008,0X650F07,0X6B0E07,0X710D06,0X780B06,0X7E0A05,0X880905,0X8F0904,0X970804,0XA00902,0XA60A02,0XB20C02,0XBD0E02,0XC91201,0XD41701,0XDE1B00,0XE72000,0XEC2500,0XF72900,0XF72D00,0XF73100,0XFF3500,0XFF3900,0XFF3E00,0XFF4300,0XFF4800,0XFF4D00,0XFF5200,0XFF5600,0XFF5D00,0XFF6200,0XFF6700,0XFF6B00,0XFF6E00,0XFF7000,},
  {0X581209,0X581209,0X581209,0X571209,0X571209,0X571209,0X571209,0X581209,0X591209,0X5B1109,0X5D1108,0X611008,0X650F07,0X6B0E07,0X710C06,0X780C06,0X810B05,0X890804,0X920704,0X9D0602,0XA60602,0XB20901,0XB90902,0XC40B01,0XCE0E01,0XD41200,0XDE1600,0XEC1A00,0XF12000,0XF12500,0XF72900,0XFF2F00,0XFF3400,0XFF3A00,0XFF3F00,0XFF4400,0XFF4C00,0XFF5100,0XFF5800,0XFF5D00,0XFF6400,0XFF6900,0XFF6F00,0XFF7400,0XFF7700,0XFF7A00,},
  {0X581209,0X581209,0X571209,0X571209,0X561209,0X561209,0X571209,0X581209,0X581209,0X5A1109,0X5D1108,0X611008,0X650F07,0X6B0E07,0X720C06,0X780B06,0X820A04,0X8A0804,0X970703,0X9F0602,0XAB0602,0XB30702,0XBF0602,0XCB0801,0XD40A01,0XDE0E00,0XEC1301,0XEC1600,0XF11A00,0XFF2100,0XFF2600,0XFF2C00,0XFF3200,0XFF3900,0XFF4100,0XFF4700,0XFF4E00,0XFF5400,0XFF5B00,0XFF6200,0XFF6900,0XFF7000,0XFF7600,0XFF7C00,0XFF8000,0XFF8300,},
  {0X581209,0X581209,0X581209,0X571209,0X561209,0X561209,0X571209,0X581209,0X581209,0X5A1109,0X5D1108,0X601008,0X640F07,0X6B0E07,0X710C06,0X790B06,0X820A05,0X8A0904,0X940703,0X9F0602,0XAB0602,0XB50601,0XBF0602,0XCB0601,0XD40901,0XDB0B00,0XEC0F00,0XEC1200,0XEC1700,0XF71C00,0XFF2400,0XFF2A00,0XFF3100,0XFF3800,0XFF4100,0XFF4800,0XFF5000,0XFF5800,0XFF6000,0XFF6700,0XFF6E00,0XFF7500,0XFF7C00,0XFF8300,0XFF8700,0XFF8B00,},
  {0X5A1209,0X591209,0X581209,0X581209,0X581209,0X571209,0X581209,0X581209,0X591209,0X5A1109,0X5D1108,0X601008,0X640F07,0X690E07,0X6F0D06,0X770C06,0X800A05,0X890904,0X920703,0X9D0603,0XA80602,0XB50502,0XC20501,0XC90701,0XD70701,0XDE0900,0XE70C00,0XF10F00,0XF71600,0XF71A00,0XF72100,0XFF2800,0XFF3100,0XFF3800,0XFF4000,0XFF4900,0XFF5100,0XFF5900,0XFF6200,0XFF6900,0XFF7100,0XFF7900,0XFF8100,0XFF8700,0XFF8C00,0XFF9100,},
  {0X5C1108,0X5B1109,0X5A1109,0X5A1109,0X591209,0X581209,0X581209,0X581209,0X591209,0X5A1109,0X5D1108,0X5F1108,0X630F07,0X670E07,0X6E0D06,0X750C06,0X7D0A05,0X860904,0X8E0804,0X990703,0XA40602,0XB00602,0XBB0501,0XC60601,0XD10701,0XDB0800,0XE20B00,0XEC0F00,0XF11400,0XF71900,0XF72100,0XFF2700,0XFF2E00,0XFF3600,0XFF3F00,0XFF4700,0XFF5000,0XFF5900,0XFF6100,0XFF6A00,0XFF7200,0XFF7B00,0XFF8300,0XFF8900,0XFF8F00,0XFF9400,},
  {0X5F1108,0X5E1108,0X5D1108,0X5C1108,0X5B1108,0X5A1109,0X5A1109,0X5A1109,0X5A1109,0X5B1108,0X5D1108,0X5F1108,0X620F07,0X670F07,0X6B0E06,0X720C06,0X790B05,0X820A04,0X8B0904,0X940703,0X9F0602,0XA90602,0XB50601,0XBF0601,0XCB0601,0XD40901,0XDE0B00,0XE70E00,0XEC1200,0XF11700,0XF71E00,0XF72400,0XFF2C00,0XFF3400,0XFF3D00,0XFF4600,0XFF4E00,0XFF5700,0XFF5F00,0XFF6800,0XFF7100,0XFF7900,0XFF8200,0XFF8900,0XFF8F00,0XFF9400,},
  {0X630F07,0X620F07,0X611007,0X5F1008,0X5E1108,0X5D1108,0X5C1108,0X5B1108,0X5B1108,0X5B1108,0X5D1108,0X5F1108,0X621007,0X650F07,0X6A0E07,0X6F0D06,0X760C06,0X7E0A05,0X870904,0X8F0804,0X990703,0XA40602,0XB00602,0XB90601,0XC40601,0XCE0801,0XD70A00,0XE20D00,0XEC1100,0XF11600,0XF71C00,0XF72200,0XFF2A00,0XFF3200,0XFF3A00,0XFF4200,0XFF4B00,0XFF5400,0XFF5D00,0XFF6500,0XFF6E00,0XFF7600,0XFF7E00,0XFF8600,0XFF8C00,0XFF9200,},
  {0X680E07,0X670F07,0X650F07,0X640F07,0X621007,0X601007,0X5F1108,0X5D1108,0X5D1108,0X5D1108,0X5D1108,0X5F1108,0X611007,0X640F07,0X670E07,0X6D0E06,0X730C06,0X7A0B05,0X820A04,0X8B0904,0X940803,0X9F0702,0XA90602,0XB30602,0XBF0601,0XC90701,0XD40901,0XDB0C00,0XE20F00,0XEC1400,0XF11900,0XF71F00,0XF72700,0XFF2F00,0XFF3700,0XFF3F00,0XFF4700,0XFF4F00,0XFF5800,0XFF6000,0XFF6800,0XFF7000,0XFF7900,0XFF8000,0XFF8700,0XFF8C00,},
  {0X6F0D06,0X6D0E06,0X6B0E07,0X680F07,0X660F07,0X640F07,0X620F07,0X601007,0X5F1107,0X5F1108,0X5E1108,0X5F1008,0X601008,0X630F07,0X660F07,0X6B0E07,0X6F0D06,0X760C06,0X7E0A05,0X860A04,0X8E0904,0X980703,0XA30702,0XAC0602,0XB70701,0XC20701,0XCB0901,0XD70B01,0XDE0E00,0XE71200,0XEC1700,0XF11C00,0XF72300,0XFF2A00,0XFF3200,0XFF3A00,0XFF4200,0XFF4A00,0XFF5200,0XFF5A00,0XFF6200,0XFF6A00,0XFF7100,0XFF7900,0XFF8000,0XFF8600,},
  {0X760C06,0X740C06,0X710D06,0X6F0E06,0X6B0E07,0X690E07,0X660F07,0X640F07,0X620F07,0X611007,0X601007,0X601008,0X611007,0X620F07,0X650F07,0X680E07,0X6D0E06,0X730C06,0X790C06,0X810A05,0X890904,0X920804,0X9C0703,0XA60702,0XB00702,0XBB0701,0XC60801,0XCE0A01,0XD70C00,0XE21000,0XEC1400,0XF11900,0XF71F00,0XF72600,0XFF2D00,0XFF3400,0XFF3C00,0XFF4400,0XFF4C00,0XFF5300,0XFF5A00,0XFF6200,0XFF6900,0XFF7000,0XFF7600,0XFF7C00,},
  {0X7F0A05,0X7C0A05,0X790B05,0X750C06,0X720D06,0X6F0E06,0X6B0E06,0X690E07,0X660F07,0X640F07,0X620F07,0X620F07,0X620F07,0X620F07,0X640F07,0X670F07,0X6B0E07,0X6F0D06,0X750C06,0X7C0B05,0X840A04,0X8C0904,0X950803,0X9F0702,0XA90702,0XB30702,0XBD0701,0XC90901,0XD10B01,0XDB0E00,0XE21100,0XEC1600,0XF11B00,0XF72100,0XF72700,0XFF2F00,0XFF3600,0XFF3D00,0XFF4400,0XFF4C00,0XFF5300,0XFF5900,0XFF6000,0XFF6700,0XFF6D00,0XFF7300,},
  {0X890904,0X860904,0X820A04,0X7E0A05,0X7A0C05,0X750C06,0X720D06,0X6E0E06,0X6B0E06,0X680E07,0X660F07,0X640F07,0X640F07,0X640F07,0X640F07,0X670F07,0X6A0E07,0X6E0E06,0X720C06,0X780C06,0X7F0A05,0X870904,0X8F0904,0X990703,0XA30702,0XAC0702,0XB70701,0XC20801,0XCB0A01,0XD40C01,0XDE0F00,0XE71200,0XEC1700,0XF11C00,0XF72200,0XF72900,0XFF2F00,0XFF3600,0XFF3D00,0XFF4400,0XFF4A00,0XFF5100,0XFF5700,0XFF5D00,0XFF6300,0XFF6800,},
};