void update(double free_particle[n_max][m_max][z_max],
             double image_free_particle[n_max][m_max][z_max])
{
     char func_name[30] = "update";
     char action_begin[10] = ">>>";
     char action_end[10] = "<<<";
     time_stamp();
     trace(func_name,action_begin);
     int i;
     
     for(i = 0; i < n_max; i++)
      {
       /*Velocity of free_particle 'i'*/
       free_particle[i][0][0] = free_particle[i][0][1];   /*x component*/
       free_particle[i][1][0] = free_particle[i][1][1];   /*y component*/
           
       /*Position of free_particle 'i'*/
       free_particle[i][2][0] = free_particle[i][2][1];   /*x component*/
       free_particle[i][3][0] = free_particle[i][3][1];   /*y component*/
           
       /*Acceleration of free_particle 'i'*/
       free_particle[i][4][0] = free_particle[i][4][1];
       free_particle[i][5][0] = free_particle[i][5][1];
       
       /*Velocity of image_free_particle 'i'*/
       image_free_particle[i][0][0] = image_free_particle[i][0][1];   /*x component*/
       image_free_particle[i][1][0] = image_free_particle[i][1][1];   /*y component*/
           
       /*Position of image_free_particle 'i'*/
       image_free_particle[i][2][0] = image_free_particle[i][2][1];   /*x component*/
       image_free_particle[i][3][0] = image_free_particle[i][3][1];   /*y component*/
           
       /*Acceleration of image_free_particle 'i'*/
       image_free_particle[i][4][0] = image_free_particle[i][4][1];
       image_free_particle[i][5][0] = image_free_particle[i][5][1];
      }
     time_stamp();
     trace(func_name,action_end);
}
