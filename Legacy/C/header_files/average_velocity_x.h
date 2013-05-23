double average_velocity_x(double free_particle[n_max][m_max][z_max])
{
       double sumx = 0.0;
       double ans = 0.0;
       char func_name[30] = "average_velocity_x";
       char action_begin[10] = ">>>";
       char action_end[10] = "<<<";
       time_stamp();
       trace(func_name,action_begin);
       
       for(i = 0; i < n_max; i++)
        {
         sumx += free_particle[i][0][0];
        }
       
       ans = (sumx)/n_max;
       
       return(ans);
       time_stamp();
       trace(func_name,action_end);
       
}
