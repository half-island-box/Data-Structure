

#include"Dijkstra.h"


Undigraph Graph_Init() {
    Edge e[12];
    e[0] = Edge(1, 2, 2);
    e[1] = Edge(2, 3, 1);
    e[2] = Edge(2, 4, 1);
    e[3] = Edge(4, 5, 2);
    e[4] = Edge(3, 5, 3);
    e[5] = Edge(6, 7, 4);
    e[6] = Edge(7, 8, 6);
    e[7] = Edge(4, 7, 2);
    e[8] = Edge(5, 8, 5);
    e[9] = Edge(7, 9, 10);
    e[10] =Edge(8, 10, 8);
    e[11]=Edge(5,10,10);

    Undigraph g(11, 12, e);
    return g;

}


int main() {

    Undigraph g = Graph_Init();
    while (1) {
        cout << "��ӭ������ɽ��ѧ��������,����1��ѯ�ص�·��,2��ѯ�ص���Ϣ,0�˳�" << endl;
        int in;
        cout << "�����룺";
        cin >> in;
        if (in>=3) {
            cout << "����ȷ����" << endl;
            system("pause");
            system("cls");
            continue;
        }
        if (in == 0) break;
        system("cls");

        if (in == 1) {
            while (1) {
                cout << "����1��ѯ���·����2�о�����·����3������;���㣬0����" << endl;
                cout << "�����룺";
                int in1;
                cin >> in1;
                if (in1>=4) {
                    cout << "����ȷ����" << endl;
                    system("pause");
                    system("cls");
                    continue;
                }
                if (in1 == 0) {
                    system("cls");
                    break;
                }




                if (in1 == 1) {
                    string begin, end;
                    cout << "���������:";
                    cin >> begin;
                    cout << "�������յ�:";
                    cin >> end;
                    cout << "���·�����£�" << endl;
                    cout << g.Dijkstra(begin, end, 0) << endl;
                    cout << endl;
                    system("pause");
                    system("cls");
                }

                if (in1 == 2) {
                    string begin, end;
                    cout << "���������:";
                    cin >> begin;
                    cout << "�������յ�:";
                    cin >> end;
                    cout << "ȫ��·�����£�" << endl;
                    g.All_route(begin, end);
                    cout << endl;
                    system("pause");
                    system("cls");
                }

                if (in1 == 3) {
                    string begin, end;
                    cout << "���������:";
                    cin >> begin;
                    cout << "�������յ�:";
                    cin >> end;
                    queue<string> pass;
                    int n;
                    //cout << "��0�ɷ���" << endl;
                    cout << "������;�������:";
                    cin >> n;
                    cout << "������;����(�ÿո�����:";
                    for (int i = 0; i < n; i++) {
                        string x;
                        cin >> x;
                        pass.push(x);
                    }
                    
                    cout << g.Dijkstra_pass(begin, end, pass) << endl;
                    system("pause");
                    system("cls");
                }
                system("cls");
            }
        }

        if (in == 2) {
            while (1) {
                cout << "����0����" << endl;
                cout << "�������ѯ�ص�:";
                string tar;
                cin >> tar;
                if (tar == "0") break;
                cout << g.show_message(tar) << endl;
                system("pause");
                system("cls");
            }
            system("cls");
        }
        
    }


    
    return 0;
}
