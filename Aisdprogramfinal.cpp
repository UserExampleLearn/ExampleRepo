
                    test = false;     
                    d[pv->v] = d[x] + pv->w; 
                    p[pv->v] = x;   
                }
        if (test) return true;  
    }

    // Sprawdzamy istnienie ujemnego cyklu

    for (x = 0; x < n; x++)
        for (pv = A[x]; pv; pv = pv->next)
            if (d[pv->v] > d[x] + pv->w) return false; // ujemny cykl!!

    return true;
}


int main()
{
    int i, v, x, y, w, sptr, * S;
    slistEl* rv, * pv;
    int t[100], a[100], b[100], c[100];
    int pom, suma = 0, wynik[100];
    v = 0;
    cin  >> n >> m;      //  liczba wierzchołków i krawędzi
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y >> w;
        t[i] = x;
        a[i] = y;
        b[i] = w;
    }
    for (int rep = 0; rep < n; rep++)
    {

        A = new slistEl * [n]; 
        d = new long long[n]; 
        p = new int[n];       
        for (i = 0; i < n; i++) 
        {
            d[i] = MAXINT;
            p[i] = -1;
            A[i] = NULL;
        }

        for (i = 0; i < m; i++)
        {
            x = t[i];
            y = a[i];
            w = b[i];
            pv = new slistEl;   
            pv->v = y;          
            pv->w = w;
            pv->next = A[x]; 
            A[x] = pv;
        }

        cout << endl;

        // Wyznaczamy najkrótsze ścieżki algorytmem Bellmana-Forda

        if (BF(v))
        {
            S = new int[n];    // Tworzymy prosty stos
            sptr = 0;

            for (i = 0; i < n; i++)
            {
                cout << i << ": ";
                for (x = i; x != -1; x = p[x]) // Wierzchołki ścieżki umieszczamy na stosie
                    S[sptr++] = x; // w kolejności od ostatniego do pierwszego

                while (sptr)       // Wierzchołki ze stosu drukujemy
                    cout << S[--sptr] << " "; // w kolejności od pierwszego do ostatniego

                cout << "$" << d[i] << endl; // Na końcu wyświetlamy koszt

                suma = suma + d[i];
            }
            wynik[rep] = suma * 2;
            delete[] S;         // Usuwamy stos
        }
        else cout << "Negative Cycle found!" << endl;
        pom = rep + 1;



        for (int i = 0; i < m; i++)
        {
            if (t[i] == 0)
            {
                t[i] = pom;
            }

            else if (t[i] == pom)
            {
                t[i] = 0;
            };
            if (a[i] == 0)
            {
                a[i] = pom;
            }
            else if (a[i] == pom)
            {

