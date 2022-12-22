#include <iostream>

#include "../include/url.h"

using std::cout;
using std::endl;

Url::Url()
{
    depth_ = 0;
    protocol_ = "";
    www_ = "";
    host_ = "";
    path_ = "";
    query_ = "";
}

Url::Url(string &url)
{
    int depth = 0;
    if (url.back() == '/')
    {
        url.erase(url.length()-1);
    }

    size_t found1 = url.find("://");
    protocol_ = url.substr(0, found1);
    url.erase(0, found1+3);

    size_t found2 = url.find("www.");
    if (found2 != string::npos)
    {
        www_ = "";
        url.erase(0, 4);
    } 
    else 
    {
        www_ = "";
    }

    size_t found3 = url.find("/");
    if (found3 != string::npos) 
    {
        host_ = url.substr(0, found3);
        url.erase(0, found3+1);
    } 
    else 
    {
        host_ = url;
        url.erase(0);
    }

    if (url != "")
    {
        size_t found4 = url.find("?");
        size_t found5 = url.find("#");
        if (found4 != string::npos) 
        {
            path_ = url.substr(0, found4);
            url.erase(0, found4+1);
        }
        else if (found5 != string::npos)
        {
            path_ = url.substr(0, found5);
            url.erase(0, found5+1);
        }
        else 
        {
            path_ = url;
            url.erase(0);
        }
    }

    if (url != "")
    {
        size_t found5 = url.find("#");
        if (found5 != string::npos) {
            query_ = url.substr(0, found5);
            url.erase(0, found5+1);
        } else {
            query_ = url;
            url.erase(0);
        }
    }

    if (path_.compare("") != 0)
    {
        depth++;
        for (unsigned i = 0; i < path_.length(); i++) {
            if (path_.at(i) == '/')
                depth++;
        }
    }

    depth_ = depth;
}

bool Url::isValid()
{
    if (protocol_.compare("http") != 0)
    {
        return false;
    }
    
    if (path_.find(".jpg") != string::npos)
    {
        return false;
    }

    if (path_.find(".gif") != string::npos)
    {
        return false;
    }

    if (path_.find(".mp3") != string::npos)
    {
        return false;
    }

    if (path_.find(".avi") != string::npos)
    {
        return false;
    }

    if (path_.find(".doc") != string::npos)
    {
        return false;
    }

    if (path_.find(".pdf") != string::npos)
    {
        return false;
    }

    return true;
}

void Url::print()
{
    if (path_ != "" && query_ != "")
        cout << protocol_ << "://" << www_ << host_ << "/" << path_ << "?" << query_ << endl;
    else if (path_ != "")
        cout << protocol_ << "://" << www_ << host_ << "/" << path_ << endl;
    else
        cout << protocol_ << "://" << www_ << host_ << endl;
}

ostream& operator<< (ostream& os, Url &url)
{
    if (url.path_ != "" && url.query_ != "")
        os << url.protocol_ << "://" << url.www_ << url.host_ << "/" << url.path_ << "?" << url.query_;
    else if (url.path_ != "")
        os << url.protocol_ << "://" << url.www_ << url.host_ << "/" << url.path_;
    else
        os << url.protocol_ << "://" << url.www_ << url.host_;

    return os;
}

bool operator== (Url& a, Url& b)
{
    if (a.protocol_.compare(b.protocol_) != 0 || 
        a.www_.compare(b.www_) != 0 ||
        a.host_.compare(b.host_) != 0 ||
        a.path_.compare(b.path_) != 0 ||
        a.query_.compare(b.query_) != 0 ||
        a.depth_ != b.depth_)
    {
        return false;
    }
    return true;
}

string Url::GetProtocol()
{
    return protocol_;
}

string Url::GetHost()
{
    return host_;
}

string Url::GetPath()
{
    return path_;
}

int Url::GetDepth()
{
    return depth_;
}