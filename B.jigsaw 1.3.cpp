#include "gamemonitor.h"
#include "img_component.h"
#include "processer.h"

int pictureid;

int main()
{
	gamemonitor* gm=new gamemonitor;
	gm->play_bgm();
	gm->load_button(new f_button("res/left.jpg", 0, 300));
	gm->load_button(new b_button("res/right.jpg", 975, 300));
	gm->load_button(new s_button("res/start.jpg", 350, 450));
	gm->load_button(new bgm_button("res/music.jpg", 950, 50));
	IMAGE tmp1;
	loadimage(&tmp1, "res/bg057.jpg", 1080, 648);
	gm->load_bg(tmp1);
	loadimage(&tmp1, "res/bg001.jpg", 1080, 648);
	gm->load_bg(tmp1);
	loadimage(&tmp1, "res/bg002.jpg", 1080, 648);
	gm->load_bg(tmp1);
	loadimage(&tmp1, "res/cls.jpg", 1080, 648);
	gm->load_bg(tmp1);
	IMAGE tmp2;
	loadimage(&tmp2, "res/title.bmp");
	gm->load_s_component(new start_comp(350, 100, tmp2));
	IMAGE tmp3, tmp4;
	loadimage(&tmp3, "res/blank.jpg");
	gm->load_p_component(new play_comp(80, 200, tmp3));
	loadimage(&tmp3, "res/bg057_p.jpg");
	gm->load_p_component(new play_comp(400, 50, tmp3));
	rotateimage(&tmp3, &tmp3, PI);
	gm->load_p_component(new play_comp(400, 50, tmp3));
	loadimage(&tmp4, "res/bg057_s.jpg");
	gm->load_p_component(new play_comp(50, 50, tmp4));
	loadimage(&tmp3, "res/bg001_p.jpg");
	gm->load_p_component(new play_comp(400, 50, tmp3));
	rotateimage(&tmp3, &tmp3, PI);
	gm->load_p_component(new play_comp(400, 50, tmp3));
	loadimage(&tmp4, "res/bg001_s.jpg");
	gm->load_p_component(new play_comp(50, 50, tmp4));
	loadimage(&tmp3, "res/bg002_p.jpg");
	gm->load_p_component(new play_comp(400, 50, tmp3));
	rotateimage(&tmp3, &tmp3, PI);
	gm->load_p_component(new play_comp(400, 50, tmp3));
	loadimage(&tmp4, "res/bg002_s.jpg");
	gm->load_p_component(new play_comp(50, 50, tmp4));
	loadimage(&tmp3, "res/shadow.jpg");
	gm->load_p_component(new play_comp(80, 200, tmp3));
	initgraph(WIDTH, HEIGHT);
	gm->update();
}