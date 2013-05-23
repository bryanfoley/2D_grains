double potential(double x[n_max][n_max],double image_x[n_max][n_max],double wall_x[n_max][44])
{
       
       double potential = 0.0000000000000000;
       char func_name[30] = "potential";
       char action_begin[10] = ">>>";
       char action_end[10] = "<<<";
       time_stamp();
       trace(func_name,action_begin);
       
       /*Calculate the Potential energy between free_particle pairs*/
       for(i = 0; i < n_max; i++)
        {
         for(j = 0; j < n_max; j++)
          {
           potential += (kn/2.0000000000000000)*((x[i][j]*x[i][j]));
          }
        }
       
       /*Calculate the Potential energy between free_particle  and image_free_particle pairs*/
       for(i = 0; i < n_max; i++)
        {
         for(j = 0; j < n_max; j++)
          {
           potential += (kn/2.0000000000000000)*((image_x[i][j]*image_x[i][j]));
          }
        }     
            
       /*Calculate the Potential energy between free_particle and wall_particle pairs*/
       for(i = 0; i < n_max; i++)
        {
         for(k = 0; k < 44; k++)
          {
           potential += (kn/2.0000000000000000)*((wall_x[i][k]*wall_x[i][k]));
          }
        }
 
       return(potential);
       time_stamp();
       trace(func_name,action_end);
}
