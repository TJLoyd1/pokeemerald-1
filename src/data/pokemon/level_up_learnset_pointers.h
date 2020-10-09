const struct LevelUpMove *const gLevelUpLearnsets[NUM_SPECIES] =
{
    [SPECIES_NONE] = sBulbasaurLevelUpLearnset,
    [SPECIES_BULBASAUR] = sBulbasaurLevelUpLearnset,
    [SPECIES_IVYSAUR] = sIvysaurLevelUpLearnset,
    [SPECIES_VENUSAUR] = sVenusaurLevelUpLearnset,
    [SPECIES_CHARMANDER] = sCharmanderLevelUpLearnset,
    [SPECIES_CHARMELEON] = sCharmeleonLevelUpLearnset,
    [SPECIES_CHARIZARD] = sCharizardLevelUpLearnset,
    [SPECIES_SQUIRTLE] = sSquirtleLevelUpLearnset,
    [SPECIES_WARTORTLE] = sWartortleLevelUpLearnset,
    [SPECIES_BLASTOISE] = sBlastoiseLevelUpLearnset,
    [SPECIES_CATERPIE] = sCaterpieLevelUpLearnset,
    [SPECIES_METAPOD] = sMetapodLevelUpLearnset,
    [SPECIES_BUTTERFREE] = sButterfreeLevelUpLearnset,
    [SPECIES_WEEDLE] = sWeedleLevelUpLearnset,
    [SPECIES_KAKUNA] = sKakunaLevelUpLearnset,
    [SPECIES_BEEDRILL] = sBeedrillLevelUpLearnset,
    [SPECIES_PIDGEY] = sPidgeyLevelUpLearnset,
    [SPECIES_PIDGEOTTO] = sPidgeottoLevelUpLearnset,
    [SPECIES_PIDGEOT] = sPidgeotLevelUpLearnset,
    [SPECIES_RATTATA] = sRattataLevelUpLearnset,
    [SPECIES_RATICATE] = sRaticateLevelUpLearnset,
    [SPECIES_SPEAROW] = sSpearowLevelUpLearnset,
    [SPECIES_FEAROW] = sFearowLevelUpLearnset,
    [SPECIES_EKANS] = sEkansLevelUpLearnset,
    [SPECIES_ARBOK] = sArbokLevelUpLearnset,
    [SPECIES_PIKACHU] = sPikachuLevelUpLearnset,
    [SPECIES_RAICHU] = sRaichuLevelUpLearnset,
    [SPECIES_SANDSHREW] = sSandshrewLevelUpLearnset,
    [SPECIES_SANDSLASH] = sSandslashLevelUpLearnset,
    [SPECIES_NIDORAN_F] = sNidoranFLevelUpLearnset,
    [SPECIES_NIDORINA] = sNidorinaLevelUpLearnset,
    [SPECIES_NIDOQUEEN] = sNidoqueenLevelUpLearnset,
    [SPECIES_NIDORAN_M] = sNidoranMLevelUpLearnset,
    [SPECIES_NIDORINO] = sNidorinoLevelUpLearnset,
    [SPECIES_NIDOKING] = sNidokingLevelUpLearnset,
    [SPECIES_CLEFAIRY] = sClefairyLevelUpLearnset,
    [SPECIES_CLEFABLE] = sClefableLevelUpLearnset,
    [SPECIES_VULPIX] = sVulpixLevelUpLearnset,
    [SPECIES_NINETALES] = sNinetalesLevelUpLearnset,
    [SPECIES_JIGGLYPUFF] = sJigglypuffLevelUpLearnset,
    [SPECIES_WIGGLYTUFF] = sWigglytuffLevelUpLearnset,
    [SPECIES_ZUBAT] = sZubatLevelUpLearnset,
    [SPECIES_GOLBAT] = sGolbatLevelUpLearnset,
    [SPECIES_ODDISH] = sOddishLevelUpLearnset,
    [SPECIES_GLOOM] = sGloomLevelUpLearnset,
    [SPECIES_VILEPLUME] = sVileplumeLevelUpLearnset,
    [SPECIES_PARAS] = sParasLevelUpLearnset,
    [SPECIES_PARASECT] = sParasectLevelUpLearnset,
    [SPECIES_VENONAT] = sVenonatLevelUpLearnset,
    [SPECIES_VENOMOTH] = sVenomothLevelUpLearnset,
    [SPECIES_DIGLETT] = sDiglettLevelUpLearnset,
    [SPECIES_DUGTRIO] = sDugtrioLevelUpLearnset,
    [SPECIES_MEOWTH] = sMeowthLevelUpLearnset,
    [SPECIES_PERSIAN] = sPersianLevelUpLearnset,
    [SPECIES_PSYDUCK] = sPsyduckLevelUpLearnset,
    [SPECIES_GOLDUCK] = sGolduckLevelUpLearnset,
    [SPECIES_MANKEY] = sMankeyLevelUpLearnset,
    [SPECIES_PRIMEAPE] = sPrimeapeLevelUpLearnset,
    [SPECIES_GROWLITHE] = sGrowlitheLevelUpLearnset,
    [SPECIES_ARCANINE] = sArcanineLevelUpLearnset,
    [SPECIES_POLIWAG] = sPoliwagLevelUpLearnset,
    [SPECIES_POLIWHIRL] = sPoliwhirlLevelUpLearnset,
    [SPECIES_POLIWRATH] = sPoliwrathLevelUpLearnset,
    [SPECIES_ABRA] = sAbraLevelUpLearnset,
    [SPECIES_KADABRA] = sKadabraLevelUpLearnset,
    [SPECIES_ALAKAZAM] = sAlakazamLevelUpLearnset,
    [SPECIES_MACHOP] = sMachopLevelUpLearnset,
    [SPECIES_MACHOKE] = sMachokeLevelUpLearnset,
    [SPECIES_MACHAMP] = sMachampLevelUpLearnset,
    [SPECIES_BELLSPROUT] = sBellsproutLevelUpLearnset,
    [SPECIES_WEEPINBELL] = sWeepinbellLevelUpLearnset,
    [SPECIES_VICTREEBEL] = sVictreebelLevelUpLearnset,
    [SPECIES_TENTACOOL] = sTentacoolLevelUpLearnset,
    [SPECIES_TENTACRUEL] = sTentacruelLevelUpLearnset,
    [SPECIES_GEODUDE] = sGeodudeLevelUpLearnset,
    [SPECIES_GRAVELER] = sGravelerLevelUpLearnset,
    [SPECIES_GOLEM] = sGolemLevelUpLearnset,
    [SPECIES_PONYTA] = sPonytaLevelUpLearnset,
    [SPECIES_RAPIDASH] = sRapidashLevelUpLearnset,
    [SPECIES_SLOWPOKE] = sSlowpokeLevelUpLearnset,
    [SPECIES_SLOWBRO] = sSlowbroLevelUpLearnset,
    [SPECIES_MAGNEMITE] = sMagnemiteLevelUpLearnset,
    [SPECIES_MAGNETON] = sMagnetonLevelUpLearnset,
    [SPECIES_FARFETCHD] = sFarfetchdLevelUpLearnset,
    [SPECIES_DODUO] = sDoduoLevelUpLearnset,
    [SPECIES_DODRIO] = sDodrioLevelUpLearnset,
    [SPECIES_SEEL] = sSeelLevelUpLearnset,
    [SPECIES_DEWGONG] = sDewgongLevelUpLearnset,
    [SPECIES_GRIMER] = sGrimerLevelUpLearnset,
    [SPECIES_MUK] = sMukLevelUpLearnset,
    [SPECIES_SHELLDER] = sShellderLevelUpLearnset,
    [SPECIES_CLOYSTER] = sCloysterLevelUpLearnset,
    [SPECIES_GASTLY] = sGastlyLevelUpLearnset,
    [SPECIES_HAUNTER] = sHaunterLevelUpLearnset,
    [SPECIES_GENGAR] = sGengarLevelUpLearnset,
    [SPECIES_ONIX] = sOnixLevelUpLearnset,
    [SPECIES_DROWZEE] = sDrowzeeLevelUpLearnset,
    [SPECIES_HYPNO] = sHypnoLevelUpLearnset,
    [SPECIES_KRABBY] = sKrabbyLevelUpLearnset,
    [SPECIES_KINGLER] = sKinglerLevelUpLearnset,
    [SPECIES_VOLTORB] = sVoltorbLevelUpLearnset,
    [SPECIES_ELECTRODE] = sElectrodeLevelUpLearnset,
    [SPECIES_EXEGGCUTE] = sExeggcuteLevelUpLearnset,
    [SPECIES_EXEGGUTOR] = sExeggutorLevelUpLearnset,
    [SPECIES_CUBONE] = sCuboneLevelUpLearnset,
    [SPECIES_MAROWAK] = sMarowakLevelUpLearnset,
    [SPECIES_HITMONLEE] = sHitmonleeLevelUpLearnset,
    [SPECIES_HITMONCHAN] = sHitmonchanLevelUpLearnset,
    [SPECIES_LICKITUNG] = sLickitungLevelUpLearnset,
    [SPECIES_KOFFING] = sKoffingLevelUpLearnset,
    [SPECIES_WEEZING] = sWeezingLevelUpLearnset,
    [SPECIES_RHYHORN] = sRhyhornLevelUpLearnset,
    [SPECIES_RHYDON] = sRhydonLevelUpLearnset,
    [SPECIES_CHANSEY] = sChanseyLevelUpLearnset,
    [SPECIES_TANGELA] = sTangelaLevelUpLearnset,
    [SPECIES_KANGASKHAN] = sKangaskhanLevelUpLearnset,
    [SPECIES_HORSEA] = sHorseaLevelUpLearnset,
    [SPECIES_SEADRA] = sSeadraLevelUpLearnset,
    [SPECIES_GOLDEEN] = sGoldeenLevelUpLearnset,
    [SPECIES_SEAKING] = sSeakingLevelUpLearnset,
    [SPECIES_STARYU] = sStaryuLevelUpLearnset,
    [SPECIES_STARMIE] = sStarmieLevelUpLearnset,
    [SPECIES_MR_MIME] = sMrmimeLevelUpLearnset,
    [SPECIES_SCYTHER] = sScytherLevelUpLearnset,
    [SPECIES_JYNX] = sJynxLevelUpLearnset,
    [SPECIES_ELECTABUZZ] = sElectabuzzLevelUpLearnset,
    [SPECIES_MAGMAR] = sMagmarLevelUpLearnset,
    [SPECIES_PINSIR] = sPinsirLevelUpLearnset,
    [SPECIES_TAUROS] = sTaurosLevelUpLearnset,
    [SPECIES_MAGIKARP] = sMagikarpLevelUpLearnset,
    [SPECIES_GYARADOS] = sGyaradosLevelUpLearnset,
    [SPECIES_LAPRAS] = sLaprasLevelUpLearnset,
    [SPECIES_DITTO] = sDittoLevelUpLearnset,
    [SPECIES_EEVEE] = sEeveeLevelUpLearnset,
    [SPECIES_VAPOREON] = sVaporeonLevelUpLearnset,
    [SPECIES_JOLTEON] = sJolteonLevelUpLearnset,
    [SPECIES_FLAREON] = sFlareonLevelUpLearnset,
    [SPECIES_PORYGON] = sPorygonLevelUpLearnset,
    [SPECIES_OMANYTE] = sOmanyteLevelUpLearnset,
    [SPECIES_OMASTAR] = sOmastarLevelUpLearnset,
    [SPECIES_KABUTO] = sKabutoLevelUpLearnset,
    [SPECIES_KABUTOPS] = sKabutopsLevelUpLearnset,
    [SPECIES_AERODACTYL] = sAerodactylLevelUpLearnset,
    [SPECIES_SNORLAX] = sSnorlaxLevelUpLearnset,
    [SPECIES_ARTICUNO] = sArticunoLevelUpLearnset,
    [SPECIES_ZAPDOS] = sZapdosLevelUpLearnset,
    [SPECIES_MOLTRES] = sMoltresLevelUpLearnset,
    [SPECIES_DRATINI] = sDratiniLevelUpLearnset,
    [SPECIES_DRAGONAIR] = sDragonairLevelUpLearnset,
    [SPECIES_DRAGONITE] = sDragoniteLevelUpLearnset,
    [SPECIES_MEWTWO] = sMewtwoLevelUpLearnset,
    [SPECIES_MEW] = sMewLevelUpLearnset,
    [SPECIES_CHIKORITA] = sChikoritaLevelUpLearnset,
    [SPECIES_BAYLEEF] = sBayleefLevelUpLearnset,
    [SPECIES_MEGANIUM] = sMeganiumLevelUpLearnset,
    [SPECIES_CYNDAQUIL] = sCyndaquilLevelUpLearnset,
    [SPECIES_QUILAVA] = sQuilavaLevelUpLearnset,
    [SPECIES_TYPHLOSION] = sTyphlosionLevelUpLearnset,
    [SPECIES_TOTODILE] = sTotodileLevelUpLearnset,
    [SPECIES_CROCONAW] = sCroconawLevelUpLearnset,
    [SPECIES_FERALIGATR] = sFeraligatrLevelUpLearnset,
    [SPECIES_SENTRET] = sSentretLevelUpLearnset,
    [SPECIES_FURRET] = sFurretLevelUpLearnset,
    [SPECIES_HOOTHOOT] = sHoothootLevelUpLearnset,
    [SPECIES_NOCTOWL] = sNoctowlLevelUpLearnset,
    [SPECIES_LEDYBA] = sLedybaLevelUpLearnset,
    [SPECIES_LEDIAN] = sLedianLevelUpLearnset,
    [SPECIES_SPINARAK] = sSpinarakLevelUpLearnset,
    [SPECIES_ARIADOS] = sAriadosLevelUpLearnset,
    [SPECIES_CROBAT] = sCrobatLevelUpLearnset,
    [SPECIES_CHINCHOU] = sChinchouLevelUpLearnset,
    [SPECIES_LANTURN] = sLanturnLevelUpLearnset,
    [SPECIES_PICHU] = sPichuLevelUpLearnset,
    [SPECIES_CLEFFA] = sCleffaLevelUpLearnset,
    [SPECIES_IGGLYBUFF] = sIgglybuffLevelUpLearnset,
    [SPECIES_TOGEPI] = sTogepiLevelUpLearnset,
    [SPECIES_TOGETIC] = sTogeticLevelUpLearnset,
    [SPECIES_NATU] = sNatuLevelUpLearnset,
    [SPECIES_XATU] = sXatuLevelUpLearnset,
    [SPECIES_MAREEP] = sMareepLevelUpLearnset,
    [SPECIES_FLAAFFY] = sFlaaffyLevelUpLearnset,
    [SPECIES_AMPHAROS] = sAmpharosLevelUpLearnset,
    [SPECIES_BELLOSSOM] = sBellossomLevelUpLearnset,
    [SPECIES_MARILL] = sMarillLevelUpLearnset,
    [SPECIES_AZUMARILL] = sAzumarillLevelUpLearnset,
    [SPECIES_SUDOWOODO] = sSudowoodoLevelUpLearnset,
    [SPECIES_POLITOED] = sPolitoedLevelUpLearnset,
    [SPECIES_HOPPIP] = sHoppipLevelUpLearnset,
    [SPECIES_SKIPLOOM] = sSkiploomLevelUpLearnset,
    [SPECIES_JUMPLUFF] = sJumpluffLevelUpLearnset,
    [SPECIES_AIPOM] = sAipomLevelUpLearnset,
    [SPECIES_SUNKERN] = sSunkernLevelUpLearnset,
    [SPECIES_SUNFLORA] = sSunfloraLevelUpLearnset,
    [SPECIES_YANMA] = sYanmaLevelUpLearnset,
    [SPECIES_WOOPER] = sWooperLevelUpLearnset,
    [SPECIES_QUAGSIRE] = sQuagsireLevelUpLearnset,
    [SPECIES_ESPEON] = sEspeonLevelUpLearnset,
    [SPECIES_UMBREON] = sUmbreonLevelUpLearnset,
    [SPECIES_MURKROW] = sMurkrowLevelUpLearnset,
    [SPECIES_SLOWKING] = sSlowkingLevelUpLearnset,
    [SPECIES_MISDREAVUS] = sMisdreavusLevelUpLearnset,
    [SPECIES_UNOWN] = sUnownLevelUpLearnset,
    [SPECIES_WOBBUFFET] = sWobbuffetLevelUpLearnset,
    [SPECIES_GIRAFARIG] = sGirafarigLevelUpLearnset,
    [SPECIES_PINECO] = sPinecoLevelUpLearnset,
    [SPECIES_FORRETRESS] = sForretressLevelUpLearnset,
    [SPECIES_DUNSPARCE] = sDunsparceLevelUpLearnset,
    [SPECIES_GLIGAR] = sGligarLevelUpLearnset,
    [SPECIES_STEELIX] = sSteelixLevelUpLearnset,
    [SPECIES_SNUBBULL] = sSnubbullLevelUpLearnset,
    [SPECIES_GRANBULL] = sGranbullLevelUpLearnset,
    [SPECIES_QWILFISH] = sQwilfishLevelUpLearnset,
    [SPECIES_SCIZOR] = sScizorLevelUpLearnset,
    [SPECIES_SHUCKLE] = sShuckleLevelUpLearnset,
    [SPECIES_HERACROSS] = sHeracrossLevelUpLearnset,
    [SPECIES_SNEASEL] = sSneaselLevelUpLearnset,
    [SPECIES_TEDDIURSA] = sTeddiursaLevelUpLearnset,
    [SPECIES_URSARING] = sUrsaringLevelUpLearnset,
    [SPECIES_SLUGMA] = sSlugmaLevelUpLearnset,
    [SPECIES_MAGCARGO] = sMagcargoLevelUpLearnset,
    [SPECIES_SWINUB] = sSwinubLevelUpLearnset,
    [SPECIES_PILOSWINE] = sPiloswineLevelUpLearnset,
    [SPECIES_CORSOLA] = sCorsolaLevelUpLearnset,
    [SPECIES_REMORAID] = sRemoraidLevelUpLearnset,
    [SPECIES_OCTILLERY] = sOctilleryLevelUpLearnset,
    [SPECIES_DELIBIRD] = sDelibirdLevelUpLearnset,
    [SPECIES_MANTINE] = sMantineLevelUpLearnset,
    [SPECIES_SKARMORY] = sSkarmoryLevelUpLearnset,
    [SPECIES_HOUNDOUR] = sHoundourLevelUpLearnset,
    [SPECIES_HOUNDOOM] = sHoundoomLevelUpLearnset,
    [SPECIES_KINGDRA] = sKingdraLevelUpLearnset,
    [SPECIES_PHANPY] = sPhanpyLevelUpLearnset,
    [SPECIES_DONPHAN] = sDonphanLevelUpLearnset,
    [SPECIES_PORYGON2] = sPorygon2LevelUpLearnset,
    [SPECIES_STANTLER] = sStantlerLevelUpLearnset,
    [SPECIES_SMEARGLE] = sSmeargleLevelUpLearnset,
    [SPECIES_TYROGUE] = sTyrogueLevelUpLearnset,
    [SPECIES_HITMONTOP] = sHitmontopLevelUpLearnset,
    [SPECIES_SMOOCHUM] = sSmoochumLevelUpLearnset,
    [SPECIES_ELEKID] = sElekidLevelUpLearnset,
    [SPECIES_MAGBY] = sMagbyLevelUpLearnset,
    [SPECIES_MILTANK] = sMiltankLevelUpLearnset,
    [SPECIES_BLISSEY] = sBlisseyLevelUpLearnset,
    [SPECIES_RAIKOU] = sRaikouLevelUpLearnset,
    [SPECIES_ENTEI] = sEnteiLevelUpLearnset,
    [SPECIES_SUICUNE] = sSuicuneLevelUpLearnset,
    [SPECIES_LARVITAR] = sLarvitarLevelUpLearnset,
    [SPECIES_PUPITAR] = sPupitarLevelUpLearnset,
    [SPECIES_TYRANITAR] = sTyranitarLevelUpLearnset,
    [SPECIES_LUGIA] = sLugiaLevelUpLearnset,
    [SPECIES_HO_OH] = sHoOhLevelUpLearnset,
    [SPECIES_CELEBI] = sCelebiLevelUpLearnset,
    [SPECIES_TREECKO] = sTreeckoLevelUpLearnset,
    [SPECIES_GROVYLE] = sGrovyleLevelUpLearnset,
    [SPECIES_SCEPTILE] = sSceptileLevelUpLearnset,
    [SPECIES_TORCHIC] = sTorchicLevelUpLearnset,
    [SPECIES_COMBUSKEN] = sCombuskenLevelUpLearnset,
    [SPECIES_BLAZIKEN] = sBlazikenLevelUpLearnset,
    [SPECIES_MUDKIP] = sMudkipLevelUpLearnset,
    [SPECIES_MARSHTOMP] = sMarshtompLevelUpLearnset,
    [SPECIES_SWAMPERT] = sSwampertLevelUpLearnset,
    [SPECIES_POOCHYENA] = sPoochyenaLevelUpLearnset,
    [SPECIES_MIGHTYENA] = sMightyenaLevelUpLearnset,
    [SPECIES_ZIGZAGOON] = sZigzagoonLevelUpLearnset,
    [SPECIES_LINOONE] = sLinooneLevelUpLearnset,
    [SPECIES_WURMPLE] = sWurmpleLevelUpLearnset,
    [SPECIES_SILCOON] = sSilcoonLevelUpLearnset,
    [SPECIES_BEAUTIFLY] = sBeautiflyLevelUpLearnset,
    [SPECIES_CASCOON] = sCascoonLevelUpLearnset,
    [SPECIES_DUSTOX] = sDustoxLevelUpLearnset,
    [SPECIES_LOTAD] = sLotadLevelUpLearnset,
    [SPECIES_LOMBRE] = sLombreLevelUpLearnset,
    [SPECIES_LUDICOLO] = sLudicoloLevelUpLearnset,
    [SPECIES_SEEDOT] = sSeedotLevelUpLearnset,
    [SPECIES_NUZLEAF] = sNuzleafLevelUpLearnset,
    [SPECIES_SHIFTRY] = sShiftryLevelUpLearnset,
    [SPECIES_NINCADA] = sNincadaLevelUpLearnset,
    [SPECIES_NINJASK] = sNinjaskLevelUpLearnset,
    [SPECIES_SHEDINJA] = sShedinjaLevelUpLearnset,
    [SPECIES_TAILLOW] = sTaillowLevelUpLearnset,
    [SPECIES_SWELLOW] = sSwellowLevelUpLearnset,
    [SPECIES_SHROOMISH] = sShroomishLevelUpLearnset,
    [SPECIES_BRELOOM] = sBreloomLevelUpLearnset,
    [SPECIES_SPINDA] = sSpindaLevelUpLearnset,
    [SPECIES_WINGULL] = sWingullLevelUpLearnset,
    [SPECIES_PELIPPER] = sPelipperLevelUpLearnset,
    [SPECIES_SURSKIT] = sSurskitLevelUpLearnset,
    [SPECIES_MASQUERAIN] = sMasquerainLevelUpLearnset,
    [SPECIES_WAILMER] = sWailmerLevelUpLearnset,
    [SPECIES_WAILORD] = sWailordLevelUpLearnset,
    [SPECIES_SKITTY] = sSkittyLevelUpLearnset,
    [SPECIES_DELCATTY] = sDelcattyLevelUpLearnset,
    [SPECIES_KECLEON] = sKecleonLevelUpLearnset,
    [SPECIES_BALTOY] = sBaltoyLevelUpLearnset,
    [SPECIES_CLAYDOL] = sClaydolLevelUpLearnset,
    [SPECIES_NOSEPASS] = sNosepassLevelUpLearnset,
    [SPECIES_TORKOAL] = sTorkoalLevelUpLearnset,
    [SPECIES_SABLEYE] = sSableyeLevelUpLearnset,
    [SPECIES_BARBOACH] = sBarboachLevelUpLearnset,
    [SPECIES_WHISCASH] = sWhiscashLevelUpLearnset,
    [SPECIES_LUVDISC] = sLuvdiscLevelUpLearnset,
    [SPECIES_CORPHISH] = sCorphishLevelUpLearnset,
    [SPECIES_CRAWDAUNT] = sCrawdauntLevelUpLearnset,
    [SPECIES_FEEBAS] = sFeebasLevelUpLearnset,
    [SPECIES_MILOTIC] = sMiloticLevelUpLearnset,
    [SPECIES_CARVANHA] = sCarvanhaLevelUpLearnset,
    [SPECIES_SHARPEDO] = sSharpedoLevelUpLearnset,
    [SPECIES_TRAPINCH] = sTrapinchLevelUpLearnset,
    [SPECIES_VIBRAVA] = sVibravaLevelUpLearnset,
    [SPECIES_FLYGON] = sFlygonLevelUpLearnset,
    [SPECIES_MAKUHITA] = sMakuhitaLevelUpLearnset,
    [SPECIES_HARIYAMA] = sHariyamaLevelUpLearnset,
    [SPECIES_ELECTRIKE] = sElectrikeLevelUpLearnset,
    [SPECIES_MANECTRIC] = sManectricLevelUpLearnset,
    [SPECIES_NUMEL] = sNumelLevelUpLearnset,
    [SPECIES_CAMERUPT] = sCameruptLevelUpLearnset,
    [SPECIES_SPHEAL] = sSphealLevelUpLearnset,
    [SPECIES_SEALEO] = sSealeoLevelUpLearnset,
    [SPECIES_WALREIN] = sWalreinLevelUpLearnset,
    [SPECIES_CACNEA] = sCacneaLevelUpLearnset,
    [SPECIES_CACTURNE] = sCacturneLevelUpLearnset,
    [SPECIES_SNORUNT] = sSnoruntLevelUpLearnset,
    [SPECIES_GLALIE] = sGlalieLevelUpLearnset,
    [SPECIES_LUNATONE] = sLunatoneLevelUpLearnset,
    [SPECIES_SOLROCK] = sSolrockLevelUpLearnset,
    [SPECIES_AZURILL] = sAzurillLevelUpLearnset,
    [SPECIES_SPOINK] = sSpoinkLevelUpLearnset,
    [SPECIES_GRUMPIG] = sGrumpigLevelUpLearnset,
    [SPECIES_PLUSLE] = sPlusleLevelUpLearnset,
    [SPECIES_MINUN] = sMinunLevelUpLearnset,
    [SPECIES_MAWILE] = sMawileLevelUpLearnset,
    [SPECIES_MEDITITE] = sMedititeLevelUpLearnset,
    [SPECIES_MEDICHAM] = sMedichamLevelUpLearnset,
    [SPECIES_SWABLU] = sSwabluLevelUpLearnset,
    [SPECIES_ALTARIA] = sAltariaLevelUpLearnset,
    [SPECIES_WYNAUT] = sWynautLevelUpLearnset,
    [SPECIES_DUSKULL] = sDuskullLevelUpLearnset,
    [SPECIES_DUSCLOPS] = sDusclopsLevelUpLearnset,
    [SPECIES_ROSELIA] = sRoseliaLevelUpLearnset,
    [SPECIES_SLAKOTH] = sSlakothLevelUpLearnset,
    [SPECIES_VIGOROTH] = sVigorothLevelUpLearnset,
    [SPECIES_SLAKING] = sSlakingLevelUpLearnset,
    [SPECIES_GULPIN] = sGulpinLevelUpLearnset,
    [SPECIES_SWALOT] = sSwalotLevelUpLearnset,
    [SPECIES_TROPIUS] = sTropiusLevelUpLearnset,
    [SPECIES_WHISMUR] = sWhismurLevelUpLearnset,
    [SPECIES_LOUDRED] = sLoudredLevelUpLearnset,
    [SPECIES_EXPLOUD] = sExploudLevelUpLearnset,
    [SPECIES_CLAMPERL] = sClamperlLevelUpLearnset,
    [SPECIES_HUNTAIL] = sHuntailLevelUpLearnset,
    [SPECIES_GOREBYSS] = sGorebyssLevelUpLearnset,
    [SPECIES_ABSOL] = sAbsolLevelUpLearnset,
    [SPECIES_SHUPPET] = sShuppetLevelUpLearnset,
    [SPECIES_BANETTE] = sBanetteLevelUpLearnset,
    [SPECIES_SEVIPER] = sSeviperLevelUpLearnset,
    [SPECIES_ZANGOOSE] = sZangooseLevelUpLearnset,
    [SPECIES_RELICANTH] = sRelicanthLevelUpLearnset,
    [SPECIES_ARON] = sAronLevelUpLearnset,
    [SPECIES_LAIRON] = sLaironLevelUpLearnset,
    [SPECIES_AGGRON] = sAggronLevelUpLearnset,
    [SPECIES_CASTFORM] = sCastformLevelUpLearnset,
    [SPECIES_VOLBEAT] = sVolbeatLevelUpLearnset,
    [SPECIES_ILLUMISE] = sIllumiseLevelUpLearnset,
    [SPECIES_LILEEP] = sLileepLevelUpLearnset,
    [SPECIES_CRADILY] = sCradilyLevelUpLearnset,
    [SPECIES_ANORITH] = sAnorithLevelUpLearnset,
    [SPECIES_ARMALDO] = sArmaldoLevelUpLearnset,
    [SPECIES_RALTS] = sRaltsLevelUpLearnset,
    [SPECIES_KIRLIA] = sKirliaLevelUpLearnset,
    [SPECIES_GARDEVOIR] = sGardevoirLevelUpLearnset,
    [SPECIES_BAGON] = sBagonLevelUpLearnset,
    [SPECIES_SHELGON] = sShelgonLevelUpLearnset,
    [SPECIES_SALAMENCE] = sSalamenceLevelUpLearnset,
    [SPECIES_BELDUM] = sBeldumLevelUpLearnset,
    [SPECIES_METANG] = sMetangLevelUpLearnset,
    [SPECIES_METAGROSS] = sMetagrossLevelUpLearnset,
    [SPECIES_REGIROCK] = sRegirockLevelUpLearnset,
    [SPECIES_REGICE] = sRegiceLevelUpLearnset,
    [SPECIES_REGISTEEL] = sRegisteelLevelUpLearnset,
    [SPECIES_KYOGRE] = sKyogreLevelUpLearnset,
    [SPECIES_GROUDON] = sGroudonLevelUpLearnset,
    [SPECIES_RAYQUAZA] = sRayquazaLevelUpLearnset,
    [SPECIES_LATIAS] = sLatiasLevelUpLearnset,
    [SPECIES_LATIOS] = sLatiosLevelUpLearnset,
    [SPECIES_JIRACHI] = sJirachiLevelUpLearnset,
    [SPECIES_DEOXYS] = sDeoxysLevelUpLearnset,
    [SPECIES_CHIMECHO] = sChimechoLevelUpLearnset,
    [SPECIES_TURTWIG] = sTurtwigLevelUpLearnset,
    [SPECIES_GROTLE] = sGrotleLevelUpLearnset,
    [SPECIES_TORTERRA] = sTorterraLevelUpLearnset,
    [SPECIES_CHIMCHAR] = sChimcharLevelUpLearnset,
    [SPECIES_MONFERNO] = sMonfernoLevelUpLearnset,
    [SPECIES_INFERNAPE] = sInfernapeLevelUpLearnset,
    [SPECIES_PIPLUP] = sPiplupLevelUpLearnset,
    [SPECIES_PRINPLUP] = sPrinplupLevelUpLearnset,
    [SPECIES_EMPOLEON] = sEmpoleonLevelUpLearnset,
    [SPECIES_STARLY] = sStarlyLevelUpLearnset,
    [SPECIES_STARAVIA] = sStaraviaLevelUpLearnset,
    [SPECIES_STARAPTOR] = sStaraptorLevelUpLearnset,
    [SPECIES_BIDOOF] = sBidoofLevelUpLearnset,
    [SPECIES_BIBAREL] = sBibarelLevelUpLearnset,
    [SPECIES_KRICKETOT] = sKricketotLevelUpLearnset,
    [SPECIES_KRICKETUNE] = sKricketuneLevelUpLearnset,
    [SPECIES_SHINX] = sShinxLevelUpLearnset,
    [SPECIES_LUXIO] = sLuxioLevelUpLearnset,
    [SPECIES_LUXRAY] = sLuxrayLevelUpLearnset,
    [SPECIES_BUDEW] = sBudewLevelUpLearnset,
    [SPECIES_ROSERADE] = sRoseradeLevelUpLearnset,
    [SPECIES_CRANIDOS] = sCranidosLevelUpLearnset,
    [SPECIES_RAMPARDOS] = sRampardosLevelUpLearnset,
    [SPECIES_SHIELDON] = sShieldonLevelUpLearnset,
    [SPECIES_BASTIODON] = sBastiodonLevelUpLearnset,
    [SPECIES_BURMY] = sBurmyLevelUpLearnset,
    [SPECIES_BURMY_SANDY] = sBurmyLevelUpLearnset,
    [SPECIES_BURMY_TRASH] = sBurmyLevelUpLearnset,
    [SPECIES_WORMADAM] = sWormadamPlantLevelUpLearnset,
    [SPECIES_WORMADAM_SANDY] = sWormadamSandyLevelUpLearnset,
    [SPECIES_WORMADAM_TRASH] = sWormadamTrashLevelUpLearnset,
    [SPECIES_MOTHIM] = sMothimLevelUpLearnset,
    [SPECIES_COMBEE] = sCombeeLevelUpLearnset,
    [SPECIES_VESPIQUEN] = sVespiquenLevelUpLearnset,
    [SPECIES_PACHIRISU] = sPachirisuLevelUpLearnset,
    [SPECIES_BUIZEL] = sBuizelLevelUpLearnset,
    [SPECIES_FLOATZEL] = sFloatzelLevelUpLearnset,
    [SPECIES_CHERUBI] = sCherubiLevelUpLearnset,
    [SPECIES_CHERRIM] = sCherrimLevelUpLearnset,
    [SPECIES_SHELLOS] = sShellosLevelUpLearnset,
    [SPECIES_GASTRODON] = sGastrodonLevelUpLearnset,
    [SPECIES_AMBIPOM] = sAmbipomLevelUpLearnset,
    [SPECIES_DRIFLOON] = sDrifloonLevelUpLearnset,
    [SPECIES_DRIFBLIM] = sDrifblimLevelUpLearnset,
    [SPECIES_BUNEARY] = sBunearyLevelUpLearnset,
    [SPECIES_LOPUNNY] = sLopunnyLevelUpLearnset,
    [SPECIES_MISMAGIUS] = sMismagiusLevelUpLearnset,
    [SPECIES_HONCHKROW] = sHonchkrowLevelUpLearnset,
    [SPECIES_GLAMEOW] = sGlameowLevelUpLearnset,
    [SPECIES_PURUGLY] = sPuruglyLevelUpLearnset,
    [SPECIES_CHINGLING] = sChinglingLevelUpLearnset,
    [SPECIES_STUNKY] = sStunkyLevelUpLearnset,
    [SPECIES_SKUNTANK] = sSkuntankLevelUpLearnset,
    [SPECIES_BRONZOR] = sBronzorLevelUpLearnset,
    [SPECIES_BRONZONG] = sBronzongLevelUpLearnset,
    [SPECIES_BONSLY] = sBonslyLevelUpLearnset,
    [SPECIES_MIMEJR] = sMimejrLevelUpLearnset,
    [SPECIES_HAPPINY] = sHappinyLevelUpLearnset,
    [SPECIES_CHATOT] = sChatotLevelUpLearnset,
    [SPECIES_SPIRITOMB] = sSpiritombLevelUpLearnset,
    [SPECIES_GIBLE] = sGibleLevelUpLearnset,
    [SPECIES_GABITE] = sGabiteLevelUpLearnset,
    [SPECIES_GARCHOMP] = sGarchompLevelUpLearnset,
    [SPECIES_MUNCHLAX] = sMunchlaxLevelUpLearnset,
    [SPECIES_RIOLU] = sRioluLevelUpLearnset,
    [SPECIES_LUCARIO] = sLucarioLevelUpLearnset,
    [SPECIES_HIPPOPOTAS] = sHippopotasLevelUpLearnset,
    [SPECIES_HIPPOWDON] = sHippowdonLevelUpLearnset,
    [SPECIES_SKORUPI] = sSkorupiLevelUpLearnset,
    [SPECIES_DRAPION] = sDrapionLevelUpLearnset,
    [SPECIES_CROAGUNK] = sCroagunkLevelUpLearnset,
    [SPECIES_TOXICROAK] = sToxicroakLevelUpLearnset,
    [SPECIES_CARNIVINE] = sCarnivineLevelUpLearnset,
    [SPECIES_FINNEON] = sFinneonLevelUpLearnset,
    [SPECIES_LUMINEON] = sLumineonLevelUpLearnset,
    [SPECIES_MANTYKE] = sMantykeLevelUpLearnset,
    [SPECIES_SNOVER] = sSnoverLevelUpLearnset,
    [SPECIES_ABOMASNOW] = sAbomasnowLevelUpLearnset,
    [SPECIES_WEAVILE] = sWeavileLevelUpLearnset,
    [SPECIES_MAGNEZONE] = sMagnezoneLevelUpLearnset,
    [SPECIES_LICKILICKY] = sLickilickyLevelUpLearnset,
    [SPECIES_RHYPERIOR] = sRhyperiorLevelUpLearnset,
    [SPECIES_TANGROWTH] = sTangrowthLevelUpLearnset,
    [SPECIES_ELECTIVIRE] = sElectivireLevelUpLearnset,
    [SPECIES_MAGMORTAR] = sMagmortarLevelUpLearnset,
    [SPECIES_TOGEKISS] = sTogekissLevelUpLearnset,
    [SPECIES_YANMEGA] = sYanmegaLevelUpLearnset,
    [SPECIES_LEAFEON] = sLeafeonLevelUpLearnset,
    [SPECIES_GLACEON] = sGlaceonLevelUpLearnset,
    [SPECIES_GLISCOR] = sGliscorLevelUpLearnset,
    [SPECIES_MAMOSWINE] = sMamoswineLevelUpLearnset,
    [SPECIES_PORYGON_Z] = sPorygonZLevelUpLearnset,
    [SPECIES_GALLADE] = sGalladeLevelUpLearnset,
    [SPECIES_PROBOPASS] = sProbopassLevelUpLearnset,
    [SPECIES_DUSKNOIR] = sDusknoirLevelUpLearnset,
    [SPECIES_FROSLASS] = sFroslassLevelUpLearnset,
    [SPECIES_ROTOM] = sRotomLevelUpLearnset,
    [SPECIES_ROTOM_FAN] = sRotomLevelUpLearnset,
    [SPECIES_ROTOM_FROST] = sRotomLevelUpLearnset,
    [SPECIES_ROTOM_HEAT] = sRotomLevelUpLearnset,
    [SPECIES_ROTOM_MOW] = sRotomLevelUpLearnset,
    [SPECIES_ROTOM_WASH] = sRotomLevelUpLearnset,
    [SPECIES_UXIE] = sUxieLevelUpLearnset,
    [SPECIES_MESPRIT] = sMespritLevelUpLearnset,
    [SPECIES_AZELF] = sAzelfLevelUpLearnset,
    [SPECIES_DIALGA] = sDialgaLevelUpLearnset,
    [SPECIES_PALKIA] = sPalkiaLevelUpLearnset,
    [SPECIES_HEATRAN] = sHeatranLevelUpLearnset,
    [SPECIES_REGIGIGAS] = sRegigigasLevelUpLearnset,
    [SPECIES_GIRATINA] = sGiratinaLevelUpLearnset,
    [SPECIES_CRESSELIA] = sCresseliaLevelUpLearnset,
    [SPECIES_PHIONE] = sPhioneLevelUpLearnset,
    [SPECIES_MANAPHY] = sManaphyLevelUpLearnset,
    [SPECIES_DARKRAI] = sDarkraiLevelUpLearnset,
    [SPECIES_SHAYMIN] = sShayminLevelUpLearnset,
    [SPECIES_ARCEUS] = sArceusLevelUpLearnset,
    [SPECIES_AUDINO] = sAudinoLevelUpLearnset,
    [SPECIES_DIANCIE] = sDiancieLevelUpLearnset,
    // Megas have the same learnsets
    [SPECIES_MEGA_VENUSAUR] = sVenusaurLevelUpLearnset,
    [SPECIES_MEGA_CHARIZARD_X] = sCharizardLevelUpLearnset,
    [SPECIES_MEGA_CHARIZARD_Y] = sCharizardLevelUpLearnset,
    [SPECIES_MEGA_BLASTOISE] = sBlastoiseLevelUpLearnset,
    [SPECIES_MEGA_BEEDRILL] = sBeedrillLevelUpLearnset,
    [SPECIES_MEGA_PIDGEOT] = sPidgeotLevelUpLearnset,
    [SPECIES_MEGA_ALAKAZAM] = sAlakazamLevelUpLearnset,
    [SPECIES_MEGA_SLOWBRO] = sSlowbroLevelUpLearnset,
    [SPECIES_MEGA_GENGAR] = sGengarLevelUpLearnset,
    [SPECIES_MEGA_KANGASKHAN] = sKangaskhanLevelUpLearnset,
    [SPECIES_MEGA_PINSIR] = sPinsirLevelUpLearnset,
    [SPECIES_MEGA_GYARADOS] = sGyaradosLevelUpLearnset,
    [SPECIES_MEGA_AERODACTYL] = sAerodactylLevelUpLearnset,
    [SPECIES_MEGA_MEWTWO_X] = sMewtwoLevelUpLearnset,
    [SPECIES_MEGA_MEWTWO_Y] = sMewtwoLevelUpLearnset,
    [SPECIES_MEGA_AMPHAROS] = sAmpharosLevelUpLearnset,
    [SPECIES_MEGA_STEELIX] = sSteelixLevelUpLearnset,
    [SPECIES_MEGA_SCIZOR] = sScizorLevelUpLearnset,
    [SPECIES_MEGA_HERACROSS] = sHeracrossLevelUpLearnset,
    [SPECIES_MEGA_HOUNDOOM] = sHoundoomLevelUpLearnset,
    [SPECIES_MEGA_TYRANITAR] = sTyranitarLevelUpLearnset,
    [SPECIES_MEGA_SCEPTILE] = sSceptileLevelUpLearnset,
    [SPECIES_MEGA_BLAZIKEN] = sBlazikenLevelUpLearnset,
    [SPECIES_MEGA_SWAMPERT] = sSwampertLevelUpLearnset,
    [SPECIES_MEGA_GARDEVOIR] = sGardevoirLevelUpLearnset,
    [SPECIES_MEGA_SABLEYE] = sSableyeLevelUpLearnset,
    [SPECIES_MEGA_MAWILE] = sMawileLevelUpLearnset,
    [SPECIES_MEGA_AGGRON] = sAggronLevelUpLearnset,
    [SPECIES_MEGA_MEDICHAM] = sMedichamLevelUpLearnset,
    [SPECIES_MEGA_MANECTRIC] = sManectricLevelUpLearnset,
    [SPECIES_MEGA_SHARPEDO] = sSharpedoLevelUpLearnset,
    [SPECIES_MEGA_CAMERUPT] = sCameruptLevelUpLearnset,
    [SPECIES_MEGA_ALTARIA] = sAltariaLevelUpLearnset,
    [SPECIES_MEGA_BANETTE] = sBanetteLevelUpLearnset,
    [SPECIES_MEGA_ABSOL] = sAbsolLevelUpLearnset,
    [SPECIES_MEGA_GLALIE] = sGlalieLevelUpLearnset,
    [SPECIES_MEGA_SALAMENCE] = sSalamenceLevelUpLearnset,
    [SPECIES_MEGA_METAGROSS] = sMetagrossLevelUpLearnset,
    [SPECIES_MEGA_LATIAS] = sLatiasLevelUpLearnset,
    [SPECIES_MEGA_LATIOS] = sLatiosLevelUpLearnset,
    [SPECIES_PRIMAL_KYOGRE] = sKyogreLevelUpLearnset,
    [SPECIES_PRIMAL_GROUDON] = sGroudonLevelUpLearnset,
    [SPECIES_MEGA_RAYQUAZA] = sRayquazaLevelUpLearnset,
    [SPECIES_MEGA_LOPUNNY] = sLopunnyLevelUpLearnset,
    [SPECIES_MEGA_GARCHOMP] = sGarchompLevelUpLearnset,
    [SPECIES_MEGA_LUCARIO] = sLucarioLevelUpLearnset,
    [SPECIES_MEGA_ABOMASNOW] = sAbomasnowLevelUpLearnset,
    [SPECIES_MEGA_GALLADE] = sGalladeLevelUpLearnset,
    [SPECIES_MEGA_AUDINO] = sAudinoLevelUpLearnset,
    [SPECIES_MEGA_DIANCIE] = sDiancieLevelUpLearnset,
	// Alolan Forms
    [SPECIES_ALOLAN_RATTATA] = sAlolanRattataLevelUpLearnset,
    [SPECIES_ALOLAN_RATICATE] = sAlolanRaticateLevelUpLearnset,
    [SPECIES_ALOLAN_RAICHU] = sAlolanRaichuLevelUpLearnset,
    [SPECIES_ALOLAN_SANDSHREW] = sAlolanSandshrewLevelUpLearnset,
    [SPECIES_ALOLAN_SANDSLASH] = sAlolanSandslashLevelUpLearnset,
    [SPECIES_ALOLAN_VULPIX] = sAlolanVulpixLevelUpLearnset,
    [SPECIES_ALOLAN_NINETALES] = sAlolanNinetalesLevelUpLearnset,
    [SPECIES_ALOLAN_DIGLETT] = sAlolanDiglettLevelUpLearnset,
    [SPECIES_ALOLAN_DUGTRIO] = sAlolanDugtrioLevelUpLearnset,
    [SPECIES_ALOLAN_MEOWTH] = sAlolanMeowthLevelUpLearnset,
    [SPECIES_ALOLAN_PERSIAN] = sAlolanPersianLevelUpLearnset,
    [SPECIES_ALOLAN_GEODUDE] = sAlolanGeodudeLevelUpLearnset,
    [SPECIES_ALOLAN_GRAVELER] = sAlolanGravelerLevelUpLearnset,
    [SPECIES_ALOLAN_GOLEM] = sAlolanGolemLevelUpLearnset,
    [SPECIES_ALOLAN_GRIMER] = sAlolanGrimerLevelUpLearnset,
    [SPECIES_ALOLAN_MUK] = sAlolanMukLevelUpLearnset,
    [SPECIES_ALOLAN_EXEGGUTOR] = sAlolanExeggutorLevelUpLearnset,
    [SPECIES_ALOLAN_MAROWAK] = sAlolanMarowakLevelUpLearnset,
    // Forms
    [SPECIES_SHAYMIN_SKY] = sShayminLevelUpLearnset,
    [SPECIES_GIRATINA_ORIGIN] = sGiratinaLevelUpLearnset,
};
