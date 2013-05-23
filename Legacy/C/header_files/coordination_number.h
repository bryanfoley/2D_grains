double coordination_number(double free_particle[n_max][m_max][z_max])
{
       double sum = 0.0;
       double ans;
       int i,j,k;
       char func_name[30] = "coordination_number";
       char action_begin[10] = ">>>";
       char action_end[10] = "<<<";
       time_stamp();
       trace(func_name,action_begin);
       
       for(i = 0; i < n_max; i++)
       {
        sum += free_particle[i][10][0];
       }
       
       ans = ((sum/n_max));
       
       return(ans);
       time_stamp();
       trace(func_name,action_end);
}
