/*******************************************************************************
*                                                                              *
* search.h -- Nirvana Editor Search Header File                                *
*                                                                              *
* Copyright 2003 The NEdit Developers                                          *
*                                                                              *
* This is free software; you can redistribute it and/or modify it under the    *
* terms of the GNU General Public License as published by the Free Software    *
* Foundation; either version 2 of the License, or (at your option) any later   *
* version. In addition, you may distribute versions of this program linked to  *
* Motif or Open Motif. See README for details.                                 *
*                                                                              *
* This software is distributed in the hope that it will be useful, but WITHOUT *
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or        *
* FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for    *
* more details.                                                                *
*                                                                              *
* You should have received a copy of the GNU General Public License along with *
* software; if not, write to the Free Software Foundation, Inc., 59 Temple     *
* Place, Suite 330, Boston, MA  02111-1307 USA                                 *
*                                                                              *
* Nirvana Text Editor                                                          *
* July 31, 2001                                                                *
*                                                                              *
*******************************************************************************/

#ifndef SEARCH_H_
#define SEARCH_H_

#include "SearchDirection.h"
#include "SearchType.h"
#include "WrapMode.h"
#include "util/string_view.h"
#include <QString>

class DocumentWidget;
class MainWindow;
class TextArea;

constexpr int MAX_SEARCH_HISTORY = 100; // Maximum length of search string history

bool ReplaceAllEx(MainWindow *window, DocumentWidget *document, TextArea *area, const QString &searchString, const QString &replaceString, SearchType searchType);
bool ReplaceAndSearchEx(MainWindow *window, DocumentWidget *document, TextArea *area, SearchDirection direction, const QString &searchString, const QString &replaceString, SearchType searchType, WrapMode searchWrap);
bool ReplaceFindSameEx(MainWindow *window, DocumentWidget *document, TextArea *area, SearchDirection direction, WrapMode searchWrap);
bool ReplaceSameEx(MainWindow *window, DocumentWidget *document, TextArea *area, SearchDirection direction, WrapMode searchWrap);
bool SearchAndReplaceEx(MainWindow *window, DocumentWidget *document, TextArea *area, SearchDirection direction, const QString &searchString, const QString &replaceString, SearchType searchType, WrapMode searchWrap);
bool SearchAndSelectIncrementalEx(MainWindow *window, DocumentWidget *document, TextArea *area, SearchDirection direction, const QString &searchString, SearchType searchType, WrapMode searchWrap, bool continued);
bool SearchAndSelectSameEx(MainWindow *window, DocumentWidget *document, TextArea *area, SearchDirection direction, WrapMode searchWrap);
bool SearchAndSelectEx(MainWindow *window, DocumentWidget *document, TextArea *area, SearchDirection direction, const QString &searchString, SearchType searchType, WrapMode searchWrap);
bool SearchString(view::string_view string, const QString &searchString, SearchDirection direction, SearchType searchType, WrapMode wrap, int beginPos, int *startPos, int *endPos, int *searchExtentBW, int *searchExtentFW, const char *delimiters);
bool SearchWindowEx(MainWindow *window, DocumentWidget *document, SearchDirection direction, const QString &searchString, SearchType searchType, WrapMode searchWrap, int beginPos, int *startPos, int *endPos, int *extentBW, int *extentFW);
std::string ReplaceAllInStringEx(view::string_view inString, const QString &searchString, const char *replaceString, SearchType searchType, int *copyStart, int *copyEnd, const char *delimiters, bool *ok);
void DoFindDlogEx(MainWindow *window, DocumentWidget *document, SearchDirection direction, int keepDialogs, SearchType searchType);
void DoFindReplaceDlogEx(MainWindow *window, DocumentWidget *document, TextArea *area, SearchDirection direction, int keepDialogs, SearchType searchType);
void FlashMatchingEx(DocumentWidget *document, TextArea *area);
void ReplaceInSelectionEx(MainWindow *window, DocumentWidget *document, TextArea *area, const QString &searchString, const QString &replaceString, SearchType searchType);
void SearchForSelectedEx(MainWindow *window, DocumentWidget *document, TextArea *area, SearchDirection direction, SearchType searchType, WrapMode searchWrap);

void eraseFlashEx(DocumentWidget *document);


/* Default scope if selection exists when replace dialog pops up.
   "Smart" means "In Selection" if the selection spans more than
   one line; "In Window" otherwise. */
enum ReplaceAllDefaultScope {
    REPL_DEF_SCOPE_WINDOW,
    REPL_DEF_SCOPE_SELECTION,
    REPL_DEF_SCOPE_SMART
};

/*
** History of search actions.
*/
struct SelectionInfo {
	bool done;
    DocumentWidget *window;
	char *selection;
};

// NOTE(eteran): temporarily exposing these publically
int countWritableWindows();
int historyIndex(int nCycles);
bool isRegexType(SearchType searchType);
void saveSearchHistory(const QString &searchString, QString replaceString, SearchType searchType, bool isIncremental);
int defaultRegexFlags(SearchType searchType);

struct SearchReplaceHistoryEntry {
    QString    search;
    QString    replace;
    SearchType type;
};

extern int NHist;
extern SearchReplaceHistoryEntry SearchReplaceHistory[MAX_SEARCH_HISTORY];

#endif
