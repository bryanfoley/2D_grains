double average_velocity_y(double free_particle[n_max][m_max][z_max])
{
       double sumy = 0.0;
       double ans = 0.0;
       char func_name[30] = "average_velocity_y";
       char action_begin[10] = ">>>";
       char action_end[10] = "<<<";
       time_stamp();
       trace(func_name,action_begin);
       
       for(i = 0; i < n_max; i++)
        {
         sumy += free_particle[i][1][0];
        }
       
       ans = (sumy)/n_max;
       time_stamp();
       trace(func_name,action_end);
       
       return(ans);
}
