AntiquityCity_DeveloperHouse_MapScripts::
	.byte 0

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
	end

AntiquityCity_DeveloperHouse_EventScript_Abzol::
	trainerbattle_single TRAINER_ABZOL, AntiquityCity_DeveloperHouse_Text_AbzolIntro, AntiquityCity_DeveloperHouse_Text_AbzolDefeat,
	msgbox AntiquityCity_DeveloperHouse_Text_AbzolPostBattle, MSGBOX_DEFAULT
	end

AntiquityCity_DeveloperHouse_EventScript_Sheeno::
	trainerbattle_single TRAINER_SHEENO, AntiquityCity_DeveloperHouse_Text_SheenoIntro, AntiquityCity_DeveloperHouse_Text_SheenoDefeat,
	msgbox AntiquityCity_DeveloperHouse_Text_SheenoPostBattle, MSGBOX_DEFAULT
	end

AntiquityCity_DeveloperHouse_Text_JahIntro:
	.string "Jah: Either you accept death or your\n"
	.string "Pokémon will die in your place.$"
	
AntiquityCity_DeveloperHouse_Text_JahPostBattle:
	.string "Jah: Next time accept your faith\n"
	.string "and don't run from it like you\l"
	.string "did this time you lucky bastard.$"

AntiquityCity_DeveloperHouse_Text_JahDefeat:
	.string "Jah: I'm going to assume you chose\n"
	.string "death instead of sacrificing your Pokémon...$"

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
	