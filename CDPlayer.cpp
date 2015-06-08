#include <iostream>
#include <string>
using namespace std;

class CD
{
public:
    CD(string name, string songss[]);
    string getSonger() const; // 获得歌手的名称
    string getSong(int index) const; // 获得某首歌的歌名
    void listSongs() const; // 列出CD的内容
private:
    string songer; // 歌手的名字。
    string songs[6]; // 每张专辑6首歌的名字。
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

    /*提供给用户一个按钮菜单， 通过这个菜单，用户可以选择：
    1. 插入CD
    2. 播放CD
    3. 弹出CD
    0. 关机 */
    void showButtons();

    /*插入CD. void insertCD(CD* cd)， 形参是指向CD对象的指针。 如果CDPlayer
    中已经有CD，提示先取出CD;如果CDPlayer中没有CD，显示插入了哪位歌星的CD。 */
    void insertCD(CD* cd);

    /*弹出CD. CD* ejectCD()， 返回值是指向该CD对象的指针。 如果CDPlayer中已经
    有CD，显示弹出了哪位歌星的CD，返回该CD的指针;如果CDPlayer中没有CD，提示
    CDPlayer中没有CD，返回NULL。 */
    void ejectCD();

    /*播放CD。 如果CDPlayer中已经有CD，显示正在播放哪位歌星的CD，并打印CD中歌曲
    的清单;如果CDPlayer中没有CD，显示CDPlayer中没有CD，并提示用户插入CD。 */
    void play();

private:
    /* 插入CDPlayer中的CD，它是指向CD对象的指针。没有CD时，为null。 使用指针，
    好地模拟了CD对象不是播放器的一部分，播放器只是读取放入其中的CD的内容。 */
    CD *cd;
    bool cdIn; // CDPlayer中是否已经插入CD
};


CDPlayer::CDPlayer()
{
    cdIn=false;
    cd=NULL;
}




void CDPlayer::showButtons()
{
    cout << "*********************************" << endl << "1. 插入CD" << endl << "2. 播放CD" << endl << "3. 弹出CD" << endl << "0. 关机"  << endl << "*********************************" << endl;
}

void CDPlayer::play()
{
    if(cdIn)
    {
        cout << "正在播放" << cd->getSonger() << "的CD......" << endl;
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
        cout << "插入了" << cd->getSonger()<< "的 CD......" << endl;
    }
}


void CDPlayer:: ejectCD()
{
    if(cd!=NULL)
    {
        cout << "弹出了" << cd->getSonger() << "的CD......" << endl;
        cd=NULL;
        cdIn=false;
    }
    else
    {
        cout << "CDPlayer中没有CD，并提示用户插入CD" << endl;
    }
}



int main()
{
    string name;
    string songs[6];
    cout << "\n制造CD......\n";
// 输入歌手名字
    cout << "Songer's Name: ";
    cin >> name; // 输入：周杰伦
    //name="周杰伦"
// 输入该歌手的六首歌名（青花瓷、菊花台、三节棍等）
    for (int i = 0; i < 6; i++)
    {
        cout << "song" << (i+1) << "#: ";
        cin >> songs[i];
    }
    CD cd(name,songs); //制造CD

    cd.listSongs(); //显示CD的内容

    CDPlayer  player; //制造CDplayer

    player.showButtons();//生成播放机的按钮
    /* 播放 */
    player.play(); //打印： Please insert CD first
    /* 插入CD */
    player.insertCD(&cd); //打印：插入了周杰伦的CD......
    /* 播放 */
    player.play(); //打印：正在播放周杰伦的CD......
    player.ejectCD(); //打印：弹出了周杰伦的CD......
    /* 另造一张CD，歌手和歌的录入省略。 */
    //CD cd2(name2, songs2);
    //player.insertCD(cd2);
    //player.play();
    return 0;
}


/*
程序的执行结果如下：
制造 CD......
Songer's Name: 周杰伦(用户输入)
song1#: 青花瓷
song2#: 菊花台
song3#: 三节棍
song4#: 东风破
song5#: 珊瑚海
song6#: 稻香

Songer: 周杰伦(cd.listSongs()的执行结果)
1. 青花瓷
2. 菊花台
3. 三节棍
4. 东风破
5. 珊瑚海
6. 稻香
*********************************
* 1. 播放 CD *(player.showButtons()的执行结果)
* 2. 插入 CD *
* 3. 弹出 CD *
* 0. 关机 *
*********************************
Please insert CD first (player.play()的执行结果)
插入了周杰伦的 CD...... (player.insertCD(cd)的执行结果)
正在播放周杰伦的 CD......
Songer: 周杰伦



1. 青花瓷(player.play()的执行结果)
2. 菊花台
3. 三节棍
4. 东风破
5. 珊瑚海
6. 稻香
弹出了周杰伦的 CD...... （ player.ejectCD()的执行结果）
*/
