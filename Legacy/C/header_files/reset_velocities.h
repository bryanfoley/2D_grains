void reset_velocities(double free_particle[n_max][m_max][z_max], 
                        double image_free_particle[n_max][m_max][z_max])
{
       int i,l;
       char func_name[30] = "reset_velocities";
       char action_begin[10] = ">>>";
       char action_end[10] = "<<<";
       time_stamp();
       trace(func_name,action_begin);
       
       for(i = 0; i < n_max; i++)
        {
         for(l = 0; l < z_max; l++)
          {
           free_particle[i][0][l] = 0.0;
           free_particle[i][1][l] = 0.0;
           image_free_particle[i][0][l] = 0.0;
           image_free_particle[i][1][l] = 0.0;
          }
        }
      time_stamp();
      trace(func_name,action_end);
}
