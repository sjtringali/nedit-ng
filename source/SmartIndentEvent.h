
#ifndef SMARTINDENTCBSTRUCT_H_
#define SMARTINDENTCBSTRUCT_H_

#include "string_view.h"

enum SmartIndentCallbackReasons {
	NEWLINE_INDENT_NEEDED, 
	CHAR_TYPED
};

struct SmartIndentEvent {
	SmartIndentCallbackReasons reason;
	int                        pos;
	int                        indentRequest;
	view::string_view          charsTyped;
};

#endif