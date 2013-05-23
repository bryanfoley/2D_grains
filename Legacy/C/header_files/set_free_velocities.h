double set_free_velocities(double free_particle[n_max][m_max][z_max])
{
     int i;
     double sigma = 0.1000000000000000;
     double mu = 0.0000000000000000;
     double u1, u2, v1, v2, s, temp1, temp2;
     double sumx = 0.0000000000000000;
     double sumxx = 0.0000000000000000;
     double mean;
     double std_dev;
     char func_name[35] = "set_free_velocities";
     char action_begin[10] = ">>>";
     char action_end[10] = "<<<";
     time_stamp();
     trace(func_name,action_begin);


     for (i=0; i < n_max; i++)
      {
       do
        {
         u1 = (double) rand()/RAND_MAX;
         u2 = (double) rand()/RAND_MAX;
         v1 = 2.0000000000000000*u1 - 1.0000000000000000;
         v2 = 2.0000000000000000*u2 - 1.0000000000000000;
         s = (v1*v1)+(v2*v2);
        }
       while (s>=1.0);
       
       temp1 = log(s);
       temp2 = sqrt(-2.0000000000000000*temp1/s);
       free_particle[i][0][0] = (((v1*temp2)*sigma + mu))*1e-1;
       free_particle[i][1][0] = (((v2*temp2)*sigma + mu))*1e-1;
      }
      
     for(i = 0; i < n_max; i++)
      {
       sumx += free_particle[i][0][0];
       sumxx += free_particle[i][9][0]*free_particle[i][9][0];
      }
     mean = sumx/n_max;
     std_dev = sqrt((sumxx - n_max * (mean * mean))/(n_max - 1));
     return(mean);
     time_stamp();
     trace(func_name,action_end);
}
