void translate_wall(double wall_particle[44][m_max][z_max])
{
     for(i = 22; i < 44; i++)
      {
       wall_particle[i][3][0] = ((wall_particle[i][3][0]) - wall_step);
      }
}
