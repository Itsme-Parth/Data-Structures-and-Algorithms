class Solution
{
public:
    vector<vector<int>> ans;
    void perm(vector<int> &nums, int i)
    {
        if (i == nums.size())
        {
            ans.push_back(nums);
            return;
        }
        for (int j = i; j < nums.size(); j++)
        {
            swap(nums[i], nums[j]);
            perm(nums, i + 1);
            swap(nums[i], nums[j]);
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        perm(nums, 0);
        return ans;
    }
};

/* ---- reset ---- */

body
{
margin:
    0;
font:
    normal 75 % source sans pro, sans - serif;
}

canvas
{
display:
    block;
    vertical - align : bottom;
}
/* ---- particles.js container ---- */

#particles - js {
position : absolute;
width : 100 % ;
height : 100 % ;
background - color : black;
}

/* Gradient text only on Webkit */
.warning
{
background:
    -webkit - linear - gradient(45deg, #c97874 10 %, #463042 90 %);
    -webkit - background - clip : text;
    -webkit - text - fill - color : transparent;
color:
# 8c5059;
    font - weight : 400;
margin:
    0 auto 6em;
    max - width : 9em;
}

.calculator
{
    font - size : 28px;
margin:
    0 auto;
width:
    10em;
}
.calculator::before, .calculator::after
{
content:
    " ";
display:
    table;
}
.calculator::after
{
clear:
    both;
}

/* Calculator after dividing by zero */
.broken
{
    -webkit - animation : broken 2s;
animation:
    broken 2s;
transform:
    translate3d(0, -2000px, 0);
opacity:
    0;
}

.viewer
{
color:
#c97874;
    float : left;
    line - height : 3em;
    text - align : right;
    text - overflow : ellipsis;
overflow:
    hidden;
width:
    7.5em;
height:
    3em;
}

#customcode button {
border : 0;
background : rgba(42, 50, 113, 0.28);
color : #6cacc5;
cursor : pointer;
float : left;
font : inherit;
margin : 0.25em;
width : 2em;
height : 2em;
transition : all 0.5s;
}
#customcode button : hover {
background : #201e40;
}
#customcode button : focus {
outline : 0;
/* The value fade-ins that appear */
}
#customcode button : focus::after {
- webkit - animation:zoom 1s;
animation : zoom 1s;
- webkit - animation - iteration - count:1;
animation - iteration - count : 1;
- webkit - animation - fill - mode:both;
animation - fill - mode : both;
content : attr(data - num);
cursor : default;
font - size : 100px;
position : absolute;
top : 1.5em;
left : 50 % ;
text - align : center;
margin - left : -24px;
opacity : 0;
width : 48px;
}

/* Same as above, modified for operators */
.ops : focus::after
{
content:
    attr(data - ops);
    margin - left : -210px;
width:
    420px;
}

/* Same as above, modified for result */
.equals : focus::after
{
content:
    attr(data - result);
    margin - left : -300px;
width:
    600px;
}

/* Reset button */
.reset
{
background:
    rgba(201, 120, 116, 0.28);
color:
#c97874;
    font - weight : 400;
    margin - left : -77px;
padding:
    0.5em 1em;
position:
    absolute;
top:
    -20em;
left:
    50 % ;
width:
    auto;
height:
    auto;
    /* When button is revealed */
}
.reset : hover
{
background:
#c97874;
color:
# 100a1c;
}
.reset.show
{
top:
    20em;
    -webkit - animation : fadein 4s;
animation:
    fadein 4s;
}

/* Animations */
/* Values that appear onclick */
@-webkit - keyframes zoom
{
    0 %
    {
    transform:
        scale(0.2);
    opacity:
        1;
    }
    70 %
    {
    transform:
        scale(1);
    }
    100 %
    {
    opacity:
        0;
    }
}
@keyframes zoom
{
    0 %
    {
    transform:
        scale(0.2);
    opacity:
        1;
    }
    70 %
    {
    transform:
        scale(1);
    }
    100 %
    {
    opacity:
        0;
    }
}
/* Division by zero animation */
@-webkit - keyframes broken
{
    0 %
    {
    transform:
        translate3d(0, 0, 0);
    opacity:
        1;
    }
    5 %
    {
    transform:
        rotate(5deg);
    }
    15 %
    {
    transform:
        rotate(-5deg);
    }
    20 %
    {
    transform:
        rotate(5deg);
    }
    25 %
    {
    transform:
        rotate(-5deg);
    }
    50 %
    {
    transform:
        rotate(45deg);
    }
    70 %
    {
    transform:
        translate3d(0, 2000px, 0);
    opacity:
        1;
    }
    75 %
    {
    opacity:
        0;
    }
    100 %
    {
    transform:
        translate3d(0, -2000px, 0);
    }
}
@keyframes broken
{
    0 %
    {
    transform:
        translate3d(0, 0, 0);
    opacity:
        1;
    }
    5 %
    {
    transform:
        rotate(5deg);
    }
    15 %
    {
    transform:
        rotate(-5deg);
    }
    20 %
    {
    transform:
        rotate(5deg);
    }
    25 %
    {
    transform:
        rotate(-5deg);
    }
    50 %
    {
    transform:
        rotate(45deg);
    }
    70 %
    {
    transform:
        translate3d(0, 2000px, 0);
    opacity:
        1;
    }
    75 %
    {
    opacity:
        0;
    }
    100 %
    {
    transform:
        translate3d(0, -2000px, 0);
    }
}
/* Reset button fadein */
@-webkit - keyframes fadein
{
    0 %
    {
    top:
        20em;
    opacity:
        0;
    }
    50 %
    {
    opacity:
        0;
    }
    100 %
    {
    opacity:
        1;
    }
}
@keyframes fadein
{
    0 %
    {
    top:
        20em;
    opacity:
        0;
    }
    50 %
    {
    opacity:
        0;
    }
    100 %
    {
    opacity:
        1;
    }
}
@media(min - width : 420px)
{
    .calculator
    {
    width:
        12em;
    }

    .viewer
    {
    width:
        8.5em;
    }

    button
    {
    margin:
        0.5em;
    }
}