#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int h, w;
        cin >> h >> w;

        if (h % 2 && w % 2)
        {
            for (int i = 0; i < h; i++)
            {
                for (int j = 0; j < w; j++)
                    cout << "(";
                cout << endl;
            }
        }
        else if (!(h % 2) && w % 2)
        {
            for (int i = 0; i < h; i++)
            {
                for (int j = 0; j < w; j++)
                {
                    if (i % 2)
                        cout << ")";
                    else
                        cout << "(";
                }
                cout << endl;
            }
        }
        else if (!(w % 2) && h % 2)
        {
            for (int i = 0; i < h; i++)
            {
                for (int j = 0; j < w; j++)
                {
                    if (j % 2)
                        cout << ")";
                    else
                        cout << "(";
                }
                cout << endl;
            }
        }
        else if (w == 2 || h == 2)
        {
            if (w >= h)
            {
                for (int j = 0; j < w; j++)
                    cout << "(";
                cout << endl;
                for (int j = 0; j < w; j++)
                    cout << ")";
                cout << endl;
            }
            else
            {
                for (int i = 0; i < h; i++)
                    cout << "()" << endl;
            }
        }
        else if (w == 4 || h == 4)
        {
            if (w >= h)
            {
                for (int i = 0; i < h; i++)
                {
                    for (int j = 0; j < w; j++)
                    {
                        if (!i)
                            cout << "(";
                        else if (i == 2)
                        {
                            if (j < w / 2)
                                cout << "(";
                            else
                                cout << ")";
                        }
                        else if (i == 1)
                        {
                            if (j >= w / 2)
                                cout << "(";
                            else
                                cout << ")";
                        }
                        else
                            cout << ")";
                    }
                    cout << endl;
                }
            }
            else
            {
                for (int i = 0; i < h; i++)
                {
                    for (int j = 0; j < w; j += 2)
                    {
                        if (i < h / 2)
                            cout << "()";
                        else
                        {
                            if (j < w / 2)
                                cout << "((";
                            else
                                cout << "))";
                        }
                    }
                    cout << endl;
                }
            }
        }
        else
        {
            for (int i = 0; i < h; i++)
            {
                for (int j = 0; j < w; j++)
                {
                    if (!i)
                        cout << "(";
                    else if (i == h - 1)
                        cout << ")";
                    else if (i % 2 == 0)
                    {
                        cout << "()";
                        j++;
                    }
                    else if (i % 2)
                    {
                        if (!j)
                            cout << "(";
                        else if (j == w - 1)
                            cout << ")";
                        else
                        {
                            cout << "()";
                            j++;
                        }
                    }
                }
                cout << endl;
            }
        }
    }

    return 0;
}