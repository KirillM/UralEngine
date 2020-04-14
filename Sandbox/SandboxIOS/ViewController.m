//
//  ViewController.m
//  SandboxIOS
//
//  Created by Кирилл Мезрин on 13.04.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#import "ViewController.h"
//#import <OpenGLES/ES3/gl.h>

#include "Sandbox.mm"

#define GLES_SILENCE_DEPRECATION

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    GLKView *view = (GLKView *)self.view;
    view.context = [[EAGLContext alloc] initWithAPI:kEAGLRenderingAPIOpenGLES3];
    view.drawableDepthFormat = GLKViewDrawableDepthFormat16;
    [EAGLContext setCurrentContext:view.context];
}

- (void)glkView:(GLKView *)view drawInRect:(CGRect)rect {
//    glClearColor(0.0, 104.0/255.0, 55.0/255.0, 1.0);
//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//    glEnable(GL_DEPTH_TEST);
//    glEnable(GL_CULL_FACE);
//    glEnable(GL_BLEND);
//    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
//    GLKMatrix4 viewMatrix = GLKMatrix4MakeTranslation(0.0, 0.0, -5.0);
//   // viewMatrix = GLKMatrix4Rotate(viewMatrix, GLKMathDegreesToRadians(20.0), 1.0, 0.0, 0.0);
//    viewMatrix = GLKMatrix4Identity;
//  //  [_square renderWithParentModelViewMatrix:viewMatrix];
//   // [_cube renderWithParentModelViewMatrix:viewMatrix];
//    [_scene renderWithParentModelViewMatrix:viewMatrix];
//    uint32_t error = glGetError();
}

- (void)update {
  //  [_square updateWithDelta:self.timeSinceLastUpdate];
  // [_cube updateWithDelta:self.timeSinceLastUpdate];
  //  [_scene updateWithDelta:self.timeSinceLastUpdate];
}

@end
