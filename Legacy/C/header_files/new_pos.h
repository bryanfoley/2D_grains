void new_pos(double free_particle[n_max][m_max][z_max],
             double wall_particle[44][m_max][z_max],
             double image_free_particle[n_max][m_max][z_max])
{
     int i;
     char func_name[30] = "new_pos";
     char action_begin[10] = ">>>";
     char action_end[10] = "<<<";
     time_stamp();
     trace(func_name,action_begin);
     
     for(i = 0; i < n_max; i++)
      {
      free_particle[i][2][1] = (free_particle[i][2][0] + ((free_particle[i][0][0])*dt)
                          +(0.5000000000000000*((free_particle[i][4][0])*(pow(dt,2.0000000000000000)))));
      free_particle[i][3][1] = (free_particle[i][3][0] + ((free_particle[i][1][0])*dt)
                          +(0.5000000000000000*((free_particle[i][5][0])*(pow(dt,2.0000000000000000)))));
                          
      image_free_particle[i][2][1] = (image_free_particle[i][2][0] + ((image_free_particle[i][0][0])*dt)
                          +(0.5000000000000000*((image_free_particle[i][4][0])*(pow(dt,2.0000000000000000)))));
      image_free_particle[i][3][1] = (image_free_particle[i][3][0] + ((image_free_particle[i][1][0])*dt)
                          +(0.5000000000000000*((image_free_particle[i][5][0])*(pow(dt,2.0000000000000000)))));
      }
      
      /*Update the top row wall_particle positions*/
      /*for(i = 22; i < 44; i++)*/
       /*{*/
        /*wall_particle[i][3][0] = wall_particle[i][3][0] + ((wall_particle[i][1][0])*dt);*/
       /*}*/

    time_stamp();
    trace(func_name,action_end);
}
