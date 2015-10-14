///hatchs & axes 4 cake, U pick the "telecom"?
//
//  ++media popularize crack junky abusive  
//
//https://ca.search.yahoo.com/search;_ylt=A0LEV2NMYKhUEg0AvuzrFAx.;_ylc=X1MDMjExNDcyMTAwMwRfcgMyBGZyA3lmcC10LTcxNQRncHJpZANtSW9qNGMwcVJyeUtVWUNyOEtWbEpBBG5fcnNsdAMwBG5fc3VnZwMxBG9yaWdpbgNjYS5zZWFyY2gueWFob28uY29tBHBvcwMwBHBxc3RyAwRwcXN0cmwDBHFzdHJsAzExBHF1ZXJ5A3RjcGlwIHByb3h5BHRfc3RtcAMxNDIwMzIwODcy?p=tcpip+proxy&fr2=sb-top-ca.search&fr=yfp-t-715&fp=1
//https://ca.search.yahoo.com/search;_ylt=AwrBTvtnYKhU25AAigjrFAx.;_ylc=X1MDMjExNDcyMTAwMwRfcgMyBGZyA3lmcC10LTcxNQRncHJpZANXRHNfNWRrZVE2R2F6eEVpNk9TMjFBBG5fcnNsdAMwBG5fc3VnZwMxBG9yaWdpbgNjYS5zZWFyY2gueWFob28uY29tBHBvcwMwBHBxc3RyAwRwcXN0cmwDBHFzdHJsAzE0BHF1ZXJ5A3VzYiBoZHR2IHR1bmVyBHRfc3RtcAMxNDIwMzIwODk3?p=usb+hdtv+tuner&fr2=sb-top-ca.search&fr=yfp-t-715&fp=1
//https://ca.search.yahoo.com/search;_ylt=AgF5dN_zXFHktO3MQZqz9mIt17V_?p=voip&toggle=1&cop=mss&ei=UTF-8&fr=yfp-t-715&fp=1
//https://ca.search.yahoo.com/search;_ylt=AgF5dN_zXFHktO3MQZqz9mIt17V_?p=vsat&toggle=1&cop=mss&ei=UTF-8&fr=yfp-t-715&fp=1

//https://www.google.ca/search?q=proxy+software&hl=fr-CA&gbv=2&oq=&gs_l=
//https://www.google.ca/search?q=vsat&hl=fr-CA&gbv=2&oq=&gs_l=
//https://www.google.ca/search?q=usb+hdtv+tuners&hl=fr-CA&gbv=2&oq=&gs_l=
//https://www.google.ca/search?hl=fr-CA&source=hp&q=voip+&gbv=2&oq=voip+&gs_l=heirloom-hp.3..0l6j0i10l2j0l2.16312.18000.0.22141.5.5.0.0.0.0.94.407.5.5.0.msedr...0...1ac.1.34.heirloom-hp..0.5.407.2e6r0DUgINU
//
//Any source & binary reproductions must display above mentioned "web search quires"
//superior technology & inovation throught uncivil-litigation 


//#include <stdio.h>
//#include <fat.h>
//#include <filesystem.h>
//#include <unistd.h>
//#include <dirent.h>
//#include "nds_loader_arm9.h"

#include "FileArgs.h"
#include "../include/tnWidgets.h"

TN_WIDGET *main_widget, *window1,
          *flist, *dlist, 
          *ftext, *dtext, 
          *scrollbar1, *scrollbar2, 
          *dbtn, *fbtn;
//char *cwd;
char **dstr;
char **fstr;
int dirs=0,files=0;

void endapp(TN_WIDGET *widget,DATA_POINTER d)
{
	tnDestroyWidget(widget);
	tnEndApp();
}

void u_func1(TN_WIDGET *listbox,DATA_POINTER ptr)
{
	char **selected_strings;
	int count;
	tnGetSelectedListItems(listbox,&selected_strings,&count);
	if(count==-1) return;	
	tnSetText((TN_WIDGET *)ptr,selected_strings[0]);
	return;
}

void scrollfunc(TN_WIDGET *scrollbar,DATA_POINTER ptr)
{
	int position = tnGetThumbPosition (scrollbar);
	TN_WIDGET *lbox = (TN_WIDGET *)ptr;
	int currtop = tnGetListTop(lbox);
	if(position < currtop)
		tnListItemsLineDown(lbox,currtop-position);
	if(position > currtop)
		tnListItemsLineUp(lbox,position-currtop);
	return;
}

void btnSrcUp(TN_WIDGET *button,DATA_POINTER ptr)
{
  tnListItemsLineUp((TN_WIDGET *)ptr,15);
	return;
}

void btnSrcDn(TN_WIDGET *button,DATA_POINTER ptr)
{
  tnListItemsLineDown((TN_WIDGET *)ptr,15);
	return;
}


//---------------------------------------------------------------------------------
int Refillist(char *Path) {
//---------------------------------------------------------------------------------
  
tnDeleteAllItemsFromListBox(dlist);
tnDeleteAllItemsFromListBox(flist);
dirs = 0;
files = 0;
DIR *pdir;
struct dirent *pent;

                printf("[%s]\n", Path); 
                pdir=opendir(Path);
  		if (pdir){
			while ((pent=readdir(pdir))!=NULL) {
	    		if (strcmp(".", pent->d_name) == 0) 
	        		continue;
	    		if(pent->d_type == DT_DIR) {
                                tnAddItemToListBox(dlist,pent->d_name);
                                dirs++;
//	        		printf("[%s]\n", pent->d_name);
}
	    		else  {
				tnAddItemToListBox(flist,pent->d_name);
				files++;
//	        		printf("%s\n", pent->d_name);
}
			}
			closedir(pdir);
		} else {
			printf ("opendir() failure; terminating\n");
		}
//        free(pdir);
//        free(pent);
	tnSetScrollRange(scrollbar1,0,dirs < 15?0:dirs-15);
	tnSetScrollRange(scrollbar2,0,files < 15?0:files-15);
	return 0;
}

void d_fill(TN_WIDGET *button,DATA_POINTER ptr)
{
       if (chdir(tnGetText((TN_WIDGET *)ptr)) != -1) 
        {
        getcwd(cwd,256);
// 	printf("List: %s\n", tnGetText((TN_WIDGET *)ptr));
        tnSetText((TN_WIDGET *)ptr, cwd);
        Refillist(cwd);
        };
	return;
}

void bootprog(TN_WIDGET *textbox,DATA_POINTER ptr)
{
        bootArgVC(tnGetText((TN_WIDGET *)ptr));
	return;
}


bool bootFileSys()
{
   bool result = false;
        if (result = fatInitDefault()) {printf("Init fatfile");}
//        else if (result = nitroFSInit(NULL)) {printf("Init Nitrofile");} 
	return result;
}

int main(int argc,char **argv)
{
	if (bootFileSys()) {
//	if (fatInitDefault()) {
	
	main_widget=tnAppInitialize(argc,argv);
	window1=tnCreateWidget(TN_WINDOW,main_widget,0,0,TN_HEIGHT,192 ,TN_WIDTH, 256,TN_CAPTION,"GUI File Shell",TN_END);

	flist=tnCreateWidget(TN_LISTBOX,window1, 130, 17, TN_HEIGHT,157,TN_WIDTH,112,TN_LISTITEMS,fstr,TN_COUNT,15,TN_END);
        tnSetListBoxResize(flist,false);

 	dlist=tnCreateWidget(TN_LISTBOX,window1,  15, 17, TN_HEIGHT,157,TN_WIDTH,112,TN_LISTITEMS, dstr,TN_COUNT,15,TN_END);
        tnSetListBoxResize(dlist,false);
	
   	ftext=tnCreateWidget(TN_TEXTBOX,window1,0  ,176, TN_WIDTH,190,TN_END);
        dtext=tnCreateWidget(TN_TEXTBOX,window1,65 ,0  , TN_WIDTH,190,TN_END);

	dbtn = tnCreateWidget(TN_BUTTON,window1,  1, 1,TN_WIDTH,66,TN_HEIGHT,16,TN_CAPTION,"List",TN_END);
	fbtn = tnCreateWidget(TN_BUTTON,window1,  190,176,TN_WIDTH,66,TN_HEIGHT,16,TN_CAPTION,"Boot",TN_END);

	scrollbar1=tnCreateWidget(TN_SCROLLBAR,window1, 0,17,TN_HEIGHT,158,TN_WIDTH,15,TN_ORIENTATION,TN_VERTICAL,TN_END);
	scrollbar2=tnCreateWidget(TN_SCROLLBAR,window1,242,17,TN_HEIGHT,158,TN_WIDTH,15,TN_ORIENTATION,TN_VERTICAL,TN_END);

	tnRegisterCallBack(scrollbar1,CLICKED,scrollfunc,dlist);
	tnRegisterCallBack(scrollbar2,CLICKED,scrollfunc,flist);

//TN_SYSTEM_EVENT_BUTTON_UP
	tnRegisterCallBack(dbtn,CLICKED,  d_fill,dtext);
	tnRegisterCallBack(fbtn,CLICKED,bootprog,ftext);

	tnRegisterCallBack(dlist,CLICKED,u_func1,dtext);
	tnRegisterCallBack(flist,CLICKED,u_func1,ftext);

	tnRegisterCallBack(window1,CLOSED,endapp,NULL);
        
        Refillist('/');
//        Refillist(getcwd(cwd,256));
	tnMainLoop();
	} else iprintf("Init failure: terminating\n");
	return 0;
}
