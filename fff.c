
/**********************************************

       Fourier級数窓を用いたフェードイン・フェードアウト法
       切替え時の波形の傾き(微分値)がゼロになるように仕込んだ窓
       作成者 工藤彰洋
       2003.12.11
       改訂 2004.07.05
       改造 2018.06 下川原 綾汰

***********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "/Users/audio/kenkyu/douki/FileLib_osx.c"
#include "/Users/audio/kenkyu/douki/umasig/umasig.h"
#include "/Users/audio/kenkyu/douki/umasig/fft.c"
#include "/Users/audio/kenkyu/douki/umasig/vector.c"
#include "/Users/audio/kenkyu/douki/umasig/c_vector.c"
#include "/Users/audio/kenkyu/douki/umasig/complex.c"
#include "/Users/audio/kenkyu/douki/umasig/utils.c"
#include "/Users/audio/kenkyu/douki/umasig/conv.c"

#define a0 ((1.0+sqrt(2.0))/4.0)
#define a1 (0.25+0.25*sqrt((5.0-2.0*sqrt(2.0))/2.0))
#define a2 ((1.0-sqrt(2.0))/4.0)
#define a3 (0.25-0.25*sqrt((5.0-2.0*sqrt(2.0))/2.0))


int main(argc,argv)
int argc;
char **argv;
{
  double **filter;
  double *in,*in_h,*out_h,*filter_one;
  int i,j,K;
  int leng_in,w_leng,m,leng_h,leng_out,leng_fil,leng_out_h,leng_in_h;
  int fil_number,loop_times,switch_times,switch_times_limit,end_angle, move_angle;
  double *Out,**out;
  double f,theta;
  int dur_time, overlap_time;
  int unit_cycle;
  int *access_fil_number;
  char *rotation_direction, *subject_dir, *LandR, TF[50], out_name[50];

  if(argc!=9){
    fprintf(stderr,"bad commmandline format\n");
    fprintf(stderr,"usage: input(.DXX) end_angle move_angle rotation_direction subject_name LandR duration_time[sample] overlap_time[sample]\n");
  exit(EXIT_FAILURE);
  }

  end_angle=atoi(argv[2]);
  move_angle=atoi(argv[3]);
  fil_number=move_angle+1;
  rotation_direction=argv[4];
  subject_dir=argv[5];
  LandR=argv[6];
  dur_time=atoi(argv[argc-2]);/*信号が重ならない間の継続時間*/
  overlap_time=atoi(argv[argc-1]);/*信号が重なる時間*/
  unit_cycle=dur_time+overlap_time;/*切替えの基本となる周期*/
  sprintf(TF, "%s/SLTF/SLTF_%d_%s.DDB", subject_dir, end_angle, LandR);
  sprintf(out_name, "%s/TS/ts%d%s_%d_%s.DDB", subject_dir, move_angle ,rotation_direction ,end_angle, LandR);


  /********************** 信号長の設定 ********************/
  leng_in=lenfile(argv[1]);
  leng_fil=lenfile(TF);
  leng_out=leng_in+leng_fil;
  leng_out_h=overlap_time+dur_time+overlap_time;
  leng_in_h =overlap_time+dur_time+overlap_time+1-leng_fil;
  /********************************************************/

  access_fil_number=malloc(sizeof(int)*(2+(fil_number-2)*2));
  for (i=0;i<fil_number;i++) access_fil_number[i]=i;

  fprintf(stderr,"signal length=%d  filter length=%d  filter number=%d\n",leng_in,leng_fil,fil_number);

  in    = (double *)calloc(leng_in,sizeof(double));/*入力*/
  in_h  = (double *)calloc(leng_in_h+leng_fil*2,sizeof(double));/*切り出した入力*/
  out_h = (double *)calloc(leng_out_h+leng_fil*2,sizeof(double));/*切り出した信号の畳み込み結果*/
  Out   = (double *)calloc(leng_out,sizeof(double));/*最終的な出力*/
  filter_one = (double *)calloc(leng_fil,sizeof(double));
  out   =(double **)malloc(fil_number*sizeof(double));/*各インパルス応答毎に計算した畳み込み結果*/
  filter=(double **)malloc(fil_number*sizeof(double));/*インパルス応答*/
  for(i=0;i<fil_number;i++){
    out[i]=(double *)calloc(leng_out,sizeof(double));
    filter[i]=(double *)calloc(leng_fil,sizeof(double));
  }

  /**************** 入力信号の読み込み ****************/
  AnyFileRead(argv[1],in,leng_in);

  /************** インパルスの応答読み込み *******************/
  i=0;
  if(strcmp(rotation_direction, "c")==0){
    for(K=end_angle-move_angle;K<=end_angle;K++,i++){
      if(K<0)    {K+=360; end_angle+=360;}
      if (K>359) {K-=360; end_angle-=360;}
      sprintf(TF, "%s/SLTF/SLTF_%d_%s.DDB", subject_dir, K, LandR);
      AnyFileRead(TF,&filter[i][0],leng_fil);
    }
  }
  else{
    for(K=end_angle+move_angle;K>=end_angle;K--,i++){
      sprintf(TF, "%s/SLTF/SLTF_%d_%s.DDB", subject_dir, K, LandR);
      AnyFileRead(TF,&filter[i][0],leng_fil);
      // printf("%d:%s:%f\n", i, TF, *(&filter[i][0]));
    }
  }

  switch_times_limit=(int)(leng_out/unit_cycle);/*インパルス応答を切替える総数*/
  fprintf(stderr,"total switching of transfer fanctions  = %d times\n",switch_times_limit);


  switch_times=0;
  for(j=0;j<leng_in_h+leng_fil*2;j++) in_h[j]=0.0;
  for(j=0;j<leng_out_h+leng_fil*2;j++) out_h[j]=0.0;
  leng_h=(dur_time+overlap_time+1)-leng_fil;
  for(j=0;j<leng_h+leng_fil;j++) in_h[j]=in[j];
  for(j=0;j<leng_fil;j++) filter_one[j]=filter[access_fil_number[0]][j];
  lconv(out_h,in_h,filter_one,leng_h+leng_fil,leng_fil);
  for(j=dur_time;j<dur_time+overlap_time;j++) {
    theta=PI/(double)overlap_time*(double)(j-dur_time);
    f=a0+a1*cos(theta)+a2*cos(2.0*theta)+a3*cos(3.0*theta);
    out_h[j]=out_h[j]*f;
  }
  for(j=0;j<dur_time+overlap_time;j++) out[access_fil_number[0]][j]=out_h[j];


  /*switch_times=0以外の処理*/
  for(switch_times=1;switch_times<switch_times_limit;switch_times++){

    for(j=0;j<leng_in_h+leng_fil*2;j++) in_h[j]=0.0;/*初期化*/
    for(j=0;j<leng_out_h+leng_fil*2;j++) out_h[j]=0.0;/*初期化*/
    leng_h=(dur_time+overlap_time+overlap_time+1)-leng_fil;/*入力信号の本来の切り出し長*/

    for(j=0;j<leng_h+leng_fil*2;j++)
      in_h[j]=in[j+(switch_times-1)*unit_cycle+dur_time-leng_fil];/*入力信号切り出し
                                                                    (非定常部分を考慮して左右にlen_filだけ伸ばす)*/
    for(j=0;j<leng_fil;j++) filter_one[j]=filter[access_fil_number[switch_times]][j];

    lconv(out_h,filter_one,in_h,leng_fil,leng_h+leng_fil*2);/*線形畳み込み*/


/*#################Fourier級数窓で重み付け#################*/
    for(j=0;j<overlap_time;j++) {
      theta=PI/(double)overlap_time*(double)(j);
      f=a0-a1*cos(theta)+a2*cos(2.0*theta)-a3*cos(3.0*theta);
      out_h[j+leng_fil]=out_h[j+leng_fil]*f;
    }
    for(j=0;j<overlap_time;j++) {
      theta=PI/(double)overlap_time*(double)(j);
      f=a0+a1*cos(theta)+a2*cos(2.0*theta)+a3*cos(3.0*theta);
      out_h[j+leng_fil+unit_cycle]=out_h[j+leng_fil+unit_cycle]*f;
    }
/*#####################################################*/

    for(j=0;j<unit_cycle+overlap_time;j++){
      out[switch_times][j+(switch_times-1)*unit_cycle+dur_time]=out_h[j+leng_fil];/*結果を出力*/
    }
  }


  /*out[インパルス応答番号][離散時間]を各フィルタの出力について重ね合わせる*/
  for(i=0;i<leng_out;i++)
    for(j=0;j<fil_number;j++)
      Out[i]=Out[i]+out[j][i];
  AnyFileWrite(out_name,Out,leng_out);
}
