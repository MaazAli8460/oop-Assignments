//Maaz ALi
//22i-1042
//Assignment4





#include "Cart.h"
int Cart::total_items = 0;
Cart::Cart()
{
    total_items = 0;
    pe_count = 0;
    br_count = 0;
    eg_count = 0;
    so_count = 0;
    br = NULL;
    eg = NULL;
    pe = NULL;
    so = NULL;
}
int Cart::getTotalItems()
{
    return total_items;
}
bool Cart::Discount() const
{
    bool arr[3];
    bool final = false;
    for (int i = 0; i < 3; i++)
    {
        arr[i] = false;
    }
    int ss = 0;
    // for pens
    for (int i = 0; i < pe_count; i++)
    {
        if (ss < 3 && pe[i].getsale() == true)
        {
            arr[ss] = pe[i].getsale();
            ss++;
        }
    }
    if (ss == 3)
    {
        for (int i = 0; i < 3; i++)
        {
            if (arr[i] == true)
            {
                final = true;
                continue;
            }
            else
            {
                final = false;
                break;
            }
        }
    }
    if (final)
    {
        return true;
        /* code */
    }

    // for bread
    for (int i = 0; i < br_count; i++)
    {
        if (ss < 3 && br[i].getsale() == true)
        {
            arr[ss] = br[i].getsale();
            ss++;
        }
    }
    if (ss == 3)
    {
        for (int i = 0; i < 3; i++)
        {
            if (arr[i] == true)
            {
                final = true;
                continue;
            }
            else
            {
                final = false;
                break;
            }
        }
    }
    if (final)
    {
        return true;
        /* code */
    }
    // for eggs
    for (int i = 0; i < eg_count; i++)
    {
        if (ss < 3 && eg[i].getsale() == true)
        {
            arr[ss] = eg[i].getsale();
            ss++;
        }
    }
    if (ss == 3)
    {
        for (int i = 0; i < 3; i++)
        {
            if (arr[i] == true)
            {
                final = true;
                continue;
            }
            else
            {
                final = false;
                break;
            }
        }
    }
    if (final)
    {
        return true;
        /* code */
    }
    // for so
    for (int i = 0; i < so_count; i++)
    {
        if (ss < 3 && so[i].getsale() == true)
        {
            arr[ss] = so[i].getsale();
            ss++;
        }
    }
    if (ss == 3)
    {
        for (int i = 0; i < 3; i++)
        {
            if (arr[i] == true)
            {
                final = true;
                continue;
            }
            else
            {
                final = false;
                break;
            }
        }
    }
    if (final)
    {
        return true;
        /* code */
    }
    return final;
}
double Cart::price() const
{
    double pricebr = 0;
    double priceeg = 0;
    double priceso = 0;
    double pricepe = 0;

    for (int i = 0; i < br_count; i++)
    {
        pricebr += br[i].price();
    }
    for (int i = 0; i < eg_count; i++)
    {
        priceeg += eg[i].price();
    }
    for (int i = 0; i < so_count; i++)
    {
        priceso += so[i].price();
    }
    for (int i = 0; i < pe_count; i++)
    {
        pricepe += pe[i].price();
    }
    double price;
    price = pricebr + priceeg + priceso + pricepe;

    if (Discount())
    {
        price = price * 0.85;
    }
    return price;
}
string Cart::String() const
{
    string str;
    if (total_items == 0)
    {
        str = "\nStill no Items in cart.\n";
        return str;
    }
    for (int i = 0; i < br_count; i++)
    {
        str += br[i].getname() + "\t";
        str += br[i].gettype() + "\t\t";
        str += to_string(br[i].getprice()) + "\t";
        str += to_string(br[i].getunits()) + "\t";
        str += to_string(br[i].getsale()) + "\t";
        str += to_string(br[i].getgift()) + "\t\t";
        str += to_string(br[i].price()) + "\n";
    }
    for (int i = 0; i < so_count; i++)
    {
        str += so[i].getname() + "\t";
        str += so[i].gettype() + "\t\t";
        str += to_string(so[i].getprice()) + "\t";
        str += to_string(so[i].getunits()) + "\t";
        str += to_string(so[i].getsale()) + "\t";
        str += to_string(so[i].getgift()) + "\t\t";
        str += to_string(so[i].price()) + "\n";
    }
    for (int i = 0; i < pe_count; i++)
    {
        str += pe[i].getname() + "\t";
        str += pe[i].gettype() + "\t";
        str += to_string(pe[i].getprice()) + "\t";
        str += to_string(pe[i].getunits()) + "\t";
        str += to_string(pe[i].getsale()) + "\t";
        str += to_string(pe[i].getgift()) + "\t\t";
        str += to_string(pe[i].price()) + "\n";
    }
    for (int i = 0; i < eg_count; i++)
    {
        str += eg[i].getname() + "\t";
        str += eg[i].gettype() + "\t\t";
        str += to_string(eg[i].getprice()) + "\t";
        str += to_string(eg[i].getunits()) + "\t";
        str += to_string(eg[i].getsale()) + "\t";
        str += to_string(eg[i].getgift()) + "\t\t";
        str += to_string(eg[i].price()) + "\n";
    }
    str += "Total cost of Cart: ";
    double x = price();
    str += to_string(x) + "\n";
    return str;
}
// oprator +=
Cart Cart::operator+=(Bread &b)
{
    total_items++;
    if (br == NULL)
    {
        br_count++;
        br = new Bread[br_count];
        br[0].setgift(b.getgift());
        br[0].setname(b.getname());
        br[0].setprice(b.getprice());
        br[0].setsale(b.getsale());
        br[0].setitem_type(b.gettype());
        br[0].setunits(b.getunits());
    }
    else
    {
        Bread *temp = new Bread[br_count + 1];
        for (int i = 0; i < br_count; i++)
        {
            temp[i].setgift(br[i].getgift());
            temp[i].setname(br[i].getname());
            temp[i].setprice(br[i].getprice());
            temp[i].setsale(br[i].getsale());
            temp[i].setitem_type(br[i].gettype());
            temp[i].setunits(br[i].getunits());
        }
        temp[br_count].setgift(b.getgift());
        temp[br_count].setname(b.getname());
        temp[br_count].setprice(b.getprice());
        temp[br_count].setsale(b.getsale());
        temp[br_count].setitem_type(b.gettype());
        temp[br_count].setunits(b.getunits());
        br_count++;
        delete[] br;
        br = temp;
        temp = NULL;
    }
    return *this;
}
Cart Cart::operator+=(Egg &e)
{
    total_items++;
    if (eg == NULL)
    {
        eg_count++;
        eg = new Egg[eg_count];
        eg[0].setgift(e.getgift());
        eg[0].setname(e.getname());
        eg[0].setprice(e.getprice());
        eg[0].setsale(e.getsale());
        eg[0].setitem_type(e.gettype());
        eg[0].setunits(e.getunits());
    }
    else
    {
        Egg *temp = new Egg[eg_count + 1];
        for (int i = 0; i < eg_count; i++)
        {
            temp[i].setgift(eg[i].getgift());
            temp[i].setname(eg[i].getname());
            temp[i].setprice(eg[i].getprice());
            temp[i].setsale(eg[i].getsale());
            temp[i].setitem_type(eg[i].gettype());
            temp[i].setunits(eg[i].getunits());
        }
        temp[eg_count].setgift(e.getgift());
        temp[eg_count].setname(e.getname());
        temp[eg_count].setprice(e.getprice());
        temp[eg_count].setsale(e.getsale());
        temp[eg_count].setitem_type(e.gettype());
        temp[eg_count].setunits(e.getunits());
        eg_count++;
        delete[] eg;
        eg = temp;
        temp = NULL;
    }
    return *this;

}
Cart Cart::operator+=(Pens &p)
{
    total_items++;
    if (pe == NULL)
    {
        pe_count++;
        pe = new Pens[pe_count];
        pe[0].setgift(p.getgift());
        pe[0].setname(p.getname());
        pe[0].setprice(p.getprice());
        pe[0].setsale(p.getsale());
        pe[0].setitem_type(p.gettype());
        pe[0].setunits(p.getunits());
    }
    else
    {
        Pens *temp = new Pens[pe_count + 1];
        for (int i = 0; i < pe_count; i++)
        {
            temp[i].setgift(pe[i].getgift());
            temp[i].setname(pe[i].getname());
            temp[i].setprice(pe[i].getprice());
            temp[i].setsale(pe[i].getsale());
            temp[i].setitem_type(pe[i].gettype());
            temp[i].setunits(pe[i].getunits());
        }
        temp[pe_count].setgift(p.getgift());
        temp[pe_count].setname(p.getname());
        temp[pe_count].setprice(p.getprice());
        temp[pe_count].setsale(p.getsale());
        temp[pe_count].setitem_type(p.gettype());
        temp[pe_count].setunits(p.getunits());
        pe_count++;
        delete[] pe;
        pe = temp;
        temp = NULL;
    }
    return *this;

}
Cart Cart::operator+=(Socks &s)
{
    total_items++;
    if (so == NULL)
    {
        so_count++;
        so = new Socks[so_count];
        so[0].setgift(s.getgift());
        so[0].setname(s.getname());
        so[0].setprice(s.getprice());
        so[0].setsale(s.getsale());
        so[0].setitem_type(s.gettype());
        so[0].setunits(s.getunits());
    }
    else
    {
        Socks *temp = new Socks[so_count + 1];
        for (int i = 0; i < so_count; i++)
        {
            temp[i].setgift(so[i].getgift());
            temp[i].setname(so[i].getname());
            temp[i].setprice(so[i].getprice());
            temp[i].setsale(so[i].getsale());
            temp[i].setitem_type(so[i].gettype());
            temp[i].setunits(so[i].getunits());
        }
        temp[so_count].setgift(s.getgift());
        temp[so_count].setname(s.getname());
        temp[so_count].setprice(s.getprice());
        temp[so_count].setsale(s.getsale());
        temp[so_count].setitem_type(s.gettype());
        temp[so_count].setunits(s.getunits());
        so_count++;
        delete[] so;
        so = temp;
        temp = NULL;
    }
    return *this;

}
// oprator +

Cart Cart::operator+(Bread &b)
{
    Cart *temp = this;

    *temp += b;
    temp->total_items+=2;
    return *temp;
}
Cart Cart::operator+(Egg &e)
{
    Cart *temp = this;

    *temp += e;
    temp->total_items+=2;
    return *temp;
}
Cart Cart::operator+(Pens &p)
{
    Cart *temp = this;

    *temp += p;
    temp->total_items+=2;
    return *temp;
}
Cart Cart::operator+(Socks &s)
{
    Cart *temp = this;

    *temp += s;
    temp->total_items+=2;
    return *temp;
}
// oprator -=

Cart Cart::operator-=(Bread &b)
{
    // total_items--;
    if (br == NULL)
    {
        cout << "\nERROR. This cart does not contain items of type Bread.";
        return *this;
    }
    else
    {
        total_items -= br_count;
        delete[] br;
        br = NULL;
        br_count = 0;
        return *this;
    }
}
Cart Cart::operator-=(Egg &e)
{
    // total_items--;
    if (eg == NULL)
    {
        cout << "\nERROR. This cart does not contain items of type Egg.";

        return *this;
    }
    else
    {
        total_items -= eg_count;
        delete[] eg;
        eg = NULL;
        eg_count = 0;
        return *this;
    }
}
Cart Cart::operator-=(Pens &p)
{
    // total_items--;
    if (pe == NULL)
    {
        cout << "\nERROR. This cart does not contain items of type Pens.";

        return *this;
    }
    else
    {
        total_items -= pe_count;
        delete[] pe;
        pe = NULL;
        pe_count = 0;
        return *this;
    }
}
Cart Cart::operator-=(Socks &s)
{
    // total_items--;
    if (so == NULL)
    {
        cout << "\nERROR. This cart does not contain items of type Socks.";

        return *this;
    }
    else
    {
        total_items -= so_count;
        delete[] so;
        so = NULL;
        so_count = 0;
        return *this;
    }
}
// oprator -
Cart Cart::operator-(Bread &b)
{
    Cart *temp = this;

    *temp -= b;
    return *temp;
}
Cart Cart::operator-(Egg &e)
{
    Cart *temp = this;

    *temp -= e;
    return *temp;
}
Cart Cart::operator-(Pens &p)
{
    Cart *temp = this;

    *temp += p;
    return *temp;
}
Cart Cart::operator-(Socks &s)
{
    Cart *temp = this;

    *temp += s;
    return *temp;
}

Cart::~Cart()
{
    // delete[] eg;
    // delete[] pe;
    // delete[] so;
    // delete []br;
}
ostream &operator<<(ostream &os, Cart &c1)
{
    os << "\nCART<CONTENTS>\nName\tType\t\tPrice\t\tUnits\tSale\tGift Card\tTotal price" << endl;
    return os << c1.String();
}
    // Cart *temp =new Cart;
    // this->pe=new Pens[this->pe_count];
    // this->br=new Bread[this->br_count];
    // this->eg=new Egg[this->eg_count];
    // this->so=new Socks[this->so_count];
    // temp->pe_count = this->pe_count;
    // temp->eg_count = this->eg_count;
    // temp->so_count = this->so_count;
    // temp->br_count = this->br_count;
    // for(int i=0;i<pe_count;i++)
    // {
    //     temp->pe[i]=this->pe[i];
    // }
    // for(int i=0;i<so_count;i++)
    // {
    //     temp->so[i]=this->so[i];
    // }
    // for(int i=0;i<br_count;i++)
    // {
    //     temp->br[i]=this->br[i];
    // }
    // for(int i=0;i<eg_count;i++)
    // {
    //     temp->eg[i]=this->eg[i];
    // }