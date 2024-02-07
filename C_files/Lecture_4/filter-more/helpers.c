#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int average = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);
            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE temp;
            temp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE store[height][width];
    // TODO
    // MOVE OVER EACH PIXEL
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // DEFINE VARIABLES
            float red = 0;
            float green = 0;
            float blue = 0;
            float numberofpixels = 0;

            // MOVE AROUND AND ON THE PARTICULAR PIXEL
            for (int l = (i - 1); l <= (i + 1); l++)
            {
                for (int m = (j - 1); m <= (j + 1); m++)
                {
                    // CHECK FOR OUT OF BOUNDS
                    if (l >= height || m >= width || l < 0 || m < 0)
                    {
                        continue;
                    }
                    // UPDATE VALUES IF INSIDE BOUNDS
                    else
                    {
                        red = red + image[l][m].rgbtRed;
                        green = green + image[l][m].rgbtGreen;
                        blue = blue + image[l][m].rgbtBlue;
                    }
                    numberofpixels++;
                }
            }

            // STORE THE VALUES IN THE NEW STRUCT
            store[i][j].rgbtRed = round(red / numberofpixels);
            store[i][j].rgbtGreen = round(green / numberofpixels);
            store[i][j].rgbtBlue = round(blue / numberofpixels);
        }
    }

    // PUT THE VALUES IN THEIR RESPECTIVE PIXELS
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtBlue = store[i][j].rgbtBlue;
            image[i][j].rgbtGreen = store[i][j].rgbtGreen;
            image[i][j].rgbtRed = store[i][j].rgbtRed;
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE store[height][width];

    int gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int gxBlue = 0;
            int gyBlue = 0;
            int gxGreen = 0;
            int gyGreen = 0;
            int gxRed = 0;
            int gyRed = 0;

            for (int r = -1; r < 2; r++)
            {
                for (int c = -1; c < 2; c++)
                {
                    if (i + r < 0 || i + r > height - 1)
                    {
                        continue;
                    }
                    if (j + c < 0 || j + c > width - 1)
                    {
                        continue;
                    }

                    gxBlue += image[i + r][j + c].rgbtBlue * gx[r + 1][c + 1];
                    gyBlue += image[i + r][j + c].rgbtBlue * gy[r + 1][c + 1];
                    gxGreen += image[i + r][j + c].rgbtGreen * gx[r + 1][c + 1];
                    gyGreen += image[i + r][j + c].rgbtGreen * gy[r + 1][c + 1];
                    gxRed += image[i + r][j + c].rgbtRed * gx[r + 1][c + 1];
                    gyRed += image[i + r][j + c].rgbtRed * gy[r + 1][c + 1];
                }
            }

            int blue = round(sqrt(gxBlue * gxBlue + gyBlue * gyBlue));
            int green = round(sqrt(gxGreen * gxGreen + gyGreen * gyGreen));
            int red = round(sqrt(gxRed * gxRed + gyRed * gyRed));

            store[i][j].rgbtBlue = (blue > 255) ? 255 : blue;
            store[i][j].rgbtGreen = (green > 255) ? 255 : green;
            store[i][j].rgbtRed = (red > 255) ? 255 : red;
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtBlue = store[i][j].rgbtBlue;
            image[i][j].rgbtGreen = store[i][j].rgbtGreen;
            image[i][j].rgbtRed = store[i][j].rgbtRed;
        }
    }
    return;
}
