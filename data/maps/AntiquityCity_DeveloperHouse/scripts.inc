AntiquityCity_DeveloperHouse_MapScripts::
	.byte 0

AntiquityCity_DeveloperHouse_EventScript_OnTransition::
	goto_if_set FLAG_BADGE01_GET, AntiquityCity_DeveloperHouse_EventScript_TryAgainLater
	end
	
AntiquityCity_DeveloperHouse_EventScript_OnTransition2::
	goto_if_set FLAG_BADGE04_GET, AntiquityCity_DeveloperHouse_EventScript_GimmeThoseCandies
	end
	
AntiquityCity_DeveloperHouse_EventScript_TryAgainLater::
	lockall
	clearflag FLAG_HIDE_ROUTE_103_RIVAL
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_QuestionMark
	applymovement 7, RareCandyManHeadsToDoor
	waitmovement 0
	msgbox AntiquityCity_DeveloperHouse_Text_RareCandiesLater, MSGBOX_DEFAULT
	closemessage
	applymovement 7, RareCandyManHeadsBackToBlockDoor
	waitmovement 0
	setvar VAR_DEVELOPER_HOUSE, 1
	releaseall
	end

AntiquityCity_DeveloperHouse_EventScript_GimmeThoseCandies::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_QuestionMark
	applymovement 7, RareCandyManHeadsToDoor
	waitmovement 0
	msgbox AntiquityCity_DeveloperHouse_Text_YoullNeedThese, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_RARE_CANDY, 999
	msgbox AntiquityCity_DeveloperHouse_Text_HeresEvenMore, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_RARE_CANDY, 999
	msgbox AntiquityCity_DeveloperHouse_Text_HeresTheLastBit, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_RARE_CANDY, 999
	msgbox AntiquityCity_DeveloperHouse_Text_NowYoullSurvive, MSGBOX_DEFAULT
	closemessage
	applymovement 7, RareCandyManHeadsBackToBlockDoor
	waitmovement 0
	releaseall
	end

AntiquityCity_DeveloperHouse_EventScript_Mart_Employee::
	lockall
	faceplayer
	msgbox AntiquityCity_DeveloperHouse_Text_BlockThisDoor, MSGBOX_DEFAULT
	closemessage
	setvar VAR_DEVELOPER_HOUSE, 2
	goto_if_set FLAG_DEFEATED_LLOYD, AntiquityCity_DeveloperHouse_EventScript_Mart_Employee_Disappears
	releaseall
	end

AntiquityCity_DeveloperHouse_EventScript_Mart_Employee_Disappears::
	msgbox AntiquityCity_DeveloperHouse_Text_OhYouWon, MSGBOX_DEFAULT
	closemessage
	applymovement 7, MartManWalksAway
	applymovement OBJ_EVENT_ID_PLAYER, PlayerWatchesMartManLeave
	waitmovement 0
	applymovement 7, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 7, MartManComesBack
	waitmovement 0
	msgbox AntiquityCity_DeveloperHouse_Text_IForgot, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_MASTER_BALL, 1
	msgbox AntiquityCity_DeveloperHouse_Text_ImGoneFr, MSGBOX_DEFAULT
	closemessage
	applymovement 7, MartManLeaves
	waitmovement 0
	fadescreen 1
	setvar VAR_DEVELOPER_HOUSE, 3
	setflag FLAG_HIDE_ROUTE_103_RIVAL
	fadescreen 0
	releaseall
	end

AntiquityCity_DeveloperHouse_EventScript_JahWontBattle::
	faceplayer
	goto_if_set FLAG_BADGE04_GET, AntiquityCity_DeveloperHouse_EventScript_Jah
	lockall
	msgbox AntiquityCity_DeveloperHouse_Text_JahsGift, MSGBOX_DEFAULT
	closemessage
	givecustommon SPECIES_RIOLU, 5, ITEM_LUCARIONITE, ITEM_LURE_BALL, NATURE_LONELY, 0, 31, 31, 31, 31, 31, 31, 0, 255, 0, 255, 4, 0, MOVE_AURA_SPHERE, MOVE_BONE_RUSH, MOVE_METEOR_MASH, MOVE_EXTREME_SPEED, 0
	playse DP_SEQ_FANFA5
	msgbox AntiquityCity_DeveloperHouse_Text_RecievedRiolu, MSGBOX_AUTOCLOSE
	waitse
	msgbox AntiquityCity_DeveloperHouse_Text_JahMugenWontBattle, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

AntiquityCity_DeveloperHouse_EventScript_MugenWontBattle::
	faceplayer
	goto_if_set FLAG_BADGE04_GET, AntiquityCity_DeveloperHouse_EventScript_Mugen
	lockall
	msgbox AntiquityCity_DeveloperHouse_Text_MugensGift, MSGBOX_DEFAULT
	closemessage
	givecustommon SPECIES_SANDILE, 5, ITEM_FOCUS_SASH, ITEM_LEVEL_BALL, NATURE_LONELY, 1, 31, 31, 31, 31, 31, 31, 0, 255, 0, 4, 255, 0, MOVE_EARTHQUAKE, MOVE_CRUNCH, MOVE_GRASS_KNOT, MOVE_STEALTH_ROCK, 1
	playse DP_SEQ_FANFA5
	msgbox AntiquityCity_DeveloperHouse_Text_RecievedSandile, MSGBOX_AUTOCLOSE
	waitse
	msgbox AntiquityCity_DeveloperHouse_Text_JahMugenWontBattle, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

AntiquityCity_DeveloperHouse_EventScript_LloydsGift::
	faceplayer
	goto_if_set FLAG_BADGE04_GET, AntiquityCity_DeveloperHouse_EventScript_Lloyd
	lockall
	msgbox AntiquityCity_DeveloperHouse_Text_LloydsGift, MSGBOX_DEFAULT
	closemessage
	givecustommon SPECIES_BELLSPROUT, 15, ITEM_LEAF_STONE, ITEM_FRIEND_BALL, NATURE_LONELY, 2, 31, 31, 31, 31, 31, 31, 0, 255, 0, 4, 255, 0, MOVE_TOXIC, MOVE_SEED_BOMB, MOVE_POISON_JAB, MOVE_SWORDS_DANCE, 0
	playse DP_SEQ_FANFA5
	msgbox AntiquityCity_DeveloperHouse_Text_RecievedBellsprout, MSGBOX_AUTOCLOSE
	waitse
	msgbox AntiquityCity_DeveloperHouse_Text_ComeBackAndBattle, MSGBOX_DEFAULT
	closemessage
	applymovement 2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

AntiquityCity_DeveloperHouse_EventScript_GodspeedsGift::
	faceplayer
	goto_if_set FLAG_BADGE04_GET, AntiquityCity_DeveloperHouse_EventScript_Godspeed
	lockall
	msgbox AntiquityCity_DeveloperHouse_Text_GodspeedsGift, MSGBOX_DEFAULT
	closemessage
	givecustommon SPECIES_LEDYBA, 10, ITEM_SILVER_POWDER, ITEM_PARK_BALL, NATURE_ADAMANT, 2, 31, 31, 31, 31, 31, 31, 0, 255, 0, 255, 0, 4, MOVE_DRAIN_PUNCH, MOVE_BUG_BITE, MOVE_AERIAL_ACE, MOVE_THUNDER_PUNCH, 0
	playse DP_SEQ_FANFA5
	msgbox AntiquityCity_DeveloperHouse_Text_RecievedLedyba, MSGBOX_AUTOCLOSE
	waitse
	msgbox AntiquityCity_DeveloperHouse_Text_ComeBackAndBattle, MSGBOX_DEFAULT
	closemessage
	applymovement 2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

AntiquityCity_DeveloperHouse_EventScript_AbzolsGift::
	faceplayer
	goto_if_set FLAG_BADGE04_GET, AntiquityCity_DeveloperHouse_EventScript_Abzol
	lockall
	msgbox AntiquityCity_DeveloperHouse_Text_AbzolsGift, MSGBOX_DEFAULT
	closemessage
	givecustommon SPECIES_VENIPEDE, 10, ITEM_BLACK_SLUDGE, ITEM_CHERISH_BALL, NATURE_ADAMANT, 2, 31, 31, 31, 31, 31, 31, 0, 255, 0, 255, 0, 4, MOVE_TOXIC_SPIKES, MOVE_STEAMROLLER, MOVE_POISON_JAB, MOVE_EARTHQUAKE, 1
	playse DP_SEQ_FANFA5
	msgbox AntiquityCity_DeveloperHouse_Text_RecievedVenipede, MSGBOX_AUTOCLOSE
	waitse
	msgbox AntiquityCity_DeveloperHouse_Text_ComeBackAndBattle, MSGBOX_DEFAULT
	closemessage
	applymovement 2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

AntiquityCity_DeveloperHouse_EventScript_SheenosGift::
	faceplayer
	goto_if_set FLAG_BADGE04_GET, AntiquityCity_DeveloperHouse_EventScript_Sheeno
	lockall
	msgbox AntiquityCity_DeveloperHouse_Text_SheenosGift, MSGBOX_DEFAULT
	closemessage
	givecustommon SPECIES_CUTIEFLY, 10, ITEM_LEFTOVERS, ITEM_REPEAT_BALL, NATURE_MODEST, 2, 31, 31, 31, 31, 31, 31, 255, 0, 0, 4, 255, 0, MOVE_POLLEN_PUFF, MOVE_MOONBLAST, MOVE_AERIAL_ACE, MOVE_QUIVER_DANCE, 1
	playse DP_SEQ_FANFA5
	msgbox AntiquityCity_DeveloperHouse_Text_RecievedCutiefly, MSGBOX_AUTOCLOSE
	waitse
	msgbox AntiquityCity_DeveloperHouse_Text_ComeBackAndBattle, MSGBOX_DEFAULT
	closemessage
	applymovement 2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

AntiquityCity_DeveloperHouse_EventScript_Jah:: @ 81ED38D
	trainerbattle_single TRAINER_JAH, AntiquityCity_DeveloperHouse_Text_JahIntro, AntiquityCity_DeveloperHouse_Text_JahDefeat,
	msgbox AntiquityCity_DeveloperHouse_Text_JahPostBattle, MSGBOX_DEFAULT
	release
	end

AntiquityCity_DeveloperHouse_EventScript_Mugen:: @ 81ED38D
	trainerbattle_single TRAINER_MUGEN, AntiquityCity_DeveloperHouse_Text_MugenIntro, AntiquityCity_DeveloperHouse_Text_MugenDefeat,
	msgbox AntiquityCity_DeveloperHouse_Text_MugenPostBattle, MSGBOX_DEFAULT
	release
	end

AntiquityCity_DeveloperHouse_EventScript_Lloyd::
	trainerbattle_single TRAINER_LLOYD, AntiquityCity_DeveloperHouse_Text_LloydIntro, AntiquityCity_DeveloperHouse_Text_LloydDefeat,
	msgbox AntiquityCity_DeveloperHouse_Text_LloydPostBattle, MSGBOX_DEFAULT
	release
	end

AntiquityCity_DeveloperHouse_EventScript_Godspeed::
	trainerbattle_single TRAINER_GODSPEED, AntiquityCity_DeveloperHouse_Text_GodspeedIntro, AntiquityCity_DeveloperHouse_Text_GodspeedDefeat,
	msgbox AntiquityCity_DeveloperHouse_Text_GodspeedPostBattle, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_LLOYD
	end

AntiquityCity_DeveloperHouse_EventScript_Abzol::
	trainerbattle_single TRAINER_ABZOL, AntiquityCity_DeveloperHouse_Text_AbzolIntro, AntiquityCity_DeveloperHouse_Text_AbzolDefeat,
	msgbox AntiquityCity_DeveloperHouse_Text_AbzolPostBattle, MSGBOX_DEFAULT
	end

AntiquityCity_DeveloperHouse_EventScript_Sheeno::
	trainerbattle_single TRAINER_SHEENO, AntiquityCity_DeveloperHouse_Text_SheenoIntro, AntiquityCity_DeveloperHouse_Text_SheenoDefeat,
	msgbox AntiquityCity_DeveloperHouse_Text_SheenoPostBattle, MSGBOX_DEFAULT
	end

RareCandyManHeadsToDoor:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

RareCandyManHeadsBackToBlockDoor:
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	face_down
	step_end

MartManWalksAway:
	walk_down
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

PlayerWatchesMartManLeave:
	walk_down
	face_left
	delay_8
	face_down
	step_end

MartManComesBack:
	walk_up
	walk_up
	walk_right
	walk_in_place_up
	step_end

MartManLeaves:
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

AntiquityCity_DeveloperHouse_Text_RareCandiesLater:
	.string "Hello there young one!\n"
	.string "Since this is just a beta that stops at\l"
	.string "at the 4th Gym, The developers have a\p"
	.string "gift for you that I will give you to\n"
	.string "battle them only AFTER you beat the 4th\l"
	.string "Gym.\p"
	.string "Since you haven't yet, you will receive\n"
	.string "the gift from me later, however the\l"
	.string "developers will still chat with you\p"
	.string "until you finish the beta.\p"
	.string "...\p"
	.string "Man I hate this annoying ass job.\n"
	.string "They're lucky the pay is good as hell...\p"
	.string "{PLAYER}:Y-You know I heard that right?$"

AntiquityCity_DeveloperHouse_Text_YoullNeedThese:
	.string "Hello there young one!\n"
	.string "Since this is just a beta that stops at\l"
	.string "at the 4th Gym, The developers have a\p"
	.string "gift for you that I will give you to battle\n"
	.string "them.\p"
	.string "Since I'm supposed to give them to you to make\n"
	.string "the battles fair, Here you go...$"
	
AntiquityCity_DeveloperHouse_Text_HeresEvenMore:
	.string "You probably think it's only one, but it's\n"
	.string "actually 999 but that's not it.\l"
	.string "There's even more...$"

AntiquityCity_DeveloperHouse_Text_HeresTheLastBit:
	.string "I'm still not down but this is it...$"

AntiquityCity_DeveloperHouse_Text_NowYoullSurvive:
	.string "Now you should be able to stand a chance\n"
	.string "against the developers.\p"
	.string "I honestly don't care if you do or\n"
	.string "not but I gotta do my job.\p"
	.string "...\p"
	.string "Man I hate this annoying ass job.\n"
	.string "They're lucky the pay is good as hell...\p"
	.string "{PLAYER}:Y-You know I heard that right?$"

AntiquityCity_DeveloperHouse_Text_BlockThisDoor:
	.string "I'm also supposed to block this door\n"
	.string "until you beat a SPECIFIC developer and\l"
	.string "NO, I'm not telling you which one it is.$"

AntiquityCity_DeveloperHouse_Text_OhYouWon:
	.string "{PLAYER}: If it was Godspeed, I already beat\n"
	.string "him so let me through.\p"
	.string "Employee: Oh...\p"
	.string "Y-You actually w-won...\p"
	.string "Um...Well I guess I'll take my\n"
	.string "Um...leave then...$"

AntiquityCity_DeveloperHouse_Text_IForgot:
	.string "I was never expecting anyone to ever\n"
	.string "win against him since he's a competitive\l"
	.string "Pokémon Battler.\p"
	.string "I forgot to give you this Master Ball for\n"
	.string "actually winning.\p"
	.string "...\p"
	.string "Damn it all...\p"
	.string "Now I gotta got back to being a normal ass\n"
	.string "low-salary having ass mart employee...$"

AntiquityCity_DeveloperHouse_Text_ImGoneFr:
	.string "Aight homeslice, my broke ass out this\n"
	.string "hoe forreal.$"

AntiquityCity_DeveloperHouse_Text_RecievedRiolu:
	.string "{PLAYER} Received a Riolu.$"

AntiquityCity_DeveloperHouse_Text_RecievedSandile:
	.string "{PLAYER} Received a Sandile.$"

AntiquityCity_DeveloperHouse_Text_RecievedBellsprout:
	.string "{PLAYER} Received a Bellsprout.$"

AntiquityCity_DeveloperHouse_Text_RecievedLedyba:
	.string "{PLAYER} Received a Ledyba.$"

AntiquityCity_DeveloperHouse_Text_RecievedVenipede:
	.string "{PLAYER} Received a Venipede.$"

AntiquityCity_DeveloperHouse_Text_RecievedCutiefly:
	.string "{PLAYER} Received a Cutiefly.$"

AntiquityCity_DeveloperHouse_Text_JahsGift:
	.string "You're a garbage ass trainer so how about\n"
	.string "this?\p"
	.string "How about I give you this and catch that\n"
	.string "fade after you beat the 4th Gym.$"

AntiquityCity_DeveloperHouse_Text_MugensGift:
	.string "I feel the same as Jah...\n"
	.string "Use this and get stronger.$"

AntiquityCity_DeveloperHouse_Text_JahMugenWontBattle:
	.string "I won't battle you until you at\n"
	.string "least train up and beat the 4th Gym.\p"
	.string "...\p"
	.string "DON'T JUST LOOK AT ME LIKE YOU DIDN'T\n"
	.string "FUCKING HEAR ME GET THE FUCK OUT OF\l"
	.string "HERE!$"

AntiquityCity_DeveloperHouse_Text_LloydsGift:
	.string "Oh hey {PLAYER}, how are you enjoying\n"
	.string "the game so far?\p"
	.string "{PLAYER}: I-It's ac-\p"
	.string "Lloyd: No need to answer...\n"
	.string "if you are really enjoying it that's\l"
	.string "great because I worked hard on it.\p"
	.string "However if you're not enjoying it,I\n"
	.string "hope this makes the experience a tad\l"
	.string "bit better for you.$"

AntiquityCity_DeveloperHouse_Text_ComeBackAndBattle:
	.string "Once you get the 4th Gym badge, you\n"
	.string "should come back and battle all of us.$"

AntiquityCity_DeveloperHouse_Text_GodspeedsGift:
	.string "If you're wondering where the story\n"
	.string "events are, they aren't any at the\l" 
	.string "moment because of...\p"
	.string "reasons unknown...\p"
	.string "To compensate for it, I'm giving you\n"
	.string "this ultra, amazing, super strong, one\l"
	.string "of a kind, extraordinary...\p"
	.string "...\p"
	.string "{PLAYER}: Well, What is it?\p"
	.string "Godspeed: ...\p"
	.string "It's\p"
	.string "A\p"
	.string "...\p"
	.string "{PLAYER}: My guy hurry the fuck up!\p"
	.string "Godspeed: ...\p"
	.string "LEEEDDDDYYYBBAAAAA!!!\p"
	.string "...\p"
	.string "{PLAYER}: R-Really!?\p"
	.string "You wasted ALL my goddamn time to give\n"
	.string "me a fucking Ledyba!?\p"
	.string "Godspeed:...\p"
	.string "Yes...Yes I did:)$"

AntiquityCity_DeveloperHouse_Text_AbzolsGift:
	.string "Sheeno and I helped make this game\n"
	.string "challenging by make EVERY SINGLE team\l"
	.string "you face off against.\p"
	.string "I wish there was a way I could do more\n"
	.string "to make your experience better...\p"
	.string "...\p"
	.string "Oh...\p"
	.string "Here have this.$"

AntiquityCity_DeveloperHouse_Text_SheenosGift:
	.string "Sheeno and I helped make this game\n"
	.string "challenging by make EVERY SINGLE team\l"
	.string "you face off against.\p"
	.string "The only way I can make your experience\n"
	.string "better is by giving you this.$"

AntiquityCity_DeveloperHouse_Text_JahIntro:
	.string "Jah: Either you accept death or your\n"
	.string "Pokémon will die in your place.$"
	
AntiquityCity_DeveloperHouse_Text_JahPostBattle:
	.string "Jah: Next time accept your faith\n"
	.string "and don't run from it like you\l"
	.string "did this time you lucky bastard.$"

AntiquityCity_DeveloperHouse_Text_JahDefeat:
	.string "Jah: I'm going to assume you chose\n"
	.string "death instead of sacrificing yourself...$"

AntiquityCity_DeveloperHouse_Text_AbzolIntro:
	.string "Abzol: Let's go!$"

AntiquityCity_DeveloperHouse_Text_AbzolDefeat:
	.string "Abzol: I lost.$"

AntiquityCity_DeveloperHouse_Text_AbzolPostBattle:
	.string "Abzol: I'm going to get stronger.$"

AntiquityCity_DeveloperHouse_Text_MugenIntro:
	.string "Mugen: SHADOW CLONE JUTSU!!$"

AntiquityCity_DeveloperHouse_Text_MugenDefeat:
	.string "Mugen: Gotta improve my swordmanship.$"

AntiquityCity_DeveloperHouse_Text_MugenPostBattle:
	.string "Mugen: Keep Talking and I'll slice you\n"
	.string "right here right now.$"
	
AntiquityCity_DeveloperHouse_Text_LloydIntro:
	.string "Lloyd: So you decided to come and\n"
	.string "fight us {PLAYER}{KUN}.\p"
	.string "Get ready for the fight of your\n"
	.string "life!!$"

AntiquityCity_DeveloperHouse_Text_LloydPostBattle:
	.string "Lloyd: Have fun with the rest of the\n"
	.string "fights or whatever your gonna do\n"
	.string "if you already beat them as well.$"

AntiquityCity_DeveloperHouse_Text_LloydDefeat:
	.string "Lloyd: Oh wow you actually beat\n"
	.string "me. You might win or probably already\n"
	.string "won against the others as well.$"

AntiquityCity_DeveloperHouse_Text_GodspeedIntro:
	.string "Godspeed: Yea, What's up?\n"
	.string "I made you myself kid, I am your creator.\p"
	.string "Y'know I'm good at art but battling\n"
	.string "ain't hard either.\p"
	.string "HAVE FUN LOSING YOU UNDERCOOKED\n"
	.string "JOJO CHARACTER!$"

AntiquityCity_DeveloperHouse_Text_GodspeedDefeat:
	.string "Godspeed: Woooowwwww, you ACTUALLY won?!\p"
	.string "That's actually pretty POG mate.$"

AntiquityCity_DeveloperHouse_Text_GodspeedPostBattle:
	.string "Godspeed: Last night there was a lot of noise\n"
	.string "near our truck.\p"
	.string "Why do we have a truck? I don't know...$"

AntiquityCity_DeveloperHouse_Text_SheenoIntro:
	.string "Sheeno: I didn't climb all the way to\n"
	.string "the top only to let a kid beat me.$"

AntiquityCity_DeveloperHouse_Text_SheenoDefeat:
	.string "Sheeno: Damn I must've gotten whiplash.$"

AntiquityCity_DeveloperHouse_Text_SheenoPostBattle:
	.string "Sheeno: Well you sure as hell ran from\n"
	.string "death I'll give you that.$"
