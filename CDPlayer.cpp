#include <iostream>
#include <string>
using namespace std;

class CD
{
public:
    CD(string name, string songss[]);
    string getSonger() const; // ��ø��ֵ�����
    string getSong(int index) const; // ���ĳ�׸�ĸ���
    void listSongs() const; // �г�CD������
private:
    string songer; // ���ֵ����֡�
    string songs[6]; // ÿ��ר��6�׸�����֡�
};

CD::CD(string name, string songss[])
{
    songer=name;
    for(int i=0; i<6; i++)
        songs[i]=songss[i];
}

string CD::getSonger() const
{
    return songer;
}

string CD::getSong(int index) const
{
    return songs[index];
}

void CD::listSongs() const
{
    cout << endl << "Songer: " << getSonger() << endl;
    for(int i=0; i<6; i++)
        cout << "song" << i+1 << "#: " << getSong(i) << endl;
        cout << endl;
}


class CDPlayer
{
public:
    CDPlayer();

    /*�ṩ���û�һ����ť�˵��� ͨ������˵����û�����ѡ��
    1. ����CD
    2. ����CD
    3. ����CD
    0. �ػ� */
    void showButtons();

    /*����CD. void insertCD(CD* cd)�� �β���ָ��CD�����ָ�롣 ���CDPlayer
    ���Ѿ���CD����ʾ��ȡ��CD;���CDPlayer��û��CD����ʾ��������λ���ǵ�CD�� */
    void insertCD(CD* cd);

    /*����CD. CD* ejectCD()�� ����ֵ��ָ���CD�����ָ�롣 ���CDPlayer���Ѿ�
    ��CD����ʾ��������λ���ǵ�CD�����ظ�CD��ָ��;���CDPlayer��û��CD����ʾ
    CDPlayer��û��CD������NULL�� */
    void ejectCD();

    /*����CD�� ���CDPlayer���Ѿ���CD����ʾ���ڲ�����λ���ǵ�CD������ӡCD�и���
    ���嵥;���CDPlayer��û��CD����ʾCDPlayer��û��CD������ʾ�û�����CD�� */
    void play();

private:
    /* ����CDPlayer�е�CD������ָ��CD�����ָ�롣û��CDʱ��Ϊnull�� ʹ��ָ�룬
    �õ�ģ����CD�����ǲ�������һ���֣�������ֻ�Ƕ�ȡ�������е�CD�����ݡ� */
    CD *cd;
    bool cdIn; // CDPlayer���Ƿ��Ѿ�����CD
};


CDPlayer::CDPlayer()
{
    cdIn=false;
    cd=NULL;
}




void CDPlayer::showButtons()
{
    cout << "*********************************" << endl << "1. ����CD" << endl << "2. ����CD" << endl << "3. ����CD" << endl << "0. �ػ�"  << endl << "*********************************" << endl;
}

void CDPlayer::play()
{
    if(cdIn)
    {
        cout << "���ڲ���" << cd->getSonger() << "��CD......" << endl;
        cd->listSongs();
    }
    else
        cout << "Please insert CD first" << endl;
}

void CDPlayer::insertCD(CD* cd1)
{
    if(cd!=NULL)
    {
        cout << "Please eject CD" << endl;
        return;
    }
    if(cd==NULL)
    {
        cd=cd1;
        cdIn=true;
        cout << "������" << cd->getSonger()<< "�� CD......" << endl;
    }
}


void CDPlayer:: ejectCD()
{
    if(cd!=NULL)
    {
        cout << "������" << cd->getSonger() << "��CD......" << endl;
        cd=NULL;
        cdIn=false;
    }
    else
    {
        cout << "CDPlayer��û��CD������ʾ�û�����CD" << endl;
    }
}



int main()
{
    string name;
    string songs[6];
    cout << "\n����CD......\n";
// �����������
    cout << "Songer's Name: ";
    cin >> name; // ���룺�ܽ���
    //name="�ܽ���"
// ����ø��ֵ����׸������໨�ɡ��ջ�̨�����ڹ��ȣ�
    for (int i = 0; i < 6; i++)
    {
        cout << "song" << (i+1) << "#: ";
        cin >> songs[i];
    }
    CD cd(name,songs); //����CD

    cd.listSongs(); //��ʾCD������

    CDPlayer  player; //����CDplayer

    player.showButtons();//���ɲ��Ż��İ�ť
    /* ���� */
    player.play(); //��ӡ�� Please insert CD first
    /* ����CD */
    player.insertCD(&cd); //��ӡ���������ܽ��׵�CD......
    /* ���� */
    player.play(); //��ӡ�����ڲ����ܽ��׵�CD......
    player.ejectCD(); //��ӡ���������ܽ��׵�CD......
    /* ����һ��CD�����ֺ͸��¼��ʡ�ԡ� */
    //CD cd2(name2, songs2);
    //player.insertCD(cd2);
    //player.play();
    return 0;
}


/*
�����ִ�н�����£�
���� CD......
Songer's Name: �ܽ���(�û�����)
song1#: �໨��
song2#: �ջ�̨
song3#: ���ڹ�
song4#: ������
song5#: ɺ����
song6#: ����

Songer: �ܽ���(cd.listSongs()��ִ�н��)
1. �໨��
2. �ջ�̨
3. ���ڹ�
4. ������
5. ɺ����
6. ����
*********************************
* 1. ���� CD *(player.showButtons()��ִ�н��)
* 2. ���� CD *
* 3. ���� CD *
* 0. �ػ� *
*********************************
Please insert CD first (player.play()��ִ�н��)
�������ܽ��׵� CD...... (player.insertCD(cd)��ִ�н��)
���ڲ����ܽ��׵� CD......
Songer: �ܽ���



1. �໨��(player.play()��ִ�н��)
2. �ջ�̨
3. ���ڹ�
4. ������
5. ɺ����
6. ����
�������ܽ��׵� CD...... �� player.ejectCD()��ִ�н����
*/
