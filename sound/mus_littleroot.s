	.include "MPlayDef.s"

	.equ	mus_littleroot_grp, voicegroup051
	.equ	mus_littleroot_pri, 0
	.equ	mus_littleroot_rev, reverb_set+50
	.equ	mus_littleroot_mvl, 100
	.equ	mus_littleroot_key, 0
	.equ	mus_littleroot_tbs, 1
	.equ	mus_littleroot_exg, 1
	.equ	mus_littleroot_cmp, 1

	.section .rodata
	.global	mus_littleroot
	.align	2

@**************** Track 1 (Midi-Chn.1) ****************@

mus_littleroot_1:
	.byte	KEYSH , mus_littleroot_key+0
@ 000   ----------------------------------------
	.byte	TEMPO , 87*mus_littleroot_tbs/2
	.byte		VOICE , 73
	.byte		VOL   , 104*mus_littleroot_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		MOD   , 5
	.byte	W96
@ 001   ----------------------------------------
	.byte	W96
@ 002   ----------------------------------------
	.byte	W92
	.byte	W03
mus_littleroot_1_B1:
	.byte	W01
@ 003   ----------------------------------------
	.byte		BEND  , c_v-6
	.byte		        c_v-4
	.byte		N56   , An4 , v120
	.byte	W03
	.byte		BEND  , c_v-3
	.byte	W02
	.byte		        c_v-2
	.byte	W04
	.byte		        c_v+0
	.byte	W36
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W02
	.byte	W01
	.byte		N02   , Gn4 , v088
	.byte	W02
	.byte	W01
	.byte		N11   , Fs4 , v116
	.byte	W11
	.byte	W01
	.byte		N44   , Gn4 , v120, gtp3
	.byte	W24
@ 004   ----------------------------------------
	.byte	W12
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W02
	.byte	W01
	.byte		N11   , Fs4 , v116
	.byte	W11
	.byte	W01
	.byte		        En4 , v112
	.byte	W11
	.byte	W01
	.byte		N56   , Dn4 , v116, gtp3
	.byte	W44
	.byte	W01
	.byte	W03
@ 005   ----------------------------------------
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W02
	.byte	W01
	.byte		N11   , Fs4 
	.byte	W11
	.byte	W01
	.byte		N32   , En4 , v116, gtp3
	.byte	W24
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W02
	.byte	W01
	.byte		        Dn4 , v116, gtp3
	.byte	W24
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W02
	.byte	W01
@ 006   ----------------------------------------
	.byte		BEND  , c_v-6
	.byte		N44   , An4 , v116, gtp3
	.byte	W02
	.byte		BEND  , c_v-3
	.byte	W03
	.byte		        c_v+0
	.byte	W30
	.byte	W01
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W02
	.byte	W01
	.byte		N11   , Gn4 , v112
	.byte	W11
	.byte	W01
	.byte		        Fs4 
	.byte	W11
	.byte	W01
	.byte		N44   , Gn4 , v116, gtp3
	.byte	W24
@ 007   ----------------------------------------
	.byte	W23
	.byte	W01
	.byte		N11   , Fs4 , v112
	.byte	W11
	.byte	W01
	.byte		N10   , En4 , v108
	.byte	W10
	.byte	W02
	.byte		N68   , Dn4 , v116, gtp3
	.byte	W48
@ 008   ----------------------------------------
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	W05
	.byte	W01
	.byte	W06
	.byte	W66
@ 009   ----------------------------------------
	.byte		BEND  , c_v-6
	.byte		        c_v-6
	.byte		N56   , Bn4 , v120, gtp3
	.byte	W03
	.byte		BEND  , c_v-4
	.byte	W02
	.byte		        c_v-2
	.byte	W04
	.byte		        c_v+0
	.byte	W36
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W02
	.byte	W01
	.byte		N11   , Dn5 , v116
	.byte	W11
	.byte	W01
	.byte		N32   , Cs5 , v120, gtp3
	.byte	W23
	.byte	W01
@ 010   ----------------------------------------
	.byte	W02
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W01
	.byte		        Bn4 , v116, gtp3
	.byte	W24
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W02
	.byte	W01
	.byte		N56   , An4 , v120, gtp3
	.byte	W48
@ 011   ----------------------------------------
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W02
	.byte	W01
	.byte		N03   , Fs4 , v112
	.byte	W03
	.byte	W01
	.byte		        An4 , v108
	.byte	W03
	.byte	W01
	.byte		        Fs4 , v112
	.byte	W03
	.byte	W01
	.byte		N44   , Dn4 , v116, gtp1
	.byte	W30
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte		N11   , En4 
	.byte	W11
	.byte	W01
	.byte		        Fs4 , v112
	.byte	W11
	.byte	W01
@ 012   ----------------------------------------
	.byte		N44   , Gn4 , v116, gtp2
	.byte	W32
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W02
	.byte	W01
	.byte	W01
	.byte		N10   , Fs4 , v112
	.byte	W10
	.byte	W02
	.byte		        En4 
	.byte	W10
	.byte	W02
	.byte		N32   , Dn4 , v116, gtp2
	.byte	W24
@ 013   ----------------------------------------
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W01
	.byte	W02
	.byte		        Cs4 , v112, gtp2
	.byte	W24
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W01
	.byte	W02
	.byte		N68   , Dn4 , v116, gtp3
	.byte	W44
	.byte	W03
	.byte	W01
@ 014   ----------------------------------------
	.byte	W05
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	W66
	.byte	W01
@ 015   ----------------------------------------
	.byte	W96
@ 016   ----------------------------------------
	.byte	W96
@ 017   ----------------------------------------
	.byte	W92
	.byte	W03
	.byte	GOTO
	 .word	mus_littleroot_1_B1
mus_littleroot_1_B2:
	.byte	FINE

@**************** Track 2 (Midi-Chn.2) ****************@

mus_littleroot_2:
	.byte	KEYSH , mus_littleroot_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 48
	.byte		VOL   , 68*mus_littleroot_mvl/mxv
	.byte		PAN   , c_v-34
	.byte		MOD   , 0
	.byte	W96
@ 001   ----------------------------------------
	.byte	W96
@ 002   ----------------------------------------
	.byte	W92
	.byte	W03
mus_littleroot_2_B1:
	.byte	W01
@ 003   ----------------------------------------
	.byte	W96
@ 004   ----------------------------------------
	.byte	W96
@ 005   ----------------------------------------
	.byte	W96
@ 006   ----------------------------------------
	.byte	W96
@ 007   ----------------------------------------
	.byte	W96
@ 008   ----------------------------------------
	.byte	W96
@ 009   ----------------------------------------
	.byte		BEND  , c_v-4
	.byte		N68   , Bn2 , v084, gtp2
	.byte		N68   , Dn3 , v092, gtp2
	.byte	W06
	.byte		BEND  , c_v-2
	.byte	W06
	.byte		        c_v+0
	.byte	W06
	.byte	W30
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	W04
	.byte	W02
	.byte		N68   , Cs3 , v080, gtp2
	.byte		N68   , En3 , v088, gtp2
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	W06
@ 010   ----------------------------------------
	.byte	W24
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	W04
	.byte	W02
	.byte		        An2 , v084, gtp2
	.byte		N68   , Dn3 , v092, gtp2
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	W30
@ 011   ----------------------------------------
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	W04
	.byte	W02
	.byte		        An2 , v080, gtp2
	.byte		N32   , En3 , v088, gtp2
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	W16
	.byte	W02
	.byte		        Fs3 , v088, gtp2
	.byte	W32
	.byte	W02
	.byte	W02
@ 012   ----------------------------------------
	.byte		BEND  , c_v-4
	.byte		N44   , Bn2 , v084, gtp2
	.byte		N44   , En3 , v092, gtp2
	.byte	W06
	.byte		BEND  , c_v-2
	.byte	W06
	.byte		        c_v+0
	.byte	W12
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	W04
	.byte	W02
	.byte		N22   , Bn2 , v080
	.byte		N10   , Dn3 , v088
	.byte	W10
	.byte	W02
	.byte		        En3 , v084
	.byte	W10
	.byte	W02
	.byte		N32   , Dn3 , v080, gtp2
	.byte		N32   , Fs3 , v088, gtp2
	.byte	W24
@ 013   ----------------------------------------
	.byte	W10
	.byte	W02
	.byte		        An2 , v080, gtp2
	.byte		N32   , En3 , v088, gtp2
	.byte	W32
	.byte	W02
	.byte	W02
	.byte		BEND  , c_v+0
	.byte		TIE   , An2 , v068
	.byte		TIE   , Dn3 , v076
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	W30
@ 014   ----------------------------------------
	.byte	W24
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	W01
	.byte		EOT   , An2 
	.byte		        Dn3 
	.byte	W05
	.byte	W30
@ 015   ----------------------------------------
	.byte	W96
@ 016   ----------------------------------------
	.byte	W96
@ 017   ----------------------------------------
	.byte	W92
	.byte	W03
	.byte	GOTO
	 .word	mus_littleroot_2_B1
mus_littleroot_2_B2:
	.byte	FINE

@**************** Track 3 (Midi-Chn.3) ****************@

mus_littleroot_3:
	.byte	KEYSH , mus_littleroot_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 35
	.byte		VOL   , 115*mus_littleroot_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		MOD   , 0
	.byte		BEND  , c_v-6
	.byte		N52   , Dn1 , v112, gtp1
	.byte	W01
	.byte		BEND  , c_v-4
	.byte	W02
	.byte		        c_v+0
	.byte	W48
	.byte	W02
	.byte	W07
	.byte		N11   , Dn1 , v096
	.byte	W11
	.byte	W01
	.byte		N32   , Gn1 , v112, gtp3
	.byte	W24
@ 001   ----------------------------------------
	.byte	W11
	.byte	W01
	.byte		BEND  , c_v-6
	.byte		N32   , An1 , v108, gtp3
	.byte	W01
	.byte		BEND  , c_v-4
	.byte	W02
	.byte		        c_v+0
	.byte	W24
	.byte	W03
	.byte		        c_v-6
	.byte	W01
	.byte		        c_v-11
	.byte	W02
	.byte		        c_v-16
	.byte	W01
	.byte		        c_v-22
	.byte	W01
	.byte	W01
	.byte		        c_v+0
	.byte		N52   , Dn1 , v112, gtp1
	.byte	W48
@ 002   ----------------------------------------
	.byte	W05
	.byte	W07
	.byte		N11   , Dn1 , v108
	.byte	W11
	.byte	W01
	.byte		N32   , Gn1 , v116, gtp3
	.byte	W32
	.byte	W03
	.byte	W01
	.byte		        An1 , v108, gtp3
	.byte	W30
	.byte		BEND  , c_v-6
	.byte	W01
	.byte		        c_v-11
	.byte	W02
	.byte		        c_v-16
	.byte	W01
	.byte		        c_v-22
	.byte	W01
mus_littleroot_3_B1:
	.byte	W01
@ 003   ----------------------------------------
	.byte		BEND  , c_v+0
	.byte		N48   , Dn1 , v112, gtp2
	.byte	W48
	.byte	W02
	.byte	W10
	.byte		N11   , Dn1 , v104
	.byte	W11
	.byte	W01
	.byte		BEND  , c_v-6
	.byte		N32   , Gn1 , v112, gtp3
	.byte	W01
	.byte		BEND  , c_v-4
	.byte	W02
	.byte		        c_v+0
	.byte	W21
@ 004   ----------------------------------------
	.byte	W11
	.byte	W01
	.byte		N24   , An1 
	.byte	W24
	.byte		N11   , An0 
	.byte	W11
	.byte	W01
	.byte		BEND  , c_v-6
	.byte		N48   , Dn1 , v116, gtp3
	.byte	W01
	.byte		BEND  , c_v-4
	.byte	W02
	.byte		        c_v+0
	.byte	W44
	.byte	W01
@ 005   ----------------------------------------
	.byte	W03
	.byte	W09
	.byte		N11   , Dn1 , v108
	.byte	W11
	.byte	W01
	.byte		BEND  , c_v-6
	.byte		N32   , Gn1 , v116, gtp3
	.byte	W01
	.byte		BEND  , c_v-4
	.byte	W02
	.byte		        c_v+0
	.byte	W32
	.byte	W01
	.byte		N32   , An1 , v116, gtp3
	.byte	W30
	.byte		BEND  , c_v-6
	.byte	W01
	.byte		        c_v-11
	.byte	W02
	.byte		        c_v-16
	.byte	W01
	.byte		        c_v-22
	.byte	W01
	.byte	W01
@ 006   ----------------------------------------
	.byte		        c_v+0
	.byte		N52   , Dn1 , v116, gtp1
	.byte	W52
	.byte	W01
	.byte	W07
	.byte		N11   , Dn1 , v112
	.byte	W11
	.byte	W01
	.byte		N32   , Cs1 , v116, gtp3
	.byte	W24
@ 007   ----------------------------------------
	.byte	W11
	.byte	W01
	.byte		BEND  , c_v-6
	.byte		N23   , Fs1 , v112
	.byte	W01
	.byte		BEND  , c_v-4
	.byte	W02
	.byte		        c_v+0
	.byte	W20
	.byte	W01
	.byte		N11   , Fs0 , v108
	.byte	W11
	.byte	W01
	.byte		BEND  , c_v-6
	.byte		N44   , Bn0 , v116, gtp3
	.byte	W01
	.byte		BEND  , c_v-4
	.byte	W02
	.byte		        c_v+0
	.byte	W44
	.byte	W01
@ 008   ----------------------------------------
	.byte		N11   , Fs0 , v112
	.byte	W11
	.byte	W01
	.byte		        Bn0 
	.byte	W11
	.byte	W01
	.byte		N32   , An0 , v116, gtp1
	.byte	W32
	.byte	W01
	.byte	W03
	.byte		N11   , An1 
	.byte	W11
	.byte	W01
	.byte		N09   , Fs1 , v112
	.byte	W09
	.byte	W03
	.byte		N10   , Dn1 
	.byte	W10
	.byte	W02
@ 009   ----------------------------------------
	.byte		BEND  , c_v-6
	.byte		N56   , Gn1 , v116, gtp1
	.byte	W01
	.byte		BEND  , c_v-4
	.byte	W02
	.byte		        c_v+0
	.byte	W54
	.byte	W03
	.byte		N05   , Gn1 , v096
	.byte	W05
	.byte	W07
	.byte		BEND  , c_v-6
	.byte		N44   , Gn1 , v112, gtp3
	.byte	W01
	.byte		BEND  , c_v-4
	.byte	W02
	.byte		        c_v+0
	.byte	W21
@ 010   ----------------------------------------
	.byte	W23
	.byte	W01
	.byte		        c_v-6
	.byte		N23   , Cs2 , v108
	.byte	W01
	.byte		BEND  , c_v-4
	.byte	W02
	.byte		        c_v+0
	.byte	W09
	.byte		        c_v-11
	.byte	W11
	.byte	W01
	.byte		        c_v-6
	.byte		N44   , Fs1 , v116, gtp3
	.byte	W01
	.byte		BEND  , c_v-4
	.byte	W02
	.byte		        c_v+0
	.byte	W44
	.byte	W01
@ 011   ----------------------------------------
	.byte		        c_v-6
	.byte		N05   , An1 , v108
	.byte	W01
	.byte		BEND  , c_v-4
	.byte	W02
	.byte		        c_v+0
	.byte	W02
	.byte	W07
	.byte		        c_v-6
	.byte		N04   , Cs2 , v100
	.byte	W01
	.byte		BEND  , c_v-4
	.byte	W02
	.byte		        c_v+0
	.byte	W01
	.byte	W08
	.byte		        c_v-6
	.byte		N44   , Bn1 , v124, gtp3
	.byte	W01
	.byte		BEND  , c_v-4
	.byte	W02
	.byte		        c_v+0
	.byte	W44
	.byte	W01
	.byte		N11   , Fs1 , v116
	.byte	W11
	.byte	W01
	.byte		        Bn0 , v112
	.byte	W11
	.byte	W01
@ 012   ----------------------------------------
	.byte		BEND  , c_v-6
	.byte		N32   , En1 , v120, gtp1
	.byte	W01
	.byte		BEND  , c_v-4
	.byte	W02
	.byte		        c_v+0
	.byte	W30
	.byte	W03
	.byte		N09   
	.byte	W09
	.byte	W03
	.byte		N10   , Fs1 , v116
	.byte	W10
	.byte	W02
	.byte		        Gn1 , v120
	.byte	W10
	.byte	W02
	.byte		BEND  , c_v-6
	.byte		N32   , An1 , v120, gtp3
	.byte	W01
	.byte		BEND  , c_v-4
	.byte	W02
	.byte		        c_v+0
	.byte	W21
@ 013   ----------------------------------------
	.byte	W07
	.byte		        c_v-11
	.byte	W02
	.byte		        c_v-16
	.byte	W01
	.byte		        c_v-22
	.byte	W01
	.byte	W01
	.byte		        c_v+0
	.byte		N32   , An0 , v116, gtp3
	.byte	W32
	.byte	W03
	.byte	W01
	.byte		BEND  , c_v-6
	.byte		N68   , Dn1 , v112
	.byte	W01
	.byte		BEND  , c_v-4
	.byte	W02
	.byte		        c_v+0
	.byte	W44
	.byte	W01
@ 014   ----------------------------------------
	.byte	W20
	.byte	W04
	.byte		N32   , Dn1 , v112, gtp3
	.byte	W03
	.byte		BEND  , c_v+0
	.byte	W32
	.byte	W01
	.byte		        c_v-16
	.byte		N32   , An1 , v112, gtp3
	.byte	W01
	.byte		BEND  , c_v-11
	.byte	W02
	.byte		        c_v-6
	.byte		        c_v-6
	.byte	W01
	.byte		        c_v+0
	.byte	W24
	.byte	W02
	.byte		        c_v-6
	.byte	W01
	.byte		        c_v-11
	.byte	W02
	.byte		        c_v-16
	.byte	W01
	.byte		        c_v-22
	.byte	W01
	.byte	W01
@ 015   ----------------------------------------
	.byte		        c_v+0
	.byte		        c_v-6
	.byte		N52   , Dn1 , v112, gtp1
	.byte	W01
	.byte		BEND  , c_v-4
	.byte	W02
	.byte		        c_v+0
	.byte	W48
	.byte	W02
	.byte	W07
	.byte		N11   , Dn1 , v096
	.byte	W11
	.byte	W01
	.byte		N32   , Gn1 , v112, gtp3
	.byte	W24
@ 016   ----------------------------------------
	.byte	W11
	.byte	W01
	.byte		BEND  , c_v-6
	.byte		N32   , An1 , v108, gtp3
	.byte	W01
	.byte		BEND  , c_v-4
	.byte	W02
	.byte		        c_v+0
	.byte	W24
	.byte	W03
	.byte		        c_v-6
	.byte	W01
	.byte		        c_v-11
	.byte	W02
	.byte		        c_v-16
	.byte	W01
	.byte		        c_v-22
	.byte	W01
	.byte	W01
	.byte		        c_v+0
	.byte		N52   , Dn1 , v112, gtp1
	.byte	W48
@ 017   ----------------------------------------
	.byte	W05
	.byte	W07
	.byte		N11   , Dn1 , v108
	.byte	W11
	.byte	W01
	.byte		N32   , Gn1 , v116, gtp3
	.byte	W30
	.byte		BEND  , c_v-6
	.byte	W01
	.byte		        c_v-11
	.byte	W02
	.byte		        c_v-16
	.byte	W01
	.byte		        c_v-22
	.byte	W01
	.byte		        c_v+0
	.byte	W01
	.byte		N32   , Cn1 , v108, gtp3
	.byte	W30
	.byte		BEND  , c_v-6
	.byte	W01
	.byte		        c_v-11
	.byte	W02
	.byte		        c_v-16
	.byte	W01
	.byte		        c_v-22
	.byte	W01
	.byte	GOTO
	 .word	mus_littleroot_3_B1
mus_littleroot_3_B2:
	.byte		BEND  , c_v+0
	.byte	FINE

@**************** Track 4 (Midi-Chn.4) ****************@

mus_littleroot_4:
	.byte	KEYSH , mus_littleroot_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 4
	.byte		VOL   , 95*mus_littleroot_mvl/mxv
	.byte		PAN   , c_v-44
	.byte		MOD   , 0
	.byte		N01   , Dn3 , v084
	.byte	W01
	.byte		        En3 , v080
	.byte	W01
	.byte	W01
	.byte		N66   , Fs3 , v092, gtp1
	.byte	W48
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W01
	.byte		N01   , En3 , v088
	.byte	W01
	.byte	W01
	.byte		        Fs3 
	.byte	W01
	.byte		N32   , Gn3 , v096
	.byte	W23
@ 001   ----------------------------------------
	.byte	W09
	.byte	W01
	.byte		N02   , Gs3 , v092
	.byte	W02
	.byte	W01
	.byte		N28   , An3 , v096
	.byte	W28
	.byte	W01
	.byte		N02   , Gs3 , v088
	.byte	W02
	.byte	W01
	.byte		        Gn3 
	.byte	W02
	.byte	W01
	.byte		N68   , Fs3 , v092
	.byte	W48
@ 002   ----------------------------------------
mus_littleroot_4_002:
	.byte	W06
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W02
	.byte	PEND
	.byte	W01
	.byte	W01
	.byte		N01   , Ds3 , v092
	.byte	W01
	.byte	W01
	.byte		N32   , En3 , v092, gtp3
	.byte	W21
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W02
	.byte	W01
	.byte		        Dn3 , v088
	.byte	W21
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W02
	.byte	W01
	.byte		N01   
	.byte	W01
	.byte		        En3 
	.byte	W01
mus_littleroot_4_B1:
	.byte	W01
@ 003   ----------------------------------------
	.byte		N64   , Fs3 , v088, gtp1
	.byte	W64
	.byte	W01
	.byte	W03
	.byte		N03   , Ds3 , v080
	.byte	W03
	.byte	W01
	.byte		N44   , En3 , v092, gtp3
	.byte	W24
@ 004   ----------------------------------------
	.byte	W23
	.byte	W01
	.byte		N11   , Dn3 , v084
	.byte	W11
	.byte	W01
	.byte		        En3 , v080
	.byte	W11
	.byte	W01
	.byte		N54   , Fs3 , v088, gtp1
	.byte	W48
@ 005   ----------------------------------------
	.byte	W07
	.byte		N01   , Gn3 
	.byte	W01
	.byte	W01
	.byte		        Gs3 , v084
	.byte	W01
	.byte		N13   , An3 , v088
	.byte	W13
	.byte	W01
	.byte		N32   , Gn3 , v092
	.byte	W32
	.byte	W01
	.byte		N02   , Gs3 , v088
	.byte	W02
	.byte	W01
	.byte		N28   , An3 , v092, gtp1
	.byte	W21
	.byte	W03
	.byte	W03
	.byte	W02
	.byte	W01
	.byte		N02   , Gs3 , v088
	.byte	W02
	.byte	W01
	.byte		        Gn3 , v084
	.byte	W02
	.byte	W01
@ 006   ----------------------------------------
	.byte		N68   , Fs3 , v088, gtp3
	.byte	W56
	.byte	W01
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W02
	.byte	W01
	.byte		N36   , En3 , v084
	.byte	W24
@ 007   ----------------------------------------
	.byte	W12
	.byte		N20   , Cs3 
	.byte	W20
	.byte	W01
	.byte		N02   , Bn2 , v080
	.byte	W02
	.byte	W01
	.byte		N11   , Cs3 
	.byte	W11
	.byte	W01
	.byte		N68   , Dn3 , v088
	.byte	W48
@ 008   ----------------------------------------
	.byte	PATT
	 .word	mus_littleroot_4_002
	.byte	W01
	.byte		N02   , Ds3 , v084
	.byte	W02
	.byte	W01
	.byte		N32   , En3 , v084, gtp3
	.byte	W32
	.byte	W03
	.byte	W01
	.byte		N24   , Fs3 , v084, gtp2
	.byte	W24
	.byte	W02
	.byte	W01
	.byte		N02   , Dn3 
	.byte	W02
	.byte	W01
	.byte		        En3 , v076
	.byte	W02
	.byte		        Fs3 , v084
	.byte	W03
	.byte	W01
@ 009   ----------------------------------------
	.byte		N66   , Gn3 , v088
	.byte	W66
	.byte	W03
	.byte		N02   , Gn3 , v084
	.byte	W02
	.byte		        Gs3 , v080
	.byte	W03
	.byte		N32   , An3 , v088
	.byte	W22
@ 010   ----------------------------------------
	.byte	W10
	.byte	W01
	.byte		N36   , Gn3 , v096
	.byte	W36
	.byte	W01
	.byte		N68   , Fs3 , v096, gtp3
	.byte	W48
@ 011   ----------------------------------------
	.byte	W09
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W02
	.byte	W01
	.byte		N44   , Dn3 , v088, gtp3
	.byte	W32
	.byte	W01
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W02
	.byte	W01
	.byte		N11   , En3 , v092
	.byte	W11
	.byte	W01
	.byte		        Fs3 , v088
	.byte	W11
	.byte	W01
@ 012   ----------------------------------------
	.byte		N02   , Dn3 , v096
	.byte	W02
	.byte	W01
	.byte		N44   , En3 
	.byte	W30
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W02
	.byte	W01
	.byte		N11   , Fs3 , v092
	.byte	W11
	.byte	W01
	.byte		        Gn3 , v088
	.byte	W11
	.byte	W01
	.byte		N30   , An3 , v088, gtp1
	.byte	W21
	.byte	W03
@ 013   ----------------------------------------
	.byte	W03
	.byte	W03
	.byte	W01
	.byte		N01   , Gs3 , v084
	.byte	W01
	.byte	W01
	.byte		        Gn3 , v076
	.byte	W01
	.byte		        Fs3 , v084
	.byte	W01
	.byte	W01
	.byte		N32   , En3 , v088, gtp3
	.byte	W32
	.byte	W03
	.byte	W01
	.byte		TIE   , Fs3 , v080
	.byte	W48
@ 014   ----------------------------------------
	.byte	W32
	.byte	W01
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W02
	.byte	W03
	.byte	W04
	.byte	W02
	.byte		EOT   
	.byte	W01
	.byte		N32   , En3 , v088
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W17
	.byte	W01
	.byte		N01   , Dn3 
	.byte	W01
	.byte		        En3 
	.byte	W01
	.byte	W01
@ 015   ----------------------------------------
	.byte		N68   , Fs3 , v092
	.byte	W48
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W02
	.byte	W01
	.byte		N01   , Cs3 , v088
	.byte	W01
	.byte		        Dn3 
	.byte	W01
	.byte	W01
	.byte		N32   , En3 , v096
	.byte	W24
@ 016   ----------------------------------------
	.byte	W08
	.byte		N02   , Cs3 , v092
	.byte	W03
	.byte	W01
	.byte		N32   , Dn3 , v096
	.byte	W32
	.byte	W01
	.byte		N02   , En3 , v088
	.byte	W02
	.byte	W01
	.byte		N68   , Fs3 , v092
	.byte	W48
@ 017   ----------------------------------------
	.byte	PATT
	 .word	mus_littleroot_4_002
	.byte	W01
	.byte	W01
	.byte		N01   , Fs3 , v092
	.byte	W01
	.byte	W01
	.byte		N32   , Gn3 , v092, gtp3
	.byte	W21
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W02
	.byte	W01
	.byte		N28   , An3 , v088, gtp1
	.byte	W21
	.byte	W03
	.byte	W03
	.byte	W02
	.byte	W01
	.byte		N02   , Gs3 , v084
	.byte	W02
	.byte	W01
	.byte		        Gn3 , v080
	.byte	W02
	.byte	GOTO
	 .word	mus_littleroot_4_B1
mus_littleroot_4_B2:
	.byte	FINE

@**************** Track 5 (Midi-Chn.5) ****************@

mus_littleroot_5:
	.byte	KEYSH , mus_littleroot_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 1
	.byte		VOL   , 99*mus_littleroot_mvl/mxv
	.byte		PAN   , c_v+21
	.byte		MOD   , 0
	.byte		N44   , Dn2 , v108, gtp3
	.byte	W12
	.byte		N40   , An2 , v104, gtp1
	.byte	W12
	.byte		N32   , Dn3 , v108, gtp3
	.byte	W12
	.byte		        Fs3 , v104
	.byte	W11
	.byte	W06
	.byte	W06
	.byte	W09
	.byte	W04
	.byte		N68   , Dn2 , v104, gtp2
	.byte		N68   , Gn2 , v100
	.byte	W01
	.byte		        As2 
	.byte	W01
	.byte		N28   , En3 , v096, gtp1
	.byte	W22
@ 001   ----------------------------------------
	.byte	W08
	.byte	W04
	.byte		N32   , Dn3 , v100, gtp2
	.byte	W32
	.byte	W01
	.byte	W01
	.byte	W02
	.byte		N56   , Dn2 , v112
	.byte	W12
	.byte		        An2 , v100, gtp3
	.byte	W12
	.byte		N16   , Dn3 , v112
	.byte	W12
	.byte		N11   , En3 , v108
	.byte	W04
	.byte	W07
	.byte	W01
@ 002   ----------------------------------------
	.byte		N23   , Dn3 
	.byte	W08
	.byte	W04
	.byte		N11   , An3 
	.byte	W11
	.byte	W01
	.byte		N32   , Dn2 , v100, gtp2
	.byte		N32   , Gn2 , v100, gtp2
	.byte	W01
	.byte		        As2 , v100, gtp1
	.byte		N32   , En3 , v096, gtp1
	.byte	W32
	.byte	W01
	.byte	W01
	.byte	W01
	.byte		        En2 , v092, gtp2
	.byte		N32   , Gn2 , v092, gtp3
	.byte	W01
	.byte		        As2 , v092, gtp2
	.byte		N32   , Dn3 , v084, gtp1
	.byte	W32
	.byte	W01
	.byte	W01
mus_littleroot_5_B1:
	.byte	W01
@ 003   ----------------------------------------
	.byte		N44   , Dn2 , v108, gtp3
	.byte	W12
	.byte		N40   , An2 , v104, gtp1
	.byte	W12
	.byte		N32   , Dn3 , v108, gtp3
	.byte	W12
	.byte		        Fs3 
	.byte	W11
	.byte	W06
	.byte	W06
	.byte	W09
	.byte	W04
	.byte		N68   , Dn2 , v108, gtp3
	.byte		N68   , Gn2 , v104, gtp2
	.byte	W01
	.byte		        As2 , v104, gtp2
	.byte	W01
	.byte		N32   , En3 , v108, gtp2
	.byte	W22
@ 004   ----------------------------------------
	.byte	W12
	.byte		        Dn3 , v108, gtp3
	.byte	W32
	.byte	W03
	.byte	W01
	.byte		N56   , Dn2 , v112, gtp3
	.byte	W12
	.byte		        An2 , v100, gtp3
	.byte	W12
	.byte		N11   , Dn3 , v112
	.byte	W11
	.byte	W01
	.byte		        En3 , v108
	.byte	W11
	.byte	W01
@ 005   ----------------------------------------
	.byte		N23   , Dn3 
	.byte	W11
	.byte	W01
	.byte		N11   , An3 , v112
	.byte	W11
	.byte	W01
	.byte		N32   , Dn2 , v100, gtp2
	.byte		N32   , Gn2 , v104, gtp2
	.byte	W01
	.byte		        As2 , v104, gtp1
	.byte		N32   , En3 , v100, gtp2
	.byte	W32
	.byte	W01
	.byte	W01
	.byte	W01
	.byte		        En2 , v096, gtp2
	.byte		N32   , Gn2 , v100, gtp2
	.byte		N32   , Dn3 , v096, gtp1
	.byte	W01
	.byte		        As2 , v100, gtp1
	.byte	W32
	.byte	W01
	.byte	W01
	.byte	W01
@ 006   ----------------------------------------
	.byte		N68   , Dn2 , v100, gtp3
	.byte		N09   , An2 , v096
	.byte	W01
	.byte		N19   , Dn3 
	.byte		N24   , Fs3 , v096, gtp2
	.byte	W09
	.byte	W02
	.byte		N28   , An2 , v104, gtp1
	.byte	W08
	.byte	W04
	.byte		N32   , Dn3 , v104, gtp3
	.byte	W03
	.byte	W09
	.byte		N11   , Fs3 , v112
	.byte	W05
	.byte	W06
	.byte	W01
	.byte		N23   , An2 , v104
	.byte	W11
	.byte	W01
	.byte		N11   , Fs3 , v108
	.byte	W11
	.byte	W01
	.byte		N32   , Cs2 , v112, gtp3
	.byte		N11   , Gn2 , v104
	.byte		N17   , Bn2 , v112
	.byte	W01
	.byte		        En3 
	.byte	W10
	.byte	W01
	.byte		N11   , Gn2 
	.byte	W06
	.byte	W05
	.byte	W01
@ 007   ----------------------------------------
	.byte		        Bn2 , v108
	.byte	W11
	.byte	W01
	.byte		        En2 , v100
	.byte		N11   , Fs2 , v104
	.byte		N32   , As2 
	.byte	W01
	.byte		N11   , Cs3 , v112
	.byte	W10
	.byte	W01
	.byte		N20   , Fs2 , v100
	.byte	W12
	.byte		N11   , En3 , v104
	.byte	W09
	.byte	W02
	.byte	W01
	.byte		N68   , Bn1 , v108, gtp2
	.byte		N09   , Fs2 , v096
	.byte		N17   , An2 
	.byte		N23   , Dn3 , v112
	.byte	W09
	.byte	W03
	.byte		N56   , Fs2 , v100, gtp2
	.byte	W05
	.byte	W06
	.byte	W01
	.byte		N44   , An2 , v100, gtp2
	.byte	W12
	.byte		N32   , Bn2 , v100, gtp2
	.byte	W12
@ 008   ----------------------------------------
	.byte		N11   , Cs3 , v088
	.byte	W11
	.byte	W01
	.byte		        Dn3 , v104
	.byte	W10
	.byte	W01
	.byte	W01
	.byte		N56   , An1 , v100, gtp3
	.byte		N68   , Fs2 , v104, gtp3
	.byte		N11   , An2 
	.byte		N11   , Dn3 
	.byte	W11
	.byte	W01
	.byte		N56   , An2 , v100, gtp3
	.byte	W12
	.byte		N44   , Dn3 , v104, gtp3
	.byte	W12
	.byte		N32   , Fs3 , v088, gtp3
	.byte	W23
	.byte	W12
	.byte	W01
@ 009   ----------------------------------------
	.byte		N44   , Gn1 , v112, gtp3
	.byte		N23   , An2 , v104
	.byte		N23   , Bn2 
	.byte	W01
	.byte		        Dn3 , v112
	.byte	W11
	.byte		N32   , Dn2 , v108, gtp3
	.byte	W12
	.byte		        Gn2 , v104, gtp3
	.byte	W12
	.byte		N23   , An2 , v112
	.byte	W11
	.byte	W01
	.byte		        Bn2 , v108
	.byte	W11
	.byte	W01
	.byte		N11   , Dn3 , v104
	.byte	W11
	.byte	W01
	.byte		N44   , Gn1 , v096, gtp3
	.byte		N20   , An2 , v104
	.byte		N23   , Cs3 , v100
	.byte		N32   , En3 , v112, gtp3
	.byte	W12
	.byte		N40   , En2 , v104, gtp1
	.byte	W08
	.byte	W03
	.byte	W01
@ 010   ----------------------------------------
	.byte		N32   , Gn2 , v104, gtp3
	.byte	W11
	.byte	W01
	.byte		        Cs3 , v108, gtp3
	.byte	W11
	.byte	W06
	.byte	W06
	.byte	W12
	.byte	W01
	.byte		N44   , Fs1 , v100, gtp3
	.byte		N23   , An2 
	.byte		N32   , Dn3 , v112, gtp3
	.byte	W12
	.byte		N44   , Dn2 , v104, gtp3
	.byte	W11
	.byte	W01
	.byte		N32   , Fs2 , v100, gtp3
	.byte	W11
	.byte	W01
	.byte		N23   , An2 , v112
	.byte	W11
	.byte	W01
@ 011   ----------------------------------------
	.byte		        Dn3 , v104
	.byte	W11
	.byte	W01
	.byte		N11   , An3 , v108
	.byte	W11
	.byte	W01
	.byte		N68   , Bn1 , v108, gtp3
	.byte		N66   , Fs2 , v108, gtp1
	.byte		N10   , An2 , v096
	.byte		N20   , Dn3 , v116
	.byte	W11
	.byte	W01
	.byte		N22   , An2 , v104
	.byte	W09
	.byte	W03
	.byte		N11   , En3 
	.byte	W10
	.byte	W01
	.byte	W01
	.byte		N30   , An2 , v096, gtp1
	.byte		N30   , Dn3 , v112, gtp1
	.byte	W30
	.byte	W01
	.byte	W04
	.byte	W01
@ 012   ----------------------------------------
	.byte		N56   , En1 , v100
	.byte		N17   , Gn2 , v104
	.byte		N23   , Bn2 , v100
	.byte		N23   , Dn3 , v096
	.byte	W12
	.byte		N56   , En2 , v108, gtp3
	.byte	W05
	.byte	W06
	.byte	W01
	.byte		N28   , Gn2 , v108, gtp1
	.byte	W12
	.byte		N23   , Bn2 , v096
	.byte	W12
	.byte		N11   , Dn3 , v100
	.byte	W05
	.byte	W03
	.byte	W03
	.byte	W01
	.byte		N05   , Gn2 
	.byte	W05
	.byte	W06
	.byte	W01
	.byte		N68   , An1 , v096, gtp3
	.byte		N68   , Gn2 , v092, gtp3
	.byte		N32   , Bn2 , v104, gtp3
	.byte		N32   , Dn3 , v108, gtp3
	.byte	W24
@ 013   ----------------------------------------
	.byte	W11
	.byte	W01
	.byte		        Cs3 , v100, gtp3
	.byte	W32
	.byte	W03
	.byte	W01
	.byte		        Dn2 , v100, gtp3
	.byte		N10   , Fs2 
	.byte	W01
	.byte		N16   , An2 , v104
	.byte		N22   , Dn3 , v108
	.byte	W10
	.byte	W01
	.byte		N23   , Fs2 , v100
	.byte	W05
	.byte	W07
	.byte		N11   , An2 , v096
	.byte	W11
	.byte	W01
	.byte		N10   , Gn2 , v104
	.byte		N10   , Bn2 
	.byte	W10
	.byte	W02
@ 014   ----------------------------------------
	.byte		        Fs2 , v096
	.byte	W01
	.byte		        An2 
	.byte	W09
	.byte	W01
	.byte	W01
	.byte		        En2 , v100
	.byte	W01
	.byte		        Gn2 
	.byte	W09
	.byte	W01
	.byte	W01
	.byte		N56   , Dn2 , v100, gtp3
	.byte		N56   , Fs2 , v096, gtp3
	.byte	W01
	.byte		        An2 , v108, gtp3
	.byte	W56
	.byte	W02
	.byte	W01
	.byte	W12
@ 015   ----------------------------------------
	.byte		N44   , Dn2 , v096, gtp3
	.byte	W12
	.byte		N40   , An2 , v092, gtp1
	.byte	W12
	.byte		N32   , Dn3 , v096, gtp3
	.byte	W12
	.byte		        Fs3 , v092
	.byte	W11
	.byte	W06
	.byte	W06
	.byte	W09
	.byte	W04
	.byte		N68   , Dn2 , v096, gtp3
	.byte		N68   , Gn2 , v092, gtp2
	.byte	W01
	.byte		        As2 , v092, gtp2
	.byte	W01
	.byte		N32   , En3 , v092, gtp2
	.byte	W22
@ 016   ----------------------------------------
	.byte	W12
	.byte		        Dn3 , v092, gtp2
	.byte	W32
	.byte	W02
	.byte	W01
	.byte	W01
	.byte		N56   , Dn2 , v096, gtp3
	.byte	W12
	.byte		        An2 , v088, gtp3
	.byte	W12
	.byte		N17   , Dn3 , v096
	.byte	W12
	.byte		N11   , En3 , v092
	.byte	W05
	.byte	W06
	.byte	W01
@ 017   ----------------------------------------
	.byte		N23   , Dn3 , v096
	.byte	W11
	.byte	W01
	.byte		N11   , An3 
	.byte	W11
	.byte	W01
	.byte		N32   , Dn2 , v100, gtp3
	.byte		N32   , Gn2 , v092, gtp2
	.byte	W01
	.byte		        As2 , v092, gtp2
	.byte		N32   , En3 , v092, gtp1
	.byte	W32
	.byte	W01
	.byte	W01
	.byte	W01
	.byte		        En2 , v100, gtp2
	.byte		N32   , Gn2 , v092, gtp2
	.byte		N32   , As2 , v092, gtp2
	.byte	W01
	.byte		        Dn3 , v092, gtp2
	.byte	W32
	.byte	W01
	.byte	W01
	.byte	GOTO
	 .word	mus_littleroot_5_B1
mus_littleroot_5_B2:
	.byte	FINE

@**************** Track 6 (Midi-Chn.6) ****************@

mus_littleroot_6:
	.byte	KEYSH , mus_littleroot_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 5
	.byte		VOL   , 50*mus_littleroot_mvl/mxv
	.byte		PAN   , c_v+56
	.byte		MOD   , 0
	.byte	W12
	.byte		N64   , Fs3 , v092, gtp1
	.byte	W48
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W02
	.byte	W01
	.byte	W01
	.byte		N01   , En3 , v088
	.byte	W01
	.byte	W01
	.byte		        Fs3 
	.byte	W01
	.byte		N32   , Gn3 , v096
	.byte	W14
@ 001   ----------------------------------------
	.byte	W18
	.byte	W01
	.byte		N02   , Gs3 , v092
	.byte	W02
	.byte	W01
	.byte		N28   , An3 , v096
	.byte	W28
	.byte	W01
	.byte		N02   , Gs3 , v088
	.byte	W02
	.byte	W01
	.byte		        Gn3 
	.byte	W02
	.byte	W01
	.byte		N68   , Fs3 , v092
	.byte	W36
	.byte	W03
@ 002   ----------------------------------------
	.byte	W15
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W02
	.byte	W01
	.byte	W01
	.byte		N01   , Ds3 
	.byte	W01
	.byte	W01
	.byte		N32   , En3 , v092, gtp3
	.byte	W21
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W02
	.byte	W01
	.byte		N24   , Dn3 , v088, gtp2
	.byte	W21
	.byte	W03
	.byte	W02
mus_littleroot_6_B1:
	.byte	W01
@ 003   ----------------------------------------
	.byte	W03
	.byte	W03
	.byte	W18
	.byte	W72
@ 004   ----------------------------------------
	.byte	W96
@ 005   ----------------------------------------
	.byte	W96
@ 006   ----------------------------------------
	.byte	W96
@ 007   ----------------------------------------
	.byte	W96
@ 008   ----------------------------------------
	.byte	W96
@ 009   ----------------------------------------
	.byte	W96
@ 010   ----------------------------------------
	.byte	W96
@ 011   ----------------------------------------
	.byte	W96
@ 012   ----------------------------------------
	.byte	W96
@ 013   ----------------------------------------
	.byte	W96
@ 014   ----------------------------------------
	.byte	W96
@ 015   ----------------------------------------
	.byte	W03
	.byte		N01   , Dn3 , v080
	.byte	W01
	.byte		        En3 
	.byte	W01
	.byte	W01
	.byte		N68   , Fs3 , v084
	.byte	W48
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W02
	.byte	W01
	.byte		N01   , Cs3 , v080
	.byte	W01
	.byte		        Dn3 
	.byte	W01
	.byte	W01
	.byte		N32   , En3 , v088
	.byte	W18
@ 016   ----------------------------------------
	.byte	W14
	.byte		N02   , Cs3 , v084
	.byte	W03
	.byte	W01
	.byte		N32   , Dn3 , v088
	.byte	W32
	.byte	W01
	.byte		N02   , En3 , v080
	.byte	W02
	.byte	W01
	.byte		N68   , Fs3 , v084
	.byte	W42
@ 017   ----------------------------------------
	.byte	W12
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W02
	.byte	W01
	.byte	W01
	.byte		N01   
	.byte	W01
	.byte	W01
	.byte		N32   , Gn3 , v084, gtp3
	.byte	W21
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W02
	.byte	W01
	.byte		N28   , An3 , v080, gtp1
	.byte	W21
	.byte	W03
	.byte	W03
	.byte	W02
	.byte	GOTO
	 .word	mus_littleroot_6_B1
mus_littleroot_6_B2:
	.byte	FINE

@**************** Track 7 (Midi-Chn.7) ****************@

mus_littleroot_7:
	.byte	KEYSH , mus_littleroot_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 45
	.byte		VOL   , 92*mus_littleroot_mvl/mxv
	.byte		PAN   , c_v-34
	.byte		MOD   , 0
	.byte	W96
@ 001   ----------------------------------------
	.byte	W96
@ 002   ----------------------------------------
	.byte	W92
	.byte	W03
mus_littleroot_7_B1:
	.byte	W01
@ 003   ----------------------------------------
	.byte		N02   , An3 , v060
	.byte	W02
	.byte	W01
	.byte		        An3 , v056
	.byte	W02
	.byte	W01
	.byte		        An3 , v044
	.byte	W02
	.byte	W01
	.byte		        An3 , v056
	.byte	W02
	.byte	W01
	.byte		        An3 , v052
	.byte	W02
	.byte	W01
	.byte		        An3 , v060
	.byte	W02
	.byte	W01
	.byte		N01   , An3 , v056
	.byte	W01
	.byte	W01
	.byte		        An3 , v068
	.byte	W01
	.byte	W01
	.byte		        An3 , v064
	.byte	W01
	.byte	W01
	.byte		        An3 , v068
	.byte	W01
	.byte	W01
	.byte		        An3 , v064
	.byte	W01
	.byte	W01
	.byte		        An3 , v060
	.byte	W01
	.byte	W01
	.byte		        An3 , v056
	.byte	W01
	.byte	W01
	.byte		        An3 , v064
	.byte	W01
	.byte	W01
	.byte		        An3 , v060
	.byte	W01
	.byte	W01
	.byte		        An3 , v076
	.byte	W01
	.byte	W01
	.byte		        An3 , v072
	.byte	W01
	.byte	W01
	.byte		        An3 , v068
	.byte	W01
	.byte	W01
	.byte		        An3 , v064
	.byte	W01
	.byte	W01
	.byte		        An3 , v076
	.byte	W01
	.byte	W01
	.byte		        An3 , v072
	.byte	W01
	.byte	W01
	.byte		        An3 , v080
	.byte	W01
	.byte	W01
	.byte		        An3 , v076
	.byte	W01
	.byte	W01
	.byte		        An3 , v072
	.byte	W01
	.byte	W01
	.byte		        An3 , v068
	.byte	W01
	.byte	W01
	.byte		        An3 , v080
	.byte	W01
	.byte	W01
	.byte		        An3 , v076
	.byte	W01
	.byte	W01
	.byte		        An3 , v092
	.byte	W01
	.byte	W01
	.byte		        An3 , v088
	.byte	W01
	.byte	W01
	.byte		        An3 , v084
	.byte	W01
	.byte	W01
	.byte		        An3 , v080
	.byte	W01
	.byte	W01
	.byte		        An3 , v092
	.byte	W01
	.byte	W01
	.byte		        An3 , v088
	.byte	W01
	.byte	W01
	.byte		        Gn3 , v060
	.byte	W01
	.byte	W01
	.byte		        Gn3 , v056
	.byte	W01
	.byte	W01
	.byte		        Gn3 , v048
	.byte	W01
	.byte	W01
	.byte		        Gn3 , v044
	.byte	W01
	.byte	W01
	.byte		        Gn3 , v056
	.byte	W01
	.byte	W01
	.byte		        Gn3 , v052
	.byte	W01
	.byte	W01
	.byte		        Gn3 , v068
	.byte	W01
	.byte	W01
	.byte		        Gn3 , v064
	.byte	W01
	.byte	W01
	.byte		        Gn3 , v060
	.byte	W01
	.byte	W01
	.byte		        Gn3 , v056
	.byte	W01
	.byte	W01
	.byte		        Gn3 , v068
	.byte	W01
	.byte	W01
	.byte		        Gn3 , v064
	.byte	W01
	.byte	W01
@ 004   ----------------------------------------
	.byte		        Gn3 , v076
	.byte	W01
	.byte	W01
	.byte		        Gn3 , v072
	.byte	W01
	.byte	W01
	.byte		        Gn3 , v064
	.byte	W01
	.byte	W01
	.byte		        Gn3 , v060
	.byte	W01
	.byte	W01
	.byte		        Gn3 , v072
	.byte	W01
	.byte	W01
	.byte		        Gn3 , v068
	.byte	W01
	.byte	W01
	.byte		        An3 , v064
	.byte	W01
	.byte	W01
	.byte		        An3 , v060
	.byte	W01
	.byte	W01
	.byte		        An3 , v056
	.byte	W01
	.byte	W01
	.byte		        An3 , v052
	.byte	W01
	.byte	W01
	.byte		        An3 , v060
	.byte	W01
	.byte	W01
	.byte		        An3 , v056
	.byte	W01
	.byte	W01
	.byte		        An3 , v072
	.byte	W01
	.byte	W01
	.byte		        An3 , v068
	.byte	W01
	.byte	W01
	.byte		        An3 , v064
	.byte	W01
	.byte	W01
	.byte		        An3 , v060
	.byte	W01
	.byte	W01
	.byte		        An3 , v072
	.byte	W01
	.byte	W01
	.byte		        An3 , v068
	.byte	W01
	.byte	W01
	.byte		        An3 , v080
	.byte	W01
	.byte	W01
	.byte		        An3 , v076
	.byte	W01
	.byte	W01
	.byte		        An3 , v072
	.byte	W01
	.byte	W01
	.byte		        An3 , v068
	.byte	W01
	.byte	W01
	.byte		        An3 , v076
	.byte	W01
	.byte	W01
	.byte		        An3 , v072
	.byte	W01
	.byte	W01
	.byte		N02   , Fs3 , v060
	.byte	W02
	.byte	W01
	.byte		        Fs3 , v056
	.byte	W02
	.byte	W01
	.byte		        Fs3 , v044
	.byte	W02
	.byte	W01
	.byte		        Fs3 , v056
	.byte	W02
	.byte	W01
	.byte		        Fs3 , v052
	.byte	W02
	.byte	W01
	.byte		        Fs3 , v060
	.byte	W02
	.byte	W01
	.byte		N01   , Fs3 , v056
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v068
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v064
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v068
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v064
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v060
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v056
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v064
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v060
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v076
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v072
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v068
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v064
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v076
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v072
	.byte	W01
	.byte	W01
@ 005   ----------------------------------------
	.byte		        Fs3 , v080
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v076
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v072
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v068
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v080
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v076
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v092
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v088
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v084
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v080
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v092
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v088
	.byte	W01
	.byte	W01
	.byte		        En3 , v060
	.byte	W01
	.byte	W01
	.byte		        En3 , v056
	.byte	W01
	.byte	W01
	.byte		        En3 , v048
	.byte	W01
	.byte	W01
	.byte		        En3 , v044
	.byte	W01
	.byte	W01
	.byte		        En3 , v056
	.byte	W01
	.byte	W01
	.byte		        En3 , v052
	.byte	W01
	.byte	W01
	.byte		        En3 , v068
	.byte	W01
	.byte	W01
	.byte		        En3 , v064
	.byte	W01
	.byte	W01
	.byte		        En3 , v060
	.byte	W01
	.byte	W01
	.byte		        En3 , v056
	.byte	W01
	.byte	W01
	.byte		        En3 , v068
	.byte	W01
	.byte	W01
	.byte		        En3 , v064
	.byte	W01
	.byte	W01
	.byte		        En3 , v076
	.byte	W01
	.byte	W01
	.byte		        En3 , v072
	.byte	W01
	.byte	W01
	.byte		        En3 , v064
	.byte	W01
	.byte	W01
	.byte		        En3 , v060
	.byte	W01
	.byte	W01
	.byte		        En3 , v072
	.byte	W01
	.byte	W01
	.byte		        En3 , v068
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v060
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v056
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v048
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v044
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v056
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v052
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v068
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v064
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v060
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v056
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v068
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v064
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v076
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v072
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v064
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v060
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v072
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v068
	.byte	W01
	.byte	W01
@ 006   ----------------------------------------
	.byte		N02   , An3 , v060
	.byte	W02
	.byte	W01
	.byte		        An3 , v056
	.byte	W02
	.byte	W01
	.byte		        An3 , v044
	.byte	W02
	.byte	W01
	.byte		        An3 , v056
	.byte	W02
	.byte	W01
	.byte		        An3 , v052
	.byte	W02
	.byte	W01
	.byte		        An3 , v060
	.byte	W02
	.byte	W01
	.byte		N01   , An3 , v056
	.byte	W01
	.byte	W01
	.byte		        An3 , v068
	.byte	W01
	.byte	W01
	.byte		        An3 , v064
	.byte	W01
	.byte	W01
	.byte		        An3 , v068
	.byte	W01
	.byte	W01
	.byte		        An3 , v064
	.byte	W01
	.byte	W01
	.byte		        An3 , v060
	.byte	W01
	.byte	W01
	.byte		        An3 , v056
	.byte	W01
	.byte	W01
	.byte		        An3 , v064
	.byte	W01
	.byte	W01
	.byte		        An3 , v060
	.byte	W01
	.byte	W01
	.byte		        An3 , v076
	.byte	W01
	.byte	W01
	.byte		        An3 , v072
	.byte	W01
	.byte	W01
	.byte		        An3 , v068
	.byte	W01
	.byte	W01
	.byte		        An3 , v064
	.byte	W01
	.byte	W01
	.byte		        An3 , v076
	.byte	W01
	.byte	W01
	.byte		        An3 , v072
	.byte	W01
	.byte	W01
	.byte		        An3 , v080
	.byte	W01
	.byte	W01
	.byte		        An3 , v076
	.byte	W01
	.byte	W01
	.byte		        An3 , v072
	.byte	W01
	.byte	W01
	.byte		        An3 , v068
	.byte	W01
	.byte	W01
	.byte		        An3 , v080
	.byte	W01
	.byte	W01
	.byte		        An3 , v076
	.byte	W01
	.byte	W01
	.byte		        An3 , v092
	.byte	W01
	.byte	W01
	.byte		        An3 , v088
	.byte	W01
	.byte	W01
	.byte		        An3 , v084
	.byte	W01
	.byte	W01
	.byte		        An3 , v080
	.byte	W01
	.byte	W01
	.byte		        An3 , v092
	.byte	W01
	.byte	W01
	.byte		        An3 , v088
	.byte	W01
	.byte		        Gn3 , v060
	.byte	W02
	.byte		        Gn3 , v056
	.byte	W02
	.byte		        Gn3 , v048
	.byte	W02
	.byte		        Gn3 , v044
	.byte	W02
	.byte		        Gn3 , v056
	.byte	W02
	.byte		        Gn3 , v052
	.byte	W02
	.byte		        Gn3 , v068
	.byte	W02
	.byte		        Gn3 , v064
	.byte	W02
	.byte		        Gn3 , v060
	.byte	W02
	.byte		        Gn3 , v056
	.byte	W02
	.byte		        Gn3 , v068
	.byte	W02
	.byte		        Gn3 , v064
	.byte	W02
	.byte		        Gn3 , v076
	.byte	W01
@ 007   ----------------------------------------
	.byte	W01
	.byte		        Gn3 , v072
	.byte	W02
	.byte		        Gn3 , v064
	.byte	W02
	.byte		        Gn3 , v060
	.byte	W02
	.byte		        Gn3 , v072
	.byte	W02
	.byte		        Gn3 , v068
	.byte	W02
	.byte	W01
	.byte		        Gn3 , v060
	.byte	W01
	.byte	W01
	.byte		        Gn3 , v056
	.byte	W01
	.byte	W01
	.byte		        Gn3 , v048
	.byte	W01
	.byte	W01
	.byte		        Gn3 , v044
	.byte	W01
	.byte	W01
	.byte		        Gn3 , v056
	.byte	W01
	.byte	W01
	.byte		        Gn3 , v052
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v068
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v064
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v060
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v056
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v068
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v064
	.byte	W01
	.byte	W01
	.byte		        En3 , v076
	.byte	W01
	.byte	W01
	.byte		        En3 , v072
	.byte	W01
	.byte	W01
	.byte		        En3 , v064
	.byte	W01
	.byte	W01
	.byte		        En3 , v060
	.byte	W01
	.byte	W01
	.byte		        En3 , v072
	.byte	W01
	.byte	W01
	.byte		        En3 , v068
	.byte	W01
	.byte	W01
	.byte		        Dn3 , v060
	.byte	W01
	.byte	W01
	.byte		        Dn3 , v056
	.byte	W01
	.byte	W01
	.byte		        Dn3 , v048
	.byte	W01
	.byte	W01
	.byte		        Dn3 , v044
	.byte	W01
	.byte	W01
	.byte		        Dn3 , v056
	.byte	W01
	.byte	W01
	.byte		        Dn3 , v052
	.byte	W01
	.byte	W01
	.byte		        Dn3 , v068
	.byte	W01
	.byte	W01
	.byte		        Dn3 , v064
	.byte	W01
	.byte	W01
	.byte		        Dn3 , v060
	.byte	W01
	.byte	W01
	.byte		        Dn3 , v056
	.byte	W01
	.byte	W01
	.byte		        Dn3 , v068
	.byte	W01
	.byte	W01
	.byte		        Dn3 , v064
	.byte	W01
	.byte	W01
	.byte		        Dn3 , v076
	.byte	W01
	.byte	W01
	.byte		        Dn3 , v072
	.byte	W01
	.byte	W01
	.byte		        Dn3 , v064
	.byte	W01
	.byte	W01
	.byte		        Dn3 , v060
	.byte	W01
	.byte	W01
	.byte		        Dn3 , v072
	.byte	W01
	.byte	W01
	.byte		        Dn3 , v068
	.byte	W01
	.byte	W01
	.byte		        Dn3 , v084
	.byte	W01
	.byte	W01
	.byte		        Dn3 , v080
	.byte	W01
	.byte	W01
	.byte		        Dn3 , v076
	.byte	W01
	.byte	W01
	.byte		        Dn3 , v072
	.byte	W01
	.byte	W01
	.byte		        Dn3 , v084
	.byte	W01
	.byte	W01
	.byte		        Dn3 , v080
	.byte	W01
	.byte	W01
@ 008   ----------------------------------------
	.byte		        Dn3 , v084
	.byte	W01
	.byte	W01
	.byte		        Dn3 , v080
	.byte	W01
	.byte	W01
	.byte		        Dn3 , v072
	.byte	W01
	.byte	W01
	.byte		        Dn3 , v068
	.byte	W01
	.byte	W01
	.byte		        Dn3 , v080
	.byte	W01
	.byte	W01
	.byte		        Dn3 , v076
	.byte	W01
	.byte	W01
	.byte		        Dn3 , v092
	.byte	W01
	.byte	W01
	.byte		        Dn3 , v088
	.byte	W01
	.byte	W01
	.byte		        Dn3 , v084
	.byte	W01
	.byte	W01
	.byte		        Dn3 , v080
	.byte	W01
	.byte	W01
	.byte		        Dn3 , v092
	.byte	W01
	.byte	W01
	.byte		        Dn3 , v088
	.byte	W01
	.byte		        En3 , v060
	.byte	W02
	.byte		        En3 , v056
	.byte	W02
	.byte		        En3 , v048
	.byte	W02
	.byte		        En3 , v044
	.byte	W02
	.byte		        En3 , v056
	.byte	W02
	.byte		        En3 , v052
	.byte	W02
	.byte		        En3 , v068
	.byte	W02
	.byte		        En3 , v064
	.byte	W02
	.byte		        En3 , v060
	.byte	W02
	.byte		        En3 , v056
	.byte	W02
	.byte		        En3 , v068
	.byte	W02
	.byte		        En3 , v064
	.byte	W02
	.byte		        En3 , v076
	.byte	W02
	.byte		        En3 , v072
	.byte	W02
	.byte		        En3 , v064
	.byte	W02
	.byte		        En3 , v060
	.byte	W02
	.byte		        En3 , v072
	.byte	W02
	.byte		        En3 , v068
	.byte	W02
	.byte		        Fs3 , v060
	.byte	W02
	.byte		        Fs3 , v056
	.byte	W02
	.byte		        Fs3 , v048
	.byte	W02
	.byte		        Fs3 , v044
	.byte	W02
	.byte		        Fs3 , v056
	.byte	W02
	.byte		        Fs3 , v052
	.byte	W02
	.byte		        Fs3 , v068
	.byte	W02
	.byte		        Fs3 , v064
	.byte	W02
	.byte		        Fs3 , v060
	.byte	W02
	.byte		        Fs3 , v056
	.byte	W02
	.byte		        Fs3 , v068
	.byte	W02
	.byte		        Fs3 , v064
	.byte	W02
	.byte		        Fs3 , v076
	.byte	W02
	.byte		        Fs3 , v072
	.byte	W02
	.byte		        Fs3 , v064
	.byte	W02
	.byte		        Fs3 , v060
	.byte	W02
	.byte		        Fs3 , v072
	.byte	W02
	.byte		        Fs3 , v068
	.byte	W02
	.byte	W01
@ 009   ----------------------------------------
	.byte		N02   , Bn3 , v060
	.byte	W02
	.byte	W01
	.byte		        Bn3 , v056
	.byte	W02
	.byte	W01
	.byte		        Bn3 , v048
	.byte	W02
	.byte	W01
	.byte		        Bn3 , v060
	.byte	W02
	.byte	W01
	.byte		        Bn3 , v056
	.byte	W02
	.byte	W01
	.byte		        Bn3 , v064
	.byte	W02
	.byte	W01
	.byte		N01   , Bn3 , v060
	.byte	W01
	.byte	W01
	.byte		        Bn3 , v068
	.byte	W01
	.byte	W01
	.byte		        Bn3 , v064
	.byte	W01
	.byte	W01
	.byte		        Bn3 , v068
	.byte	W01
	.byte	W01
	.byte		        Bn3 , v064
	.byte	W01
	.byte	W01
	.byte		        Bn3 , v060
	.byte	W01
	.byte	W01
	.byte		        Bn3 , v056
	.byte	W01
	.byte	W01
	.byte		        Bn3 , v068
	.byte	W01
	.byte	W01
	.byte		        Bn3 , v064
	.byte	W01
	.byte	W01
	.byte		        Bn3 , v080
	.byte	W01
	.byte	W01
	.byte		        Bn3 , v076
	.byte	W01
	.byte	W01
	.byte		        Bn3 , v072
	.byte	W01
	.byte	W01
	.byte		        Bn3 , v068
	.byte	W01
	.byte	W01
	.byte		        Bn3 , v080
	.byte	W01
	.byte	W01
	.byte		        Bn3 , v076
	.byte	W01
	.byte	W01
	.byte		        Bn3 , v084
	.byte	W01
	.byte	W01
	.byte		        Bn3 , v080
	.byte	W01
	.byte	W01
	.byte		        Bn3 , v076
	.byte	W01
	.byte	W01
	.byte		        Bn3 , v072
	.byte	W01
	.byte	W01
	.byte		        Bn3 , v080
	.byte	W01
	.byte	W01
	.byte		        Bn3 , v076
	.byte	W01
	.byte	W01
	.byte		        Bn3 , v092
	.byte	W01
	.byte	W01
	.byte		        Bn3 , v088
	.byte	W01
	.byte	W01
	.byte		        Bn3 , v084
	.byte	W01
	.byte	W01
	.byte		        Bn3 , v080
	.byte	W01
	.byte	W01
	.byte		        Bn3 , v092
	.byte	W01
	.byte	W01
	.byte		        Bn3 , v088
	.byte	W01
	.byte	W01
	.byte		N02   , An3 , v060
	.byte	W02
	.byte	W01
	.byte		        An3 , v056
	.byte	W02
	.byte	W01
	.byte		        An3 , v048
	.byte	W02
	.byte	W01
	.byte		        An3 , v060
	.byte	W02
	.byte	W01
	.byte		        An3 , v056
	.byte	W02
	.byte	W01
	.byte		        An3 , v064
	.byte	W02
	.byte	W01
	.byte		N01   , An3 , v060
	.byte	W01
	.byte	W01
	.byte		        An3 , v068
	.byte	W01
	.byte	W01
	.byte		        An3 , v064
	.byte	W01
	.byte	W01
@ 010   ----------------------------------------
	.byte		        An3 , v068
	.byte	W01
	.byte	W01
	.byte		        An3 , v064
	.byte	W01
	.byte	W01
	.byte		        An3 , v060
	.byte	W01
	.byte	W01
	.byte		        An3 , v056
	.byte	W01
	.byte	W01
	.byte		        An3 , v068
	.byte	W01
	.byte	W01
	.byte		        An3 , v064
	.byte	W01
	.byte	W01
	.byte		N02   , Gn3 , v060
	.byte	W02
	.byte	W01
	.byte		        Gn3 , v056
	.byte	W02
	.byte	W01
	.byte		        Gn3 , v048
	.byte	W02
	.byte	W01
	.byte		        Gn3 , v060
	.byte	W02
	.byte	W01
	.byte		        Gn3 , v056
	.byte	W02
	.byte	W01
	.byte		        Gn3 , v064
	.byte	W02
	.byte	W01
	.byte		N01   , Gn3 , v060
	.byte	W01
	.byte	W01
	.byte		        Gn3 , v064
	.byte	W01
	.byte	W01
	.byte		        Gn3 , v060
	.byte	W01
	.byte	W01
	.byte		        Gn3 , v068
	.byte	W01
	.byte	W01
	.byte		        Gn3 , v064
	.byte	W01
	.byte	W01
	.byte		        Gn3 , v068
	.byte	W01
	.byte	W01
	.byte		        Gn3 , v060
	.byte	W01
	.byte	W01
	.byte		        Gn3 , v068
	.byte	W01
	.byte	W01
	.byte		        Gn3 , v064
	.byte	W01
	.byte	W01
	.byte		N02   , Fs3 
	.byte	W02
	.byte	W01
	.byte		        Fs3 , v060
	.byte	W02
	.byte	W01
	.byte		        Fs3 , v048
	.byte	W02
	.byte	W01
	.byte		        Fs3 , v060
	.byte	W02
	.byte	W01
	.byte		        Fs3 , v056
	.byte	W02
	.byte	W01
	.byte		        Fs3 , v064
	.byte	W02
	.byte	W01
	.byte		N01   , Fs3 , v060
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v072
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v068
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v072
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v068
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v064
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v060
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v068
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v064
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v080
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v076
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v072
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v068
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v080
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v076
	.byte	W01
	.byte	W01
@ 011   ----------------------------------------
	.byte		        Fs3 , v084
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v080
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v076
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v072
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v084
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v080
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v096
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v092
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v088
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v084
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v096
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v092
	.byte	W01
	.byte	W01
	.byte		N02   , Dn3 , v060
	.byte	W02
	.byte	W01
	.byte		        Dn3 , v056
	.byte	W02
	.byte	W01
	.byte		        Dn3 , v048
	.byte	W02
	.byte	W01
	.byte		        Dn3 , v060
	.byte	W02
	.byte	W01
	.byte		        Dn3 , v056
	.byte	W02
	.byte	W01
	.byte		        Dn3 , v064
	.byte	W02
	.byte	W01
	.byte		N01   , Dn3 , v060
	.byte	W01
	.byte	W01
	.byte		        Dn3 , v064
	.byte	W01
	.byte	W01
	.byte		        Dn3 , v060
	.byte	W01
	.byte	W01
	.byte		        Dn3 , v068
	.byte	W01
	.byte	W01
	.byte		        Dn3 , v064
	.byte	W01
	.byte	W01
	.byte		        Dn3 , v068
	.byte	W01
	.byte	W01
	.byte		        Dn3 , v060
	.byte	W01
	.byte	W01
	.byte		        Dn3 , v068
	.byte	W01
	.byte	W01
	.byte		        Dn3 , v064
	.byte	W01
	.byte	W01
	.byte		N02   , Fs3 
	.byte	W02
	.byte	W01
	.byte		        Fs3 , v060
	.byte	W02
	.byte	W01
	.byte		        Fs3 , v052
	.byte	W02
	.byte	W01
	.byte		        Fs3 , v064
	.byte	W02
	.byte	W01
	.byte		        Fs3 , v060
	.byte	W02
	.byte	W01
	.byte		        Fs3 , v068
	.byte	W02
	.byte	W01
	.byte		N01   , Fs3 , v064
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v068
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v064
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v076
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v068
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v072
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v064
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v076
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v068
	.byte	W01
	.byte	W01
@ 012   ----------------------------------------
	.byte		N02   , En3 , v060
	.byte	W02
	.byte	W01
	.byte		        En3 , v056
	.byte	W02
	.byte	W01
	.byte		        En3 , v044
	.byte	W02
	.byte	W01
	.byte		        En3 , v056
	.byte	W02
	.byte	W01
	.byte		        En3 , v052
	.byte	W02
	.byte	W01
	.byte		        En3 , v060
	.byte	W02
	.byte	W01
	.byte		N01   , En3 , v056
	.byte	W01
	.byte	W01
	.byte		        En3 , v068
	.byte	W01
	.byte	W01
	.byte		        En3 , v064
	.byte	W01
	.byte	W01
	.byte		        En3 , v068
	.byte	W01
	.byte	W01
	.byte		        En3 , v064
	.byte	W01
	.byte	W01
	.byte		        En3 , v060
	.byte	W01
	.byte	W01
	.byte		        En3 , v056
	.byte	W01
	.byte	W01
	.byte		        En3 , v064
	.byte	W01
	.byte	W01
	.byte		        En3 , v060
	.byte	W01
	.byte	W01
	.byte		        En3 , v076
	.byte	W01
	.byte	W01
	.byte		        En3 , v072
	.byte	W01
	.byte	W01
	.byte		        En3 , v068
	.byte	W01
	.byte	W01
	.byte		        En3 , v064
	.byte	W01
	.byte	W01
	.byte		        En3 , v076
	.byte	W01
	.byte	W01
	.byte		        En3 , v072
	.byte	W01
	.byte	W01
	.byte		        Dn3 , v080
	.byte	W01
	.byte	W01
	.byte		        Dn3 , v076
	.byte	W01
	.byte	W01
	.byte		        Dn3 , v072
	.byte	W01
	.byte	W01
	.byte		        Dn3 , v068
	.byte	W01
	.byte	W01
	.byte		        Dn3 , v080
	.byte	W01
	.byte	W01
	.byte		        Dn3 , v076
	.byte	W01
	.byte	W01
	.byte		        En3 , v092
	.byte	W01
	.byte	W01
	.byte		        En3 , v088
	.byte	W01
	.byte	W01
	.byte		        En3 , v084
	.byte	W01
	.byte	W01
	.byte		        En3 , v080
	.byte	W01
	.byte	W01
	.byte		        En3 , v092
	.byte	W01
	.byte	W01
	.byte		        En3 , v088
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v060
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v056
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v048
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v044
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v056
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v052
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v068
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v064
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v060
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v056
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v068
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v064
	.byte	W01
	.byte	W01
@ 013   ----------------------------------------
	.byte		        Fs3 , v076
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v072
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v064
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v060
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v072
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v068
	.byte	W01
	.byte	W01
	.byte		        En3 , v060
	.byte	W01
	.byte	W01
	.byte		        En3 , v056
	.byte	W01
	.byte	W01
	.byte		        En3 , v048
	.byte	W01
	.byte	W01
	.byte		        En3 , v044
	.byte	W01
	.byte	W01
	.byte		        En3 , v056
	.byte	W01
	.byte	W01
	.byte		        En3 , v052
	.byte	W01
	.byte	W01
	.byte		        En3 , v068
	.byte	W01
	.byte	W01
	.byte		        En3 , v064
	.byte	W01
	.byte	W01
	.byte		        En3 , v060
	.byte	W01
	.byte	W01
	.byte		        En3 , v056
	.byte	W01
	.byte	W01
	.byte		        En3 , v068
	.byte	W01
	.byte	W01
	.byte		        En3 , v064
	.byte	W01
	.byte	W01
	.byte		        En3 , v076
	.byte	W01
	.byte	W01
	.byte		        En3 , v072
	.byte	W01
	.byte	W01
	.byte		        En3 , v064
	.byte	W01
	.byte	W01
	.byte		        En3 , v060
	.byte	W01
	.byte	W01
	.byte		        En3 , v072
	.byte	W01
	.byte	W01
	.byte		        En3 , v068
	.byte	W01
	.byte	W01
	.byte		N02   , Dn3 , v060
	.byte	W02
	.byte	W01
	.byte		        Dn3 , v056
	.byte	W02
	.byte	W01
	.byte		        Dn3 , v044
	.byte	W02
	.byte	W01
	.byte		        Dn3 , v056
	.byte	W02
	.byte	W01
	.byte		        Dn3 , v052
	.byte	W02
	.byte	W01
	.byte		        Dn3 , v060
	.byte	W02
	.byte	W01
	.byte		N01   , Dn3 , v056
	.byte	W01
	.byte	W01
	.byte		        Dn3 , v068
	.byte	W01
	.byte	W01
	.byte		        Dn3 , v064
	.byte	W01
	.byte	W01
	.byte		        Dn3 , v068
	.byte	W01
	.byte	W01
	.byte		        Dn3 , v064
	.byte	W01
	.byte	W01
	.byte		        Dn3 , v060
	.byte	W01
	.byte	W01
	.byte		        Dn3 , v056
	.byte	W01
	.byte	W01
	.byte		        Dn3 , v064
	.byte	W01
	.byte	W01
	.byte		        Dn3 , v060
	.byte	W01
	.byte	W01
	.byte		        Dn3 , v076
	.byte	W01
	.byte	W01
	.byte		        Dn3 , v072
	.byte	W01
	.byte	W01
	.byte		        Dn3 , v068
	.byte	W01
	.byte	W01
	.byte		        Dn3 , v064
	.byte	W01
	.byte	W01
	.byte		        Dn3 , v076
	.byte	W01
	.byte	W01
	.byte		        Dn3 , v072
	.byte	W01
	.byte	W01
@ 014   ----------------------------------------
	.byte		        Dn3 , v080
	.byte	W01
	.byte	W01
	.byte		        Dn3 , v076
	.byte	W01
	.byte	W01
	.byte		        Dn3 , v072
	.byte	W01
	.byte	W01
	.byte		        Dn3 , v068
	.byte	W01
	.byte	W01
	.byte		        Dn3 , v080
	.byte	W01
	.byte	W01
	.byte		        Dn3 , v076
	.byte	W01
	.byte	W01
	.byte		        Dn3 , v092
	.byte	W01
	.byte	W01
	.byte		        Dn3 , v088
	.byte	W01
	.byte	W01
	.byte		        Dn3 , v084
	.byte	W01
	.byte	W01
	.byte		        Dn3 , v080
	.byte	W01
	.byte	W01
	.byte		        Dn3 , v092
	.byte	W01
	.byte	W01
	.byte		        Dn3 , v088
	.byte	W01
	.byte	W01
	.byte		N32   , Dn3 , v080, gtp2
	.byte	W32
	.byte	W02
	.byte	W02
	.byte		N02   , En3 , v056
	.byte	W02
	.byte	W01
	.byte		        En3 , v052
	.byte	W02
	.byte	W01
	.byte		N02   
	.byte	W02
	.byte	W01
	.byte		N02   
	.byte	W02
	.byte	W01
	.byte		N01   , En3 , v060
	.byte	W01
	.byte	W01
	.byte		N01   
	.byte	W01
	.byte	W01
	.byte		        En3 , v064
	.byte	W01
	.byte	W01
	.byte		        En3 , v060
	.byte	W01
	.byte	W01
	.byte		        En3 , v072
	.byte	W01
	.byte	W01
	.byte		        En3 , v068
	.byte	W01
	.byte	W01
	.byte		        En3 , v072
	.byte	W01
	.byte	W01
	.byte		        En3 , v068
	.byte	W01
	.byte	W01
	.byte		        En3 , v064
	.byte	W01
	.byte	W01
	.byte		        En3 , v060
	.byte	W01
	.byte	W01
	.byte		        En3 , v072
	.byte	W01
	.byte	W01
	.byte		        En3 , v068
	.byte	W01
	.byte	W01
@ 015   ----------------------------------------
	.byte		N02   , Fs3 , v056
	.byte	W02
	.byte	W01
	.byte		        Fs3 , v052
	.byte	W02
	.byte	W01
	.byte		        Fs3 , v044
	.byte	W02
	.byte	W01
	.byte		        Fs3 , v056
	.byte	W02
	.byte	W01
	.byte		        Fs3 , v052
	.byte	W02
	.byte	W01
	.byte		        Fs3 , v060
	.byte	W02
	.byte	W01
	.byte		N01   , Fs3 , v056
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v068
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v064
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v068
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v064
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v056
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v052
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v064
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v060
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v076
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v072
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v068
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v064
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v076
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v072
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v080
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v076
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v072
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v068
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v080
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v076
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v088
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v084
	.byte	W01
	.byte	W01
	.byte		N01   
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v080
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v088
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v084
	.byte	W01
	.byte	W01
	.byte		        Gn3 , v056
	.byte	W01
	.byte	W01
	.byte		        Gn3 , v052
	.byte	W01
	.byte	W01
	.byte		        Gn3 , v048
	.byte	W01
	.byte	W01
	.byte		        Gn3 , v044
	.byte	W01
	.byte	W01
	.byte		        Gn3 , v056
	.byte	W01
	.byte	W01
	.byte		        Gn3 , v052
	.byte	W01
	.byte	W01
	.byte		        Gn3 , v068
	.byte	W01
	.byte	W01
	.byte		        Gn3 , v064
	.byte	W01
	.byte	W01
	.byte		        Gn3 , v060
	.byte	W01
	.byte	W01
	.byte		        Gn3 , v056
	.byte	W01
	.byte	W01
	.byte		        Gn3 , v068
	.byte	W01
	.byte	W01
	.byte		        Gn3 , v064
	.byte	W01
	.byte	W01
@ 016   ----------------------------------------
	.byte		        Gn3 , v072
	.byte	W01
	.byte	W01
	.byte		        Gn3 , v068
	.byte	W01
	.byte	W01
	.byte		        Gn3 , v064
	.byte	W01
	.byte	W01
	.byte		        Gn3 , v060
	.byte	W01
	.byte	W01
	.byte		        Gn3 , v072
	.byte	W01
	.byte	W01
	.byte		        Gn3 , v068
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v064
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v060
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v052
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v048
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v060
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v056
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v072
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v068
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v064
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v060
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v072
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v068
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v080
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v076
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v068
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v064
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v076
	.byte	W01
	.byte	W01
	.byte		        Fs3 , v072
	.byte	W01
	.byte	W01
	.byte		N02   , Dn3 , v056
	.byte	W02
	.byte	W01
	.byte		        Dn3 , v052
	.byte	W02
	.byte	W01
	.byte		        Dn3 , v044
	.byte	W02
	.byte	W01
	.byte		        Dn3 , v056
	.byte	W02
	.byte	W01
	.byte		        Dn3 , v052
	.byte	W02
	.byte	W01
	.byte		        Dn3 , v060
	.byte	W02
	.byte	W01
	.byte		N01   , Dn3 , v056
	.byte	W01
	.byte	W01
	.byte		        Dn3 , v068
	.byte	W01
	.byte	W01
	.byte		        Dn3 , v064
	.byte	W01
	.byte	W01
	.byte		        Dn3 , v068
	.byte	W01
	.byte	W01
	.byte		        Dn3 , v064
	.byte	W01
	.byte	W01
	.byte		        Dn3 , v056
	.byte	W01
	.byte	W01
	.byte		        Dn3 , v052
	.byte	W01
	.byte	W01
	.byte		        Dn3 , v064
	.byte	W01
	.byte	W01
	.byte		        Dn3 , v060
	.byte	W01
	.byte	W01
	.byte		        Dn3 , v076
	.byte	W01
	.byte	W01
	.byte		        Dn3 , v072
	.byte	W01
	.byte	W01
	.byte		        Dn3 , v068
	.byte	W01
	.byte	W01
	.byte		        Dn3 , v064
	.byte	W01
	.byte	W01
	.byte		        Dn3 , v076
	.byte	W01
	.byte	W01
	.byte		        Dn3 , v072
	.byte	W01
	.byte	W01
@ 017   ----------------------------------------
	.byte		        Dn3 , v080
	.byte	W01
	.byte	W01
	.byte		        Dn3 , v076
	.byte	W01
	.byte	W01
	.byte		        Dn3 , v072
	.byte	W01
	.byte	W01
	.byte		        Dn3 , v068
	.byte	W01
	.byte	W01
	.byte		        Dn3 , v080
	.byte	W01
	.byte	W01
	.byte		        Dn3 , v076
	.byte	W01
	.byte	W01
	.byte		        Dn3 , v088
	.byte	W01
	.byte	W01
	.byte		        Dn3 , v084
	.byte	W01
	.byte	W01
	.byte		N01   
	.byte	W01
	.byte	W01
	.byte		        Dn3 , v080
	.byte	W01
	.byte	W01
	.byte		        Dn3 , v088
	.byte	W01
	.byte	W01
	.byte		        Dn3 , v084
	.byte	W01
	.byte	W01
	.byte		        En3 , v056
	.byte	W01
	.byte	W01
	.byte		        En3 , v052
	.byte	W01
	.byte	W01
	.byte		        En3 , v048
	.byte	W01
	.byte	W01
	.byte		        En3 , v044
	.byte	W01
	.byte	W01
	.byte		        En3 , v056
	.byte	W01
	.byte	W01
	.byte		        En3 , v052
	.byte	W01
	.byte	W01
	.byte		        En3 , v068
	.byte	W01
	.byte	W01
	.byte		        En3 , v064
	.byte	W01
	.byte	W01
	.byte		        En3 , v060
	.byte	W01
	.byte	W01
	.byte		        En3 , v056
	.byte	W01
	.byte	W01
	.byte		        En3 , v068
	.byte	W01
	.byte	W01
	.byte		        En3 , v064
	.byte	W01
	.byte	W01
	.byte		        En3 , v072
	.byte	W01
	.byte	W01
	.byte		        En3 , v068
	.byte	W01
	.byte	W01
	.byte		        En3 , v064
	.byte	W01
	.byte	W01
	.byte		        En3 , v060
	.byte	W01
	.byte	W01
	.byte		        En3 , v072
	.byte	W01
	.byte	W01
	.byte		        En3 , v068
	.byte	W01
	.byte	W01
	.byte		        Dn3 , v056
	.byte	W01
	.byte	W01
	.byte		        Dn3 , v052
	.byte	W01
	.byte	W01
	.byte		        Dn3 , v048
	.byte	W01
	.byte	W01
	.byte		        Dn3 , v044
	.byte	W01
	.byte	W01
	.byte		        Dn3 , v056
	.byte	W01
	.byte	W01
	.byte		        Dn3 , v052
	.byte	W01
	.byte	W01
	.byte		        Dn3 , v068
	.byte	W01
	.byte	W01
	.byte		        Dn3 , v064
	.byte	W01
	.byte	W01
	.byte		        Dn3 , v060
	.byte	W01
	.byte	W01
	.byte		        Dn3 , v056
	.byte	W01
	.byte	W01
	.byte		        Dn3 , v068
	.byte	W01
	.byte	W01
	.byte		        Dn3 , v064
	.byte	W01
	.byte	W01
	.byte		        Dn3 , v072
	.byte	W01
	.byte	W01
	.byte		        Dn3 , v068
	.byte	W01
	.byte	W01
	.byte		        Dn3 , v064
	.byte	W01
	.byte	W01
	.byte		        Dn3 , v060
	.byte	W01
	.byte	W01
	.byte		        Dn3 , v072
	.byte	W01
	.byte	W01
	.byte		        Dn3 , v068
	.byte	W01
	.byte	GOTO
	 .word	mus_littleroot_7_B1
mus_littleroot_7_B2:
	.byte	FINE

@******************************************************@
	.align	2

mus_littleroot:
	.byte	7	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_littleroot_pri	@ Priority
	.byte	mus_littleroot_rev	@ Reverb.

	.word	mus_littleroot_grp

	.word	mus_littleroot_1
	.word	mus_littleroot_2
	.word	mus_littleroot_3
	.word	mus_littleroot_4
	.word	mus_littleroot_5
	.word	mus_littleroot_6
	.word	mus_littleroot_7

	.end
