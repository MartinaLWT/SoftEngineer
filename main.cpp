/*#if defined(UNICODE) && !defined(_UNICODE)
    #define _UNICODE
#elif defined(_UNICODE) && !defined(UNICODE)
    #define UNICODE
#endif*/

#define UNICODE
#define _UNICODE


#include <tchar.h>
#include <windows.h>
#include <string>
#include <iostream>
#include"list.h"
#include"item.h"
#include"item_list.h"
#include"user.h"
#include"hashtable.h"
#include"deal.h"
#include"stack.h"

//#include"deal.cc"
using namespace std;

int page = 1,nameLength,pwLength;
int i,clicked;
int fLoged=0;
TCHAR lpString[128],pOut[128];
//User systemUser(L"system",L"whatthehell");

//TCHAR lpname[128];

Stack<int> pageStack = Stack<int>();

Item itemtest1 = Item(100,L"雀巢酸奶",L"正版雀巢酸奶，保质期至2118年9月，未开封",true,L"system");
Item itemtest2 = Item(100,L"IPHONE666",L"2117年最新款正版IPHONE",true,L"system");
Item itemtest3 = Item(100,L"百事辣椒酱",L"百事辣椒酱，正版！永久质保，未开封",true,L"system");

ListNode<Item> *pointer;
ItemList itemList;
List<Item> beFound;
Item item = Item();
Item *itemCheck;
Item *items[5];
int listPrinted = 0;
int totalfound,totalDeal,totalMyItem;
int itemchosen,dealchosen,myitemchosen;

List<Deal> dealList;
ListNode<Deal> *dealcheck;

HashTable userTable;
wstring name,password,keyword,linked_sentence,linked_mainsentence;
User preUser;
Individual preIndividual;
static int cxchar,cychar;
static HWND hwndForPOne[4];//注册登陆页1
static HWND hwndForPTwo[5];//主页2
static HWND hwndForPThree[7];//搜索商品页3
static HWND hwndForPFour[2];//商品详情页4
static HWND hwndForPFive[7];//个人交易信息页5
static HWND hwndForPSix[7];//个人商品信息页6
static HWND hwndForSeven[1];//交易详情页7


LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);


int WINAPI WinMain (HINSTANCE hThisInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR lpszArgument,
                     int nCmdShow)
{
    HWND hwnd;               /* This is the handle for our window */
    MSG messages;            /* Here messages to the application are saved */
    WNDCLASSEX wincl;        /* Data structure for the windowclass */
    static TCHAR appName[] = TEXT("线鱼");

    /* The Window structure */
    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = appName;
    wincl.lpfnWndProc = WindowProcedure;      /* This function is called by windows */
    wincl.style = CS_VREDRAW | CS_HREDRAW;
    wincl.cbSize = sizeof (WNDCLASSEX);

    /* Use default icon and mouse-pointer */
    wincl.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;                 /* No menu */
    wincl.cbClsExtra = 0;                      /* No extra bytes after the window class */
    wincl.cbWndExtra = 0;                      /* structure or the window instance */
    /* Use Windows's default colour as the background of the window */
    wincl.hbrBackground = (HBRUSH)CreateSolidBrush(RGB(255,194,166));

    /* Register the window class, and if it fails quit the program */
    if (!RegisterClassEx (&wincl))
        return 0;

    /* The class is registered, let's create the program*/
    hwnd = CreateWindowEx (
           0,                   /* Extended possibilites for variation */
           appName,         /* Classname */
           appName,       /* Title Text */
           WS_OVERLAPPEDWINDOW, /* default window */
           CW_USEDEFAULT,       /* Windows decides the position */
           CW_USEDEFAULT,       /* where the window ends up on the screen */
           800,                 /* The programs width */
           600,                 /* and height in pixels */
           HWND_DESKTOP,        /* The window is a child-window to desktop */
           NULL,                /* No menu */
           hThisInstance,       /* Program Instance handler */
           NULL                 /* No Window Creation data */
           );

    /* Make the window visible on the screen */
    ShowWindow (hwnd, nCmdShow);

    itemList.add_item(itemtest1);
    itemList.add_item(itemtest2);
    itemList.add_item(itemtest3);


    /* Run the message loop. It will run until GetMessage() returns 0 */
    while (GetMessage (&messages, NULL, 0, 0))
    {
        /* Translate virtual-key messages into character messages */
        TranslateMessage(&messages);
        /* Send message to WindowProcedure */
        DispatchMessage(&messages);
    }

    /* The program return-value is 0 - The value that PostQuitMessage() gave */
    return messages.wParam;
}


/*  This function is called by the Windows function DispatchMessage()  */

LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    HDC hdc;
    PAINTSTRUCT ps;
    RECT rect,rForDetail;
    setlocale(LC_ALL,"chs");


    switch (message)                  /* handle the messages */
    {

    case WM_CREATE:
        {
            cxchar = LOWORD(GetDialogBaseUnits());
            cychar = HIWORD(GetDialogBaseUnits());
            //Page Login
            hwndForPOne[0] = CreateWindow(TEXT("Button"),TEXT("注册"),//注册按键
                         BS_PUSHBUTTON|WS_CHILD,
                         300,300,
                         70,40,
                         hwnd,(HMENU)0,((LPCREATESTRUCT)lParam)->hInstance,NULL);
            hwndForPOne[1] = CreateWindow(TEXT("Button"),TEXT("登陆"),//登陆按键
                         BS_PUSHBUTTON|WS_CHILD,
                         400,300,
                         70,40,
                         hwnd,(HMENU)1,((LPCREATESTRUCT)lParam)->hInstance,NULL);
            hwndForPOne[2] = CreateWindow(TEXT("Edit"),TEXT("请于此处输入用户名"),//用户名输入窗
                         WS_CHILD,
                         300,200,
                         180,20,
                         hwnd,(HMENU)2,((LPCREATESTRUCT)lParam)->hInstance,NULL);
            hwndForPOne[3] = CreateWindow(TEXT("Edit"),TEXT("请于此处输入密码"),//密码输入窗
                         WS_CHILD,
                         300,250,
                         180,20,
                         hwnd,(HMENU)3,((LPCREATESTRUCT)lParam)->hInstance,NULL);
            hwndForPTwo[0] = CreateWindow(TEXT("Edit"),TEXT("搜索关键词...."),//主页搜索栏
                         WS_CHILD,
                         100,70,
                         500,20,
                         hwnd,(HMENU)4,((LPCREATESTRUCT)lParam)->hInstance,NULL);
            hwndForPTwo[1] = CreateWindow(TEXT("Button"),TEXT("搜索"),//主页搜索按键
                         BS_PUSHBUTTON|WS_CHILD,
                         650,65,
                         70,40,
                         hwnd,(HMENU)5,((LPCREATESTRUCT)lParam)->hInstance,NULL);
            hwndForPTwo[2] = CreateWindow(TEXT("Button"),TEXT("我的交易"),//查看我的交易按键
                         BS_PUSHBUTTON|WS_CHILD,
                         200,400,
                         350,40,
                         hwnd,(HMENU)6,((LPCREATESTRUCT)lParam)->hInstance,NULL);
            hwndForPTwo[3] = CreateWindow(TEXT("Button"),TEXT("我的商品"),//查看我的商品按键
                         BS_PUSHBUTTON|WS_CHILD,
                         200,300,
                         350,40,
                         hwnd,(HMENU)7,((LPCREATESTRUCT)lParam)->hInstance,NULL);
            hwndForPSix[6] = hwndForPThree[6] = hwndForPFive[5] =
            hwndForPFour[1] = hwndForSeven[0] = CreateWindow(TEXT("Button"),TEXT("<="),//后退按键
                         BS_PUSHBUTTON|WS_CHILD,
                         50,500,
                         70,40,
                         hwnd,(HMENU)26,((LPCREATESTRUCT)lParam)->hInstance,NULL);
            for(i=0;i<5;i++)//建立搜索出的商品选项
            {
                hwndForPThree[i] = CreateWindow(TEXT("Button"),TEXT(""),
                            BS_AUTORADIOBUTTON|WS_CHILD,
                            120,120+70*i,
                            550,40,
                            hwnd,(HMENU)(8+i),((LPCREATESTRUCT)lParam)->hInstance,NULL);
            }
            hwndForPThree[5] = CreateWindow(TEXT("Button"),TEXT("查看"),//查看商品按钮
                         BS_PUSHBUTTON|WS_CHILD,
                         600,480,
                         70,40,
                         hwnd,(HMENU)13,((LPCREATESTRUCT)lParam)->hInstance,NULL);
            //hwndForPThree[6] = CreateWindow(TEXT("Button"),TEXT("<="),//后退按键
                         //BS_PUSHBUTTON|WS_CHILD,
                         //50,500,
                         //70,40,
                         //hwnd,(HMENU)14,((LPCREATESTRUCT)lParam)->hInstance,NULL);
            hwndForPFour[0] = CreateWindow(TEXT("Button"),TEXT("购买！"),//购买按键
                         BS_PUSHBUTTON|WS_CHILD,
                         600,500,
                         70,40,
                         hwnd,(HMENU)14,((LPCREATESTRUCT)lParam)->hInstance,NULL);
            //hwndForPFour[0] = CreateWindow(TEXT("Button"),TEXT("<="),//后退按键
                         //BS_PUSHBUTTON|WS_CHILD,
                         //50,500,
                         //70,40,
                         //hwnd,(HMENU)14,((LPCREATESTRUCT)lParam)->hInstance,NULL);
            for(i=0;i<5;i++)//建立我的交易选项
            {
                hwndForPFive[i] = CreateWindow(TEXT("Button"),TEXT(""),
                            BS_AUTORADIOBUTTON|WS_CHILD,
                            120,120+70*i,
                            550,40,
                            hwnd,(HMENU)(15+i),((LPCREATESTRUCT)lParam)->hInstance,NULL);
            }
            hwndForPFive[6] = CreateWindow(TEXT("Button"),TEXT("查看"),//查看单个交易按键
                         BS_PUSHBUTTON|WS_CHILD,
                         600,500,
                         70,40,
                         hwnd,(HMENU)20,((LPCREATESTRUCT)lParam)->hInstance,NULL);
            for(i=0;i<5;i++)//建立我的商品选项
            {
                hwndForPSix[i] = CreateWindow(TEXT("Button"),TEXT(""),
                            BS_AUTORADIOBUTTON|WS_CHILD,
                            120,120+70*i,
                            550,40,
                            hwnd,(HMENU)(21+i),((LPCREATESTRUCT)lParam)->hInstance,NULL);
            }
            hwndForPSix[5] = CreateWindow(TEXT("Button"),TEXT("查看"),//查看单个交易按键
                         BS_PUSHBUTTON|WS_CHILD,
                         600,500,
                         70,40,
                         hwnd,(HMENU)27,((LPCREATESTRUCT)lParam)->hInstance,NULL);
            return 0;
        }

    case WM_PAINT:
        {
            hdc = BeginPaint(hwnd,&ps);
            GetClientRect(hwnd,&rect);
            SetBkColor(hdc,RGB(255,194,166));
            rForDetail.top = 350;rForDetail.left = 150;rForDetail.bottom = 450;rForDetail.right = 750;
            switch(page)
            {
            case 1://Login page
                {
                    TextOut(hdc,350,100,TEXT("登入页面"),4);
                    TextOut(hdc,220,200,TEXT("用户名:"),4);
                    TextOut(hdc,220,250,TEXT("密码:"),3);
                    for(i=0;i<4;i++)
                    {
                        ShowWindow(hwndForPOne[i],SW_SHOW);
                    }
                    //TextOut
                    break;
                }
            case 2://Main Page
                {
                    for(i=0;i<4;i++)
                    {
                        ShowWindow(hwndForPTwo[i],SW_SHOW);
                    }
                    linked_mainsentence = L"亲爱的"+name+L",您好！";
                    TextOut(hdc,250,250,linked_mainsentence.c_str(),linked_mainsentence.length());
                    //TextOut(hdc,250,250,TEXT("亲爱的"),3);
                    //TextOut(hdc,450,250,TEXT("您好！"),3);
                    //TextOut(hdc,320,250,name.c_str(),nameLength);
                    break;
                }
            case 3://Search Page
                {
                    for(i=0;i<7;i++)
                    {
                        ShowWindow(hwndForPThree[i],SW_SHOW);
                    }
                    break;
                }
            case 4://Details of the item
                {
                        ShowWindow(hwndForPFour[1],SW_SHOW);
                    //wchar_t price_wchars[50];
                    //wsprintf(price_wchars, L"%f", itemCheck.price());
                    //wstring price_wstr = price_wchars;
                    //wstring.valueOf(6);
                    //wostringstream stream;
                    //stream << itemCheck().price();
                    linked_sentence = L"商品名："+itemCheck->title();
                    TextOut(hdc,100,100,linked_sentence.c_str(),linked_sentence.length());
                    linked_sentence = L"卖家："+itemCheck->seller();
                    TextOut(hdc,100,200,linked_sentence.c_str(),linked_sentence.length());
                    linked_sentence = L"详情："+itemCheck->detail();
                    TextOut(hdc,100,300,linked_sentence.c_str(),linked_sentence.length());
                    if(itemCheck->on_shelf())
                    {
                        TextOut(hdc,100,400,TEXT("状态：在售"),5);
                        ShowWindow(hwndForPFour[0],SW_SHOW);
                    }
                    else
                    {
                        TextOut(hdc,100,400,TEXT("状态：已下架"),6);
                    }
                    break;
                }
            case 5://我的交易页
                {
                    for(i=0;i<7;i++)
                    {
                        ShowWindow(hwndForPFive[i],SW_SHOW);
                    }
                    break;
                }
            case 6://我的商品页
                {
                    for(i=0;i<7;i++)
                    {
                        ShowWindow(hwndForPSix[i],SW_SHOW);
                    }
                }
            case 7:
                {
                    ShowWindow(hwndForSeven[0],SW_SHOW);
                    linked_sentence = L"交易商品名："+dealcheck->get_content().GetItemName();
                    TextOut(hdc,100,100,linked_sentence.c_str(),linked_sentence.length());
                    linked_sentence = L"出售人："+dealcheck->get_content().GetSeller();
                    TextOut(hdc,100,200,linked_sentence.c_str(),linked_sentence.length());
                    linked_sentence = L"购买人："+dealcheck->get_content().GetBuyer();
                    TextOut(hdc,100,300,linked_sentence.c_str(),linked_sentence.length());
                    break;
                }
            }
            EndPaint(hwnd,&ps);
            return 0;
        }
    case WM_COMMAND:
    {
        clicked = LOWORD(wParam);
        if(clicked>7&&clicked<13)
        {
            itemchosen = clicked - 8;
        }
        if(clicked>14&&clicked<20)
        {
            dealchosen = clicked-15;
        }
        GetClientRect(hwnd,&rect);
        switch(clicked)
        {
            case 0:
            {
                //nameLength = GetWindowText(hwndForPOne[2],lpname,128);
                nameLength = GetWindowText(hwndForPOne[2],lpString,128);
                name = lpString;
                //*pOut = name;
                pwLength = GetWindowText(hwndForPOne[3],lpString,128);
                password = lpString;
                preUser = User(name,password);

                if(userTable.AddIndividual(preUser))
                {
                    //MessageBox(hwnd,userTable.Table[ElfHash(preUser.GetName())].user->GetCode().c_str(),TEXT(""),MB_OK);
                    //page = 2;
                    MessageBox(hwnd,TEXT("注册成功！"),TEXT("欢迎！"),MB_OK);
                    /*for(i=0;i<4;i++)
                    {
                        ShowWindow(hwndForPOne[i],SW_HIDE);
                    }
                    InvalidateRect(hwnd,&rect,true);*/
                }
                else
                {
                    MessageBox(hwnd,TEXT("注册失败，请更换用户名！"),TEXT("提示"),MB_OK);
                }
                break;
            }
            case 1:
            {
                GetWindowText(hwndForPOne[2],lpString,128);
                name = lpString;
                GetWindowText(hwndForPOne[3],lpString,128);
                password = lpString;
                preUser = User(name,password);
                if(userTable.UserLogin(preUser.GetName(),preUser.GetCode()))
                {
                    MessageBox(hwnd,TEXT("登陆成功！"),TEXT("欢迎"),MB_OK);
                    page = 2;
                    pageStack.push(page);//主页入栈
                    for(i=0;i<4;i++)
                    {
                        ShowWindow(hwndForPOne[i],SW_HIDE);
                    }
                    InvalidateRect(hwnd,&rect,true);
                }
                else
                {
                    MessageBox(hwnd,TEXT("登陆失败！请重新尝试或注册"),TEXT("提示"),MB_OK);
                }
                break;
            }

            case 5://查找包含关键词的商品
            {
                //Item it = itemList.items().front()->get_content();
                //MessageBox(hwnd,it.title().c_str(),TEXT("shangp"),MB_OK);
                GetWindowText(hwndForPTwo[0],lpString,128);
                keyword = lpString;
                beFound = itemList.find_item(keyword);
                pointer = beFound.front();
                //MessageBox(hwnd,l)
                for(totalfound=0;totalfound<5;totalfound++)
                {
                    if(pointer==nullptr)
                        break;
                    items[totalfound] = pointer->get_pointer();
                    SetWindowText(hwndForPThree[totalfound],items[totalfound]->title().c_str());
                    pointer = pointer->get_next();
                    //MessageBox(hwnd,L"Hello",L"fu",MB_OK);
                }
                //beFound = itemList.find_item(keyword);
                //MessageBox(hwnd,to_string(totalfound).c_str(),TEXT("total"),MB_OK);
                page = 3;
                pageStack.push(page);
                for(i=0;i<4;i++)//隐藏主页窗口
                {
                    ShowWindow(hwndForPTwo[i],SW_HIDE);
                }
                InvalidateRect(hwnd,&rect,true);
                break;
            }
            case 13://商品搜索页按下查看
            {
                if(itemchosen<=totalfound)
                {
                    itemCheck = items[itemchosen];
                    for(i=0;i<7;i++)
                    {
                        ShowWindow(hwndForPThree[i],SW_HIDE);
                    }
                    page = 4;
                    pageStack.push(page);
                }
                else
                {
                    UpdateWindow(hwnd);
                }
                InvalidateRect(hwnd,&rect,true);
                break;
            }
            case 14://购买按键
            {
                Deal newDeal = Deal(itemCheck->seller(),preUser.GetName(),itemCheck->title(),itemCheck->id());
                dealList.add_front(newDeal);
                preUser.buy_deals().add_front(newDeal);

                /*Deal trytest = (preUser.buy_deals().front())->get_content();
                wstring holy = trytest.GetItemName();
                MessageBox(hwnd,holy.c_str(),TEXT(" "),MB_OK);*/
                //Item& theItem = ItemList.find_item(itemCheck.id());
                itemList.find_item(itemCheck->id())->put_off_shelf();
                itemCheck->put_off_shelf();
                InvalidateRect(hwnd,&rect,true);
                break;
            }
            case 6://按下查看我的交易按键
            {
                totalDeal = 0;
                ListNode<Deal> *nowdeal = preUser.buy_deals().front();
                while(nowdeal!=nullptr&&totalDeal<5)
                {
                    Deal transmit1 = nowdeal->get_content();
                    wstring transmit2 = transmit1.GetItemName();
                    SetWindowText(hwndForPFive[totalDeal],transmit2.c_str());
                    totalDeal++;
                    nowdeal = nowdeal->get_next();
                }
                page = 5;
                pageStack.push(page);
                for(i=0;i<5;i++)
                {
                    ShowWindow(hwndForPTwo[i],SW_HIDE);
                }
                InvalidateRect(hwnd,&rect,true);
                break;
            }
            case 7://按下查看我的商品
            {
                /*totalMyItem = 0;
                ListNode<Item> *nowmyitem = preUser.sale_items().front();
                while(nowmyitem!=nullptr&&totalMyItem<5)
                {
                    Item transmit3  = nowmyitem->get_content();
                    wstring transmit4 = transmit3.title();
                    SetWindowText(hwndForPSix[totalMyItem],transmit4.c_str());
                    totalMyItem++;
                    nowmyitem = nowmyitem->get_next();
                }
                //MessageBox(hwnd,TEXT("Hello"),TEXT("Bye"),MB_OK);
                page = 6;
                pageStack.push(page);
                MessageBox(hwnd,TEXT("Hello"),TEXT("Bye"),MB_OK);*/
                for(i=0;i<5;i++)
                {
                    ShowWindow(hwndForPTwo[i],SW_HIDE);
                }
                MessageBox(hwnd,TEXT("Hello"),TEXT("Bye"),MB_OK);
                InvalidateRect(hwnd,&rect,true);
                //MessageBox(hwnd,TEXT("Hello"),TEXT("Bye"),MB_OK);
                break;
            }
            case 20://按下查看交易详情按键
            {
                if(dealchosen<totalDeal)
                {
                    dealcheck = preUser.buy_deals().front();
                    for(i=0;i<dealchosen;i++)
                    {
                        dealcheck = dealcheck->get_next();
                    }
                    for(i=0;i<7;i++)
                    {
                        ShowWindow(hwndForPFive[i],SW_HIDE);
                    }
                    page = 7;
                    pageStack.push(page);
                    InvalidateRect(hwnd,&rect,true);
                }
                else
                {
                    UpdateWindow(hwnd);
                }
                break;
            }
            case 26:
            {
                /*wstring ks= L"k";
                int hell = pageStack.getSize();
                for(i=0;i<=hell;i++)
                    ks += L"k";
                MessageBox(hwnd,ks.c_str(),TEXT("hell"),MB_OK);*/
                int toHide;
                toHide = pageStack.pop();
                page = pageStack.top();
                if(toHide==3)
                {
                    for(i=0;i<7;i++)
                        ShowWindow(hwndForPThree[i],SW_HIDE);
                        InvalidateRect(hwnd,&rect,true);
                    break;
                }
                else if(toHide==4)
                {
                    for(i=0;i<2;i++)
                        ShowWindow(hwndForPFour[i],SW_HIDE);
                        InvalidateRect(hwnd,&rect,true);
                    break;
                }
                else if(toHide==5)
                {
                    for(i=0;i<7;i++)
                        ShowWindow(hwndForPFive[i],SW_HIDE);
                        InvalidateRect(hwnd,&rect,true);
                    break;
                }
                else if(toHide==6)
                {
                    for(i=0;i<7;i++)
                        ShowWindow(hwndForPSix[i],SW_HIDE);
                        InvalidateRect(hwnd,&rect,true);
                    break;
                }
                else if(toHide==7)
                {
                    for(i=0;i<1;i++)
                        ShowWindow(hwndForSeven[i],SW_HIDE);
                        InvalidateRect(hwnd,&rect,true);
                    break;
                }
                InvalidateRect(hwnd,&rect,true);
                break;
            }
        }
        return 0;
    }
    case WM_DESTROY:
        PostQuitMessage(0);       /* send a WM_QUIT to the message queue */
        break;
    default:                      /* for messages that we don't deal with */
        return DefWindowProc (hwnd, message, wParam, lParam);
    }

    return 0;
}
