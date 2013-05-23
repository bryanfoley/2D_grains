void sum_forces(double free_particle[n_max][m_max][z_max],
                double image_free_particle[n_max][m_max][z_max],
                double free_forces[n_max][n_max][z_max],
                double image_free_forces[n_max][n_max][z_max],
                double wall_free_forces[n_max][44][z_max],
                double image_image_forces[n_max][n_max][z_max],
                double wall_image_forces[n_max][44][z_max])
{
     int i,j,k;
     double sum_x = 0.0000000000000000;
     double sum_y = 0.0000000000000000;
     double sum_x_wall = 0.0000000000000000;
     double sum_y_wall = 0.0000000000000000;
     char func_name[30] = "sum_forces";
     char action_begin[10] = ">>>";
     char action_end[10] = "<<<";
     time_stamp();
     trace(func_name,action_begin);
     
     /*Sum the forces acting on free_particle 'i'*/
     for(i = 0; i < n_max; i++)
      {
       for(j = 0; j < n_max; j++)
        {
         sum_x += free_forces[i][j][0] + image_free_forces[i][j][0];
         sum_y += free_forces[i][j][1] + image_free_forces[i][j][1]; 
        }
       
        /*Sum the forces acting on free_particle 'i' from all wall_particles 'j'*/
        for(k = 0; k < 44; k++)
         {
          sum_x_wall += wall_free_forces[i][k][0];
          sum_y_wall += wall_free_forces[i][k][1]; 
         }
       
       /*Compute the resultant force on free_particle 'i'*/
       free_particle[i][6][0] = (sum_x + sum_x_wall);    /*x component*/
       free_particle[i][7][0] = (sum_y + sum_y_wall);    /*y component*/
       sum_x = 0.0000000000000000;   /*Reset the counter*/
       sum_y = 0.0000000000000000;   /*Reset the counter*/
       sum_x_wall = 0.0000000000000000;   /*Reset the counter*/
       sum_y_wall = 0.0000000000000000;   /*Reset the counter*/
      }

/*____________________________________________________________________________*/           
     /*reset the counters again*/
      sum_x = 0.0000000000000000;
      sum_y = 0.0000000000000000;
      sum_x_wall = 0.0000000000000000;
      sum_y_wall = 0.0000000000000000;
/*____________________________________________________________________________*/     
     
     /*Sum the forces acting on image_free_particle 'i'*/ 
     for(i = 0; i < n_max; i++)
      {
       for(j = 0; j < n_max; j++)
        {
         sum_x += image_image_forces[i][j][0] + image_free_forces[j][i][0];
         sum_y += image_image_forces[i][j][1] + image_free_forces[j][i][1];
        }
       
        for(k = 0; k < 44; k++)
         {
          sum_x_wall += wall_image_forces[i][k][0];
          sum_y_wall += wall_image_forces[i][k][1];
         }
       
       /*Compute the resultant force on free_particle 'i'*/
       image_free_particle[i][6][0] = (sum_x + sum_x_wall);    /*x component*/
       image_free_particle[i][7][0] = (sum_y + sum_y_wall);    /*y component*/
       sum_x = 0.0000000000000000;   /*Reset the counter*/
       sum_y = 0.0000000000000000;   /*Reset the counter*/
       sum_x_wall = 0.0000000000000000;   /*Reset the counter*/
       sum_y_wall = 0.0000000000000000;   /*Reset the counter*/
      }
     time_stamp();
     trace(func_name,action_end);
/*____________________________________________________________________________*/
}
