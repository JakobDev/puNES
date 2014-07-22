/*
 * menu_file.c
 *
 *  Created on: 16/dic/2011
 *      Author: fhorse
 */

#include <libgen.h>
#include <string.h>
#include "menu_file.h"
#include "recent_roms.h"
#include "uncompress.h"
#include "info.h"

#if defined (__SUNPRO_C)
#pragma align 4 (open_icon_inline)
#endif
#if defined (__GNUC__)
static const guint8 open_icon_inline[] __attribute__ ((__aligned__ (4))) =
#else
static const guint8 open_icon_inline[] =
#endif
{ ""
  /* Pixbuf magic (0x47646b50) */
  "GdkP"
  /* length: header (24) + pixel_data (676) */
  "\0\0\2\274"
  /* pixdata_type (0x2010002) */
  "\2\1\0\2"
  /* rowstride (64) */
  "\0\0\0@"
  /* width (16) */
  "\0\0\0\20"
  /* height (16) */
  "\0\0\0\20"
  /* pixel_data: */
  "\221\377\377\377\0\1\200\200\200\4\204\200\200`\10\1UUU\3\211\377\377"
  "\377\0\2txbuvye\371\203wzf\374\3wyf\374vye\360rtd\\\210\377\377\377\0"
  "\1uxc\364\202\265\267\250\377\6\263\265\246\377\262\264\244\377\260\262"
  "\241\377\252\254\233\377y|g\365sxd3\207\377\377\377\0\2svc\373\262\264"
  "\244\377\204\220\223|\377\3\236\241\215\377\236\240\217\376vye\373\203"
  "twc\377\6twd\377tvc\377uxc\367sxdspr^\373\250\252\231\377\202\220\223"
  "|\377\2z|m\377WYU\377\206UWS\377\6WYU\377\201\203v\377\226\230\204\377"
  "os`\367ln[\373\224\227\204\377\202\204\207q\377\2WYU\377\373\373\373"
  "\377\206\377\377\377\377\6\373\373\373\377WYU\377\211\214v\377kn[\377"
  "giW\373}\177m\377\202wye\377\2UWS\377\377\377\377\377\206\272\275\266"
  "\377\5\377\377\377\377UWS\377wye\377gjX\377deT\373\203jkY\377\2UWS\377"
  "\377\377\377\377\206\356\356\354\377\5\377\377\377\377UWS\377jkY\377"
  "dfU\377_aP\373\203ggV\377\3UWS\377\377\377\377\377\272\275\266\377\205"
  "\270\273\263\377\5\373\373\372\377VXS\377ggW\377`bQ\377[\\M\373\203g"
  "gV\377\3XZU\377\255\257\242\377y|i\377\203x{g\377\203wzf\377\202uxd\377"
  "\2rta\377fiW\375\203lo\\\377>ps`\377\240\241\221\377\277\277\263\377"
  "\304\305\271\377\303\304\270\377\302\303\267\377\301\301\266\377\300"
  "\300\265\377\277\277\264\377\275\276\262\377\271\271\255\377jlZ\377a"
  "cR\377\277\301\263\377\304\305\270\377\302\303\266\377\301\301\264\377"
  "\267\271\252\377\253\255\234\377\247\250\226\377\246\250\226\377\244"
  "\246\224\377\244\245\224\377\243\245\223\377\241\243\222\377\241\242"
  "\221\377\263\265\250\377abR\377WXJ\377\303\305\270\377\270\272\253\377"
  "\271\272\252\377\270\272\253\377\267\270\251\377\266\270\251\377\267"
  "\267\251\377\264\266\247\377\263\265\246\377\262\263\244\377\260\261"
  "\243\377\257\261\242\377\254\256\240\377\260\261\243\377WXJ\377RRE\375"
  "\233\233\210\377\254\254\232\377\255\255\233\377\256\256\234\377\257"
  "\257\236\377\260\260\237\377\261\261\241\377\257\257\237\377\255\255"
  "\234\377\252\252\231\377\247\247\227\377\245\245\223\377\242\242\220"
  "\377\214\214z\377QQC\376NN@oNNB\365\214JJ>\377\2NNB\365MM@p"};

#if defined (__SUNPRO_C)
#pragma align 4 (recent_roms_icon)
#endif
#if defined (__GNUC__)
static const guint8 recent_roms_icon[] __attribute__ ((__aligned__ (4))) =
#else
static const guint8 recent_roms_icon[] =
#endif
{ ""
  /* Pixbuf magic (0x47646b50) */
  "GdkP"
  /* length: header (24) + pixel_data (711) */
  "\0\0\2\337"
  /* pixdata_type (0x2010002) */
  "\2\1\0\2"
  /* rowstride (64) */
  "\0\0\0@"
  /* width (16) */
  "\0\0\0\20"
  /* height (16) */
  "\0\0\0\20"
  /* pixel_data: */
  "\203\377\377\377\0\1\364\2404\350\204\364\2415\377\5\364\2414\377\365"
  "\2558\377\366\265<\377\366\2579\354\377\377\0\1\206\377\377\377\0\13"
  "\354\223+\377\375\313\201\377\375\312\177\377\375\311}\377\375\313y\377"
  "\374\332c\377\374\341R\377\357\326(\377\347\316\32\377\370\344C\225\377"
  "\353N\32\205\377\377\377\0\2\344\205\40\377\376\331\242\377\202\375\305"
  "r\377\7\374\330`\377\374\351O\377\364\337-\377\362\341a\377\362\344w"
  "\377\360\330-\377\373\351O\216\205\377\377\377\0\14\335y\27\377\376\346"
  "\302\377\376\326\234\377\375\331\220\377\366\335@\377\356\326\33\377"
  "\354\325\24\377\374\371\341\377\375\372\347\377\344\312\22\377\344\313"
  "\32\372\345\313\34v\204\377\377\377\0\5\326k\15\377\376\351\315\377\375"
  "\331\250\377\375\336\213\377\347\317\30\377\204\377\377\377\377\3\377"
  "\377\372\377\377\377\377\377\334\300\12\365\204\377\377\377\0\7\317^"
  "\4\377\375\343\302\377\374\314\221\377\374\326|\377\356\327+\377\354"
  "\330K\377\377\377\375\377\202\377\377\377\377\3\377\375\353\377\347\322"
  "E\377\342\310\32\302\204\377\377\377\0\14\317^\4\377\375\333\265\377"
  "\373\277z\377\373\305s\377\373\342V\377\344\311\24\377\374\370\335\377"
  "\377\376\363\377\377\374\350\377\371\361\270\377\337\301\21\374\377\345"
  "K:\204\377\377\377\0\2\317^\3\377\374\321\242\377\202\372\262c\377\10"
  "\373\317X\377\337\304\23\377\377\377\377\377\360\341y\377\361\341z\377"
  "\377\377\377\377\331\273\11\371\377\377\0\1\204\377\377\377\0\2\317^"
  "\3\377\373\305\215\377\202\371\244L\377\7\370\251L\377\346\301%\377\334"
  "\275\13\377\346\313&\377\342\303\37\377\330\271\10\372\330\275\21\245"
  "\205\377\377\377\0\2\317^\3\377\372\270v\377\204\370\2275\377\4\370\247"
  ":\377\373\313r\377\331z\22\377\377\377U\3\206\377\377\377\0\2\316]\2"
  "\377\371\252\\\377\205\367\212\36\377\2\372\261h\377\317^\3\377\207\377"
  "\377\377\0\11\316]\2\377\367\233@\377\365}\7\377\366\216(\377\367\235"
  "D\377\366\217*\377\365}\7\377\370\242N\377\317^\3\377\207\377\377\377"
  "\0\11\316]\2\377\367\221.\377\366\210\34\377\357\210(\377\325f\11\364"
  "\357\212,\377\366\213\"\377\367\231=\377\316]\2\377\207\377\377\377\0"
  "\11\316]\1\377\366\213#\377\356\202\35\377\320^\2\363\315[\0p\320^\2"
  "\363\357\206%\377\367\2232\377\316]\2\377\207\377\377\377\0\11\316\\"
  "\1\377\355|\21\377\320^\1\363\314^\0<\377\377\377\0\314^\0<\320^\2\363"
  "\356\202\35\377\316]\1\377\207\377\377\377\0\3\317\\\0\350\317]\1\365"
  "\314^\0<\203\377\377\377\0\3\314^\0<\317^\2\365\317\\\0\350\204\377\377"
  "\377\0"};

#if defined (__SUNPRO_C)
#pragma align 4 (quit_icon_inline)
#endif
#if defined (__GNUC__)
static const guint8 quit_icon_inline[] __attribute__ ((__aligned__ (4))) =
#else
static const guint8 quit_icon_inline[] =
#endif
{ ""
  /* Pixbuf magic (0x47646b50) */
  "GdkP"
  /* length: header (24) + pixel_data (920) */
  "\0\0\3\260"
  /* pixdata_type (0x2010002) */
  "\2\1\0\2"
  /* rowstride (64) */
  "\0\0\0@"
  /* width (16) */
  "\0\0\0\20"
  /* height (16) */
  "\0\0\0\20"
  /* pixel_data: */
  "\1Z\\X\205\206UWS\377\3WYU\377\\^Z\377dfc\377\202hjg\377\16fgd\377`b"
  "^\377`b^\207\377\377\377\1UWS\377\244\244\244\377\204\204\204\377yyy"
  "\377ooo\377ggg\377aaa\377ccc\377\361\361\357\377\364\364\363\377\202"
  "\366\366\365\377\16\365\365\364\377\351\351\350\377cea\377\377\377\377"
  "\3UWS\377\256\256\256\377\214\214\214\377\201\201\201\377www\377ooo\377"
  "jjj\377nnn\377\363\363\362\377\370\370\370\377\202\373\373\373\377\77"
  "\371\371\371\377\365\365\364\377lnk\377\377\377\377\5UWS\377\272\272"
  "\272\377\230\230\230\377\214\214\214\377\202\202\202\377yyy\377sss\377"
  "xxx\377\337\264\262\377\264..\377\264//\377\355\317\317\377\373\373\372"
  "\377\366\366\365\377oqm\377\377\377\377\5UWS\377\274\274\274\377\236"
  "\236\236\377\225\225\225\377\214\214\214\377\202\202\202\377|||\377\203"
  "oo\377\253\20\16\377\353j-\377\347`)\377\264-,\377\373\373\372\377\366"
  "\366\365\377oqm\377\377\377\377\6UWS\377\276\276\276\377\240\240\240"
  "\377\230\230\230\377\217\217\217\377\207\207\207\377\200\177\177\377"
  "\233\"\"\377\331I\37\377\356c+\377\345T%\377\271;:\377\373\373\372\377"
  "\366\366\365\377pqn\377\377\377\377\6UWS\377\277\277\277\377\243\243"
  "\243\377\232\232\232\377\222\222\222\377\211\211\211\377\217LL\377\274"
  "\34\14\377\360v.\377\335\34\25\377\260\4\4\377\203\244\0\0\377\14\234"
  "\22\21\377\255\27\27""8UWS\377\277\277\277\377\245\245\245\377\234\234"
  "\234\377\224\224\224\377\216zz\377\244\7\7\377\351i(\377\3372\27\377"
  "\3373\30\377\204\361~/\377\14\340U\40\377\243\1\1\313UWS\377\277\277"
  "\277\377\247\247\247\377\237\237\237\377\226\226\226\377\220}}\377\235"
  "\10\7\377\325.\22\377\320\5\5\377\325\33\14\377\203\320\5\5\377\16\321"
  "\7\6\377\316-\21\377\236\3\3\277UWS\377\277\277\277\377\252\252\252\377"
  "\241\241\241\377\231\231\231\377\220\220\220\377\216QQ\377\242\3\3\377"
  "\320\17\15\377\353r+\377\257\35\14\377\203\225\0\0\377;\214\32\31\377"
  "\236\24\24\77UWS\377\277\277\277\377\253\253\253\377\243\243\243\377"
  "\233\233\233\377\222\222\222\377\214\213\213\377\217&&\377\273!!\377"
  "\350W<\377\352x8\377\236&&\377\366\367\366\377\356\356\355\377pqn\377"
  "\377\377\377\6UWS\377\277\277\277\377\253\253\253\377\246\246\246\377"
  "\236\236\236\377\230\230\230\377\225\225\225\377\221\201\201\377\213"
  "\13\13\377\331TP\377\335hG\377\23777\377\361\361\357\377\347\350\345"
  "\377mok\377\377\377\377\5UWS\377\277\277\277\377\254\254\254\377\252"
  "\252\252\377\246\246\246\377\242\242\242\377\177\177\177\377\233\234"
  "\233\377\306\253\251\377\22500\377\232<;\377\320\264\262\377\345\346"
  "\344\377\335\336\333\377gie\377\377\377\377\3VXT\377\300\300\300\377"
  "\256\256\256\377\264\264\263\377\215\215\215\377\226\227\224\377\314"
  "\316\311\377\327\331\325\377\330\332\326\377\203\331\333\327\377\13\326"
  "\330\324\377\320\323\316\377`b^\377\377\377\377\3WYU\377\306\306\306"
  "\377\233\233\232\377\225\227\224\377\301\304\277\377\306\311\303\377"
  "\306\311\304\377\205\307\311\304\377\6\306\310\303\377\302\305\277\377"
  "Y[W\377\377\377\377\1""554\247klj\377\202XZV\377\211Y[W\377\3WYU\377"
  "\\^Z\205\377\377\377\0"};

#if defined (__SUNPRO_C)
#pragma align 4 (recent_roms_nes_pixbuf)
#endif
#if defined (__GNUC__)
static const guint8 recent_roms_nes_pixbuf[] __attribute__ ((__aligned__ (4))) =
#else
static const guint8 recent_roms_nes_pixbuf[] =
#endif
{ ""
  /* Pixbuf magic (0x47646b50) */
  "GdkP"
  /* length: header (24) + pixel_data (706) */
  "\0\0\2\332"
  /* pixdata_type (0x2010002) */
  "\2\1\0\2"
  /* rowstride (64) */
  "\0\0\0@"
  /* width (16) */
  "\0\0\0\20"
  /* height (16) */
  "\0\0\0\20"
  /* pixel_data: */
  "\213\377\377\377\0\2SXS4UUU0\210\377\377\377\0\2@@@\4UUU\3\204\377\377"
  "\377\0\2VVSMTXT:\207\377\377\377\0\5XXP\40UWS\255UWS\270UWS\207UUU$\202"
  "\377\377\377\0\3UUU\33VXT\200UUU'\206\377\377\377\0\13UWS\212TWTjUUU"
  "\3TWTRUWS\257VXT}UUU\25\377\377\377\0UUU!TVS\216R[R\34\205\377\377\377"
  "\0\13UWS\234VXT\206\0\0\0\1\377\377\377\0UUU\11UXSfUWS\271UXRZ@@@\4U"
  "WSuUUQ<\205\377\377\377\0\4XXO\35UXR\306UWS\266PPP\20\202\377\377\377"
  "\0\5R[R\34TXS\227UWS\302UWS\273SSS(\206\377\377\377\0\4@@@\4TVS\216U"
  "WS\331UUU$\203\377\377\377\0\2QQQ\26XXN\32\211\377\377\377\0\2VXTzUV"
  "T\267\210\377\377\377\0\3\205\217\205\31\212\214\207\220\217\222\215"
  "\313\203\217\222\215\320\2\215\220\213\327\206\210\203\371\203\217\222"
  "\215\320\10\217\222\215\313\211\214\207j\200\200\200\2\377\377\377\0"
  "\211\211\211\32\214\216\211\354\267\270\264\372\322\322\317\377\202\324"
  "\325\322\377\4\301\306\312\377\306\311\314\377\301\306\312\377\320\322"
  "\320\377\202\324\325\322\377\16\320\321\316\377\236\237\233\364\215\217"
  "\213\333\211\211\211\34\211\213\207w\257\260\255\366\324\324\321\377"
  "cea\377\324\324\321\377\356\356\354\377\313\322\332\377\300\312\325\377"
  "\316\325\334\377\342\344\346\377\202\356\356\354\377\11\201\227\266\377"
  "\356\356\354\377\255\256\252\371\214\214\210|\217\221\214\335\325\326"
  "\323\377ac_\377UWS\377ac_\377\206\356\356\354\377\12\335wv\377\356\356"
  "\354\377\236\304y\377\325\325\323\377\216\220\214\333\216\217\211\354"
  "\335\336\333\377\336\336\334\377^`\\\377\336\336\334\377\207\356\356"
  "\354\377\6\331\307v\377\356\356\354\377\335\336\333\377\214\215\211\356"
  "\214\216\210\216\271\272\267\372\203\356\356\354\377\1\331\331\327\377"
  "\204\267\270\264\374\1\333\333\332\377\203\356\356\354\377\11\272\273"
  "\270\373\215\217\212\222\210\210\202+\215\217\211\363\315\316\313\377"
  "\343\343\341\377\320\321\316\377\217\220\213\365\210\212\204\203\202"
  "\210\212\206x\15\211\213\205\210\220\221\213\365\324\325\322\377\346"
  "\346\343\377\321\322\316\377\216\217\213\364\213\213\205.\377\377\377"
  "\0\212\212\206=\217\220\214\317\215\217\212\361\220\223\214\317\212\212"
  "\207S\204\377\377\377\0\6\213\216\211a\217\220\213\330\212\214\207\372"
  "\216\221\214\331\207\213\203D\377\377\377\0"};

#if defined (__SUNPRO_C)
#pragma align 4 (recent_roms_fm2_pixbuf)
#endif
#if defined (__GNUC__)
static const guint8 recent_roms_fm2_pixbuf[] __attribute__ ((__aligned__ (4))) =
#else
static const guint8 recent_roms_fm2_pixbuf[] =
#endif
{ ""
  /* Pixbuf magic (0x47646b50) */
  "GdkP"
  /* length: header (24) + pixel_data (893) */
  "\0\0\3\225"
  /* pixdata_type (0x2010002) */
  "\2\1\0\2"
  /* rowstride (64) */
  "\0\0\0@"
  /* width (16) */
  "\0\0\0\20"
  /* height (16) */
  "\0\0\0\20"
  /* pixel_data: */
  "\3UWS\377\377\377\377\377UWS\377\204\237\274\334\377\5UWS\377\377\377"
  "\377\377J\200\30\377G\211\7p\0\377\0\1\204\377\377\377\0\3[]Y\375UWS"
  "\377[]Y\377\204\312\333\355\377\6UWS\377vwt\377C\207\4\377R\232\16\364"
  "F\214\6\314B\212\7#\203\377\377\377\0\3UWS\377\377\377\377\377UWS\377"
  "\204\365\370\373\377\14UWS\377\377\377\377\377C\207\4\377\210\3413\377"
  "j\272\36\374F\213\6\364G\211\7p\0\377\0\1\377\377\377\0[]Y\375UWS\377"
  "[]Y\377\204\210\212\205\377\14UWS\377\206\207\204\377C\207\4\377\207"
  "\3400\377\211\3413\377\200\325-\377R\232\16\363F\214\6\314B\212\7#UW"
  "S\377\377\377\377\377UWS\377\204\237\274\334\377\14UWS\377\377\377\377"
  "\377C\207\4\377|\330!\377S\233\16\364j\272\37\374\211\3403\377k\273\37"
  "\374D\210\5\363[]Y\375UWS\377[]Y\377\204\312\333\355\377\14UWS\377\226"
  "\230\225\377C\207\4\377s\322\26\377C\207\4\377G\214\6\316T\235\20\363"
  "\211\3413\377C\207\4\377UWS\377\377\377\377\377UWS\377\202\365\370\373"
  "\377N\367\371\374\377\370\372\374\377\224\226\223\377\377\377\377\377"
  "C\207\4\377s\322\26\377C\207\4\377\0\377\0\1C\207\4\377\211\3413\377"
  "C\207\4\377[]Y\375UWS\377[]Y\377\210\212\205\377\243\244\240\377\226"
  "\253\203\377V\222\34\377I\212\15\377D\210\5\377F\213\7\377s\322\26\377"
  "C\207\4\377\377\377\377\0C\207\4\377\177\332%\377C\207\4\377UWS\377\377"
  "\377\377\377UWS\377\237\274\334\377\301\324\350\377P\221\27\377\201\310"
  "=\377\253\341x\377\235\337\\\377{\323&\377s\322\26\377C\207\4\377\377"
  "\377\377\0C\207\4\377t\322\27\377C\207\4\377[]Y\375UWS\377[]Y\377\312"
  "\333\355\377\335\350\363\377R\222\30\377j\275\31\377q\314\32\377s\321"
  "\27\377o\313\24\377d\271\20\377E\213\4\351\377\377\377\0C\207\4\377s"
  "\322\26\377C\207\4\377UWS\377\377\377\377\377UWS\377\365\370\373\377"
  "\367\372\374\377\307\333\270\377^\232'\377I\212\15\377E\211\6\377E\207"
  "\11\377F\214\5\335D\210\4G\377\377\377\0C\207\4\377s\322\26\377C\207"
  "\4\377[]Y\375UWS\377[]Y\377\202\210\212\205\377\5\237\240\234\377\257"
  "\260\255\377\224\225\222\377\210\211\206\377[]Y\375\203\377\377\377\0"
  "\6C\207\4\377s\322\26\377C\207\4\377UWS\377\377\377\377\377UWS\377\204"
  "\237\274\334\377\14UWS\377\377\377\377\377Pe<\377F\214\5\335D\211\5\362"
  "D\210\4\375F\214\5\371s\322\26\377C\207\4\377[]Y\375UWS\377[]Y\377\204"
  "\312\333\355\377\202UWS\377\12G\207\13\377m\277\36\377\230\332X\377\262"
  "\346\177\377\224\333N\377s\322\26\377C\207\4\377UWS\377\377\377\377\377"
  "UWS\377\204\365\370\373\377\14UWS\377\377\377\377\377G\206\13\377d\272"
  "\20\377p\314\30\377s\321\27\377p\313\26\377d\271\20\377E\213\4\351VW"
  "T\374UWS\377VWT\377\204\210\212\205\377\202UWS\377\7Qe=\375F\213\5\334"
  "D\211\5\362D\210\4\375D\211\5\363F\214\5\335D\210\4G"};

#if defined (__SUNPRO_C)
#pragma align 4 (recent_roms_fds_pixbuf)
#endif
#if defined (__GNUC__)
static const guint8 recent_roms_fds_pixbuf[] __attribute__ ((__aligned__ (4))) =
#else
static const guint8 recent_roms_fds_pixbuf[] =
#endif
{ ""
  /* Pixbuf magic (0x47646b50) */
  "GdkP"
  /* length: header (24) + pixel_data (773) */
  "\0\0\3\35"
  /* pixdata_type (0x2010002) */
  "\2\1\0\2"
  /* rowstride (64) */
  "\0\0\0@"
  /* width (16) */
  "\0\0\0\20"
  /* height (16) */
  "\0\0\0\20"
  /* pixel_data: */
  "\3LNK\223KMI\373IKG\377\2125f\244\377\6""341\377120\373/1/\221IKG\374"
  "\214\216\214\377\216\220\216\377\212\227\270\333\377\7wzy\377nrq\377"
  ",-+\373FHD\377\216\217\215\377MOM\377\376\376\377\377\210\363\363\363"
  "\377\10\376\376\377\377@DD\377qtt\377)*(\377BDA\377\214\216\214\377N"
  "QN\377\377\377\377\377\210\342\342\342\377\10\377\377\377\377BFE\377"
  "psr\377$%#\377\77@=\377\212\214\211\377PSO\377\377\377\377\377\205\370"
  "\370\370\377\203\371\371\370\377\10\377\377\377\377DHF\377nqp\377!\""
  "\40\377<=:\377\210\211\207\377RTQ\377\377\377\377\377\210\342\342\342"
  "\377\10\377\377\377\377FJH\377lpn\377\35\36\35\377897\377\206\210\205"
  "\377TVR\377\377\377\377\377\204\375\375\374\377\204\375\375\375\377\10"
  "\377\377\377\377HKI\377jmk\377\32\33\31\377563\377\203\204\202\377UW"
  "S\377\370\370\370\377\210\377\377\377\377\6\370\370\370\377JMK\377hk"
  "i\377\26\27\26\377120\377\200\201~\377\204UWS\3770SVR\377RUQ\377QSP\377"
  "PSO\377ORN\377NQN\377MPM\377LOL\377gjg\377\23\24\23\377./-\377}\177{"
  "\377UWS\377\177\201|\377\233\236\230\377\231\234\226\377\226\231\223"
  "\377\223\225\220\377\220\222\215\377\215\217\211\377\212\215\207\377"
  "\177\202~\377rsq\377beb\377ege\377\17\20\17\377*+)\377z{x\377UWS\377"
  "\224\226\221\377\325\331\322\377\340\343\336\377\347\351\345\377\355"
  "\356\354\377\350\351\346\377\343\344\341\377\331\333\327\377|~y\377Q"
  "SP\377rur\377cec\377\14\14\14\377'(&\377wyu\377UWS\377\210\213\205\377"
  "\330\333\325\377\310\314\303\377\202VXT\377\16\312\315\307\377\300\304"
  "\274\377\326\330\324\377orm\377RUQ\377tvs\377bea\377\10\11\10\377#$\""
  "\377tur\377UWS\377}\177z\377\327\332\324\377\320\324\314\377\202UWS\377"
  "\16\304\310\301\377\272\276\266\377\324\327\322\377cfa\377TVR\377uwt"
  "\377`b_\377\5\5\5\377!!\40\372ab_\377dfc\377qto\377\330\333\325\377\331"
  "\333\326\377\202UWS\377\35\276\302\273\377\273\277\267\377\324\326\322"
  "\377XZV\377UWS\377wyu\377_a]\377\2\2\2\377\35\35\32P\37\40\36\364Z\\"
  "X\377fhd\377\333\335\327\377\336\340\334\377\325\327\322\377\314\317"
  "\311\377\303\307\301\377\313\316\311\377\325\326\322\377UWS\377_a]\377"
  "~\200|\377XYV\377\1\1\1\373\0\0\0\0\26\26\26F\26\26\25\367Z\\X\377WY"
  "U\377\207UWS\377\4\1\1\1\377\0\0\0\377\1\1\1\375\5\5\5\221"};

void menu_file_recent_roms_activate(gint index);

static GtkWidget *recent;

void menu_file(GtkWidget *mainmenu, GtkAccelGroup *accel_group) {
	GtkWidget *menu, *file, *open, *quit;

	menu = gtk_menu_new();
	file = gtk_menu_item_new_with_mnemonic("_File");

	/* append menu file to main menu */
	gtk_menu_shell_append(GTK_MENU_SHELL(mainmenu), file);
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(file), menu);

	open = gtk_image_menu_item_new_with_mnemonic("_Open");
	recent = gtk_image_menu_item_new_with_label("Recent Roms");
	quit = gtk_image_menu_item_new_with_mnemonic("E_xit");

	/* icons */
	gw_image_from_inline(open, open_icon_inline);
	gw_image_from_inline(recent, recent_roms_icon);
	gw_image_from_inline(quit, quit_icon_inline);

	/* accelerators */
	gtk_widget_add_accelerator(open, "activate", accel_group, GDK_o, GDK_CONTROL_MASK,
			GTK_ACCEL_VISIBLE);
	gtk_widget_add_accelerator(quit, "activate", accel_group, GDK_q, GDK_CONTROL_MASK,
			GTK_ACCEL_VISIBLE);

	/* append menu shell */
	gtk_menu_shell_append(GTK_MENU_SHELL(menu), open);
	gtk_menu_shell_append(GTK_MENU_SHELL(menu), recent);
	gtk_menu_shell_append(GTK_MENU_SHELL(menu), gtk_separator_menu_item_new());
	gtk_menu_shell_append(GTK_MENU_SHELL(menu), quit);

	/* signals */
	g_signal_connect(G_OBJECT(open), "activate", G_CALLBACK(file_open), NULL);
	g_signal_connect(G_OBJECT(quit), "activate", G_CALLBACK(main_win_delete_event), NULL);
}
void menu_file_check(void) {
	GtkWidget *submenu;

	gtk_widget_hide_all(recent);

	gtk_menu_item_set_submenu(GTK_MENU_ITEM(recent), NULL);

	if (recent_roms_list.count > 0) {
		gint index;

		submenu = gtk_menu_new();
		gtk_menu_item_set_submenu(GTK_MENU_ITEM(recent), submenu);

		for (index = 0; index < RECENT_ROMS_MAX; index++) {
			GtkWidget *slot;
			char description[RECENT_ROMS_LINE], *ext;

			if (recent_roms_list.item[index][0] == 0) {
				break;
			}

			sprintf(description, "%s", basename(recent_roms_list.item[index]));
			slot = gtk_image_menu_item_new_with_label(description);

			ext = strrchr(description, '.');
			if (ext == NULL) {
				gw_image_from_inline(slot, recent_roms_nes_pixbuf);
			} else if (!(strcasecmp(ext, ".fds")) || !(strcasecmp(ext, ".FDS"))) {
				gw_image_from_inline(slot, recent_roms_fds_pixbuf);
			} else if (!(strcasecmp(ext, ".fm2")) || !(strcasecmp(ext, ".FM2"))) {
				gw_image_from_inline(slot, recent_roms_fm2_pixbuf);
			} else {
				gw_image_from_inline(slot, recent_roms_nes_pixbuf);
			}

			gtk_menu_shell_append(GTK_MENU_SHELL(submenu), slot);

			g_signal_connect_swapped(G_OBJECT(slot), "activate",
			        G_CALLBACK(menu_file_recent_roms_activate), GINT_TO_POINTER(index));
		}
	}

	gtk_widget_show_all(recent);
}

void menu_file_recent_roms_activate(gint index) {
	emu_pause(TRUE);

	if (strncmp(recent_roms_list.current, recent_roms_list.item[index],
	        RECENT_ROMS_LINE) != 0) {
		change_rom(recent_roms_list.item[index]);
	} else {
		/* se l'archivio e' compresso e contiene piu' di una rom allora lo carico */
		if ((info.uncompress_rom == TRUE) && (uncomp.files_founded > 1)) {
			change_rom(recent_roms_list.item[index]);
		}
	}

	emu_pause(FALSE);
}
